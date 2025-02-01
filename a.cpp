#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

void dfs(ll node,ll p,vector<pair<ll,ll>> adj[],vector<ll> &depth)
{
	for(auto &v:adj[node])
	{
		if(v.first!=p)
		{
			depth[v.first]=depth[node]+v.second;
			dfs(v.first,node,adj,depth);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,ans=0;
	cin>>n;
	vector<pair<ll,ll>> adj[n];
	vector<ll> depth(n,0);
	for(ll i=1;i<n;++i)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		ans+=2*w;
	}
	dfs(0,0,adj,depth);
	cout<<ans-*max_element(depth.begin(),depth.end())<<'\n';
	return 0;
}
