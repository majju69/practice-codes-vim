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
	ll n,k,cur=1,ans=0;
	set<ll> vis;
	map<ll,vector<ll>> mp;
	cin>>n>>k;
	vector<ll> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	mp[a[0]].push_back(0);
	for(ll i=1;i<n;++i)
	{
		a[i]+=a[i-1];
		mp[a[i]].push_back(i);
	}
	while(1)
	{
		if(abs(cur)>1e14||vis.count(cur))
		{
			break;
		}
		for(ll i=0;i<n;++i)
		{
			// a[r]-a[l-1]=cur => a[r]=cur+a[l-1]
			ll req=cur+((i==0)?0:a[i-1]);
			if(mp.count(req))
			{
				vector<ll> &vec=mp[req];
				ans+=upper_bound(vec.begin(),vec.end(),n)-lower_bound(vec.begin(),vec.end(),i);
			}
		}
		vis.insert(cur);
		cur*=k;
	}
	cout<<ans<<'\n';
	return 0;
}
