#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll gcd(ll a,ll b)
{
	return ((b==0)?a:gcd(b,a%b));
}

vector<long long> lpf(200001,0);
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
	ll n,cnt1=0,g=0;
	map<ll,map<ll,ll>> mp;
	cin>>n;
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		if(x==1)
		{
			cnt1++;
			continue;
		}
		g=gcd(g,x);
		while(x>1)
		{
			ll cur_prime=lpf[x],cnt=0;
			while(x%cur_prime==0)
			{
				cnt++;
				x/=cur_prime;
			}
			mp[cur_prime][cnt]++;
		}
	}
	if(cnt1>=2)
	{
		cout<<1<<'\n';
	}
	else if(cnt1==1)
	{
		cout<<g<<'\n';
	}
	else
	{
		ll ans=1;
		for(auto &v:mp)
		{
			ll tot_cnt=0;
			for(auto &v1:v.second)
			{
				tot_cnt+=v1.second;
			}
			if(n-tot_cnt>=2)
			{
				continue;
			}
			else if(n-tot_cnt==1)
			{
				auto it=v.second.begin();
				ll cur_cnt=it->first;
				while(cur_cnt--)
				{
					ans*=v.first;
				}
			}
			else
			{
				auto it=v.second.begin();
				ll cur_cnt=it->second,cur_mn=it->first;
				if(cur_cnt>1)
				{
					while(cur_mn--)
					{
						ans*=v.first;
					}
				}
				else
				{
					ll cur_mn_sec=1e18;
					for(auto &v1:v.second)
					{
						if(v1.first!=cur_mn)
						{
							cur_mn_sec=v1.first;
							break;
						}
					}
					while(cur_mn_sec--)
					{
						ans*=v.first;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
