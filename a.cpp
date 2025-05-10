#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<int> lpf(20000001,0);
vector<int> primes;

void leastPrimeFactor()
{
    int n=lpf.size();
    for(int i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
        }
        for(int j=0;i*primes[j]<n;++j)
        {
            lpf[i*primes[j]]=primes[j];
            if(primes[j]==lpf[i])
            {
                break;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	leastPrimeFactor();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int c,d,x;
		long long ans=0;
		cin>>c>>d>>x;
		for(int i=1;i*i<=x;++i)
		{
			if(x%i==0)
			{
				int div=x/i;
				if((div+d)%c==0)
				{
					int num=(d+div)/c,cur=1;
					while(num>1)
					{
						int cur_prime=lpf[num];
						cur*=2;
						while(num%cur_prime==0)
						{
							num/=cur_prime;
						}
					}
					ans+=1ll*cur;
				}
				if(i*i!=x)
				{
					div=i;
					if((div+d)%c==0)
					{
						int num=(d+div)/c,cur=1;
						while(num>1)
						{
							int cur_prime=lpf[num];
							cur*=2;
							while(num%cur_prime==0)
							{
								num/=cur_prime;
							}
						}
						ans+=1ll*cur;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}	
