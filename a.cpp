#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

vector<long long> lpf(1000001,0);
vector<long long> primes;

void leastPrimeFactor()
{
    long long n=lpf.size();
    for(long long i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
        }
        for(long long j=0;i*primes[j]<n;++j)
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
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,q,mx=0,even=0,odd=0;
		map<ll,ll> mp;
		cin>>n;
		for(ll i=0;i<n;++i)
		{
			ll x,real_x=1;
			map<ll,ll> tmp;
			cin>>x;
			while(x>1)
			{
				tmp[lpf[x]]++;
				x/=lpf[x];
			}
			for(auto &v:tmp)
			{
				if(v.second&1)
				{
					real_x*=v.first;
				}
			}
			mp[real_x]++;
			mx=max(mx,mp[real_x]);
		}
		for(auto &v:mp)
		{
			if(v.first>1)
			{
				if(v.second&1)
				{
					odd=max(odd,v.second);
					continue;
				}
				even+=v.second;
			}
			else
			{
				even+=v.second;
			}
		}
		cin>>q;
		while(q--)
		{
			ll x;
			cin>>x;
			cout<<((x==0)?mx:max(even,odd))<<'\n';
		}
	}
	return 0;
}
