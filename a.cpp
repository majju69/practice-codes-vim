#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<int> lpf(10000001,0);
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
		int n,k,ans=1;
		map<int,bool> present;
		cin>>n>>k;
		for(int i=0;i<n;++i)
		{
			int x,cur=1,cur_p=-1,cnt=0;
			cin>>x;
			cur_p=lpf[x];
			while(x>1)
			{
				if(lpf[x]==cur_p)
				{
					cnt++;
					x/=lpf[x];
				}
				else
				{
					if(cnt&1)
					{
						cur*=cur_p;
					}
					cnt=1;
					cur_p=lpf[x];
					x/=lpf[x];
				}
			}
			if(cnt&1)
			{
				cur*=cur_p;
			}
			if(present[cur])
			{
				ans++;
				present.clear();
				present[cur]=1;
			}
			else
			{
				present[cur]=1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
