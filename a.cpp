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
	ll n,m;
	set<pair<ll,ll>> st;
	cin>>n>>m;
	vector<pair<ll,ll>> adj[n];
	vector<ll> a(n),dist(n,1e18);
	for(ll i=0;i<m;++i)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		w<<=1;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(auto &v:a)
	{
		cin>>v;
	}
	for(ll i=0;i<n;++i)
	{
		dist[i]=a[i];
		st.insert({a[i],i});
	}
	while(st.size())
	{
		auto it=st.begin();
		ll node=it->second,dis=it->first;
		st.erase(*it);
		for(auto &v:adj[node])
		{
			ll curNode=v.first,curDist=v.second;
			if(dist[curNode]>dis+curDist)
			{
				st.erase({dist[curNode],curNode});
				dist[curNode]=dis+curDist;
				st.insert({dist[curNode],curNode});
			}
		}
	}
	for(auto &v:dist)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
