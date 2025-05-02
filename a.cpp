#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

vector<vector<ll>> divisors(1000001);

void fillDivisors()
{
	ll n=divisors.size();
	for(ll i=2;i<n;i++)
	{
		for(ll j=i;j<n;j+=i)
		{
			divisors[j].push_back(i);
		}
	}
}

inline ll get(ll x)
{
	return x*(x-1)*(x-2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillDivisors();
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,ans=0;
		map<ll,ll> mp;
		cin>>n;
		for(ll i=0;i<n;++i)
		{
			ll x;
			cin>>x;
			mp[x]++;
		}
		for(auto &v:mp)
		{
			ll x=v.first;
			ans+=get(v.second);
			for(auto &d:divisors[x])
			{
				ll y=x/d;
				if(y%d==0&&mp.count(y)&&mp.count(y/d))
				{
					ans+=v.second*mp[y]*mp[y/d];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
