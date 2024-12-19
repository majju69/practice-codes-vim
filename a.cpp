#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<int> spf(400001,0);

void smallestPrimeFactor()
{
    int n=spf.size();
    for(int i=1;i<n;++i)
    {
        spf[i]=i;
    }
    for(int i=4;i<n;i+=2)
    {
        spf[i]=2;
    }
    for(int i=3;i*i<n;++i)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<n;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	smallestPrimeFactor();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		set<int> primes;
		cin>>n;
		vector<int> a(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		for(auto &v:a)
		{
			if(spf[v]==v)
			{
				primes.insert(v);
			}
			if((int)primes.size()>=2)
			{
				break;
			}
		}
		if((int)primes.size()>=2)
		{
			cout<<-1<<'\n';
		}
		else if((int)primes.size()==1)
		{
			int p=*primes.begin();
			bool ok=1;
			for(auto &v:a)
			{
				if(v<p)
				{
					ok=0;
					break;
				}
				if(v>p&&v<2*p)
				{
					ok=0;
					break;
				}
				if(v==p)
				{
					continue;
				}
				if(v%2==0)
				{
					continue;
				}
				if(v-spf[v]<2*p)
				{
					ok=0;
					break;
				}
			}
			cout<<(ok?p:-1)<<'\n';
		}
		else
		{
			cout<<2<<'\n';
		}
	}
	return 0;
}
