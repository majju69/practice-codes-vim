#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,ans=0,mn=1e18;
		cin>>n;
		vector<pair<ll,ll>> a(n);
		for(auto &v:a)
		{
			cin>>v.first>>v.second;
		}
		for(ll i=0;i<n;++i)
		{
			ll req=max(0LL,a[i].first-a[(i-1+n)%n].second);
			ans+=req;
			a[i].first-=req;
		}
		for(auto &v:a)
		{
			mn=min(mn,v.first);
		}
		cout<<ans+mn<<'\n';
	}
	return 0;
}
