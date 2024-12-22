#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

void dijkstra(ll src,vector<pair<ll,ll>> adj[],vector<ll> &dist,vector<pair<ll,bool>> &par)
{
	set<pair<ll,ll>> st;
	dist[src]=0;
	st.insert({0,src});
	while(st.size())
	{
		auto it=st.begin();
		ll node=it->second,dis=it->first;
		st.erase(*it);
		for(auto &v:adj[node])
		{
			ll curNode=v.first,curDist=abs(v.second);
			bool neg=(v.second<0);
			if(dist[curNode]>dis+curDist)
			{
				if(dist[curNode]!=1e18)
				{
					st.erase({dist[curNode],curNode});
				}
				dist[curNode]=dis+curDist;
				st.insert({dist[curNode],curNode});
				par[curNode]={node,neg};
			}
			if(dist[curNode]==dis+curDist)
			{
				if(!neg)
				{
					par[curNode]={node,neg};
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
	ll n,m,k,cnt=0;
	cin>>n>>m>>k;
	vector<pair<ll,ll>> adj[n];
	vector<ll> dist(n,1e18),t_dist(n,1e18);
	vector<pair<ll,bool>> par(n,{-1,0});
	vector<bool> vis(n,0);
	for(ll i=0;i<m;++i)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(ll i=0;i<k;++i)
	{
		ll u,w;
		cin>>u>>w;
		u--;
		t_dist[u]=min(t_dist[u],w);
	}
	dijkstra(0,adj,dist,par);
	for(int i=0;i<n;++i)
	{
		par[i]={-1,0};
		if(t_dist[i]!=1e18)
		{
			adj[0].push_back({i,-t_dist[i]});
			adj[i].push_back({0,-t_dist[i]});
		}
	}
	dijkstra(0,adj,dist,par);
	for(ll i=n-1;i>=0;--i)
	{
		if(!vis[i])
		{
			ll cur=i;
			while(cur!=-1&&!vis[i])
			{
				cnt+=par[cur].second;
				vis[cur]=1;
				cur=par[cur].first;
			}
		}
	}
	cout<<k-cnt<<'\n';
	return 0;
}
