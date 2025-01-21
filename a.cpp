#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

void dfs(ll node,vector<bool> &vis,vector<ll> adj[],stack<ll> &st)
{
	vis[node]=1;
	for(auto &v:adj[node])
	{
		if(!vis[v])
		{
			dfs(v,vis,adj,st);
		}
	}
	st.push(node);
}

void dfs(ll node,ll c,vector<ll> &comp,vector<ll> adjT[],ll &coins,vector<ll> &a)
{
	comp[node]=c;
	coins+=a[node];
	for(auto &v:adjT[node])
	{
		if(comp[v]==-1)
		{
			dfs(v,c,comp,adjT,coins,a);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,cnt=0;
	stack<ll> st;
	cin>>n>>m;
	vector<ll> a(n),coin_cnt,comp(n,-1),adj[n],adjT[n];
	vector<bool> vis(n,0);
	for(auto &v:a)
	{
		cin>>v;
	}
	for(ll i=0;i<m;++i)
	{
		ll u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adjT[v].push_back(u);
	}
	for(ll i=0;i<n;++i)
	{
		if(!vis[i])
		{
			dfs(i,vis,adj,st);
		}
	}
	while(st.size())
	{
		ll node=st.top();
		st.pop();
		if(comp[node]==-1)
		{
			ll coins=0;
			dfs(node,cnt++,comp,adjT,coins,a);
			coin_cnt.push_back(coins);
		}
	}
	queue<ll> q;
	vector<ll> adj_red[cnt],indegree(cnt,0),dp(cnt,0),toposort;
	for(ll i=0;i<n;++i)
	{
		for(auto &node:adj[i])
		{
			ll u=comp[i],v=comp[node];
			if(u!=v)
			{
				adj_red[u].push_back(v);
				indegree[v]++;
			}
		}
	}
	for(ll i=0;i<cnt;++i)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(q.size())
	{
		ll node=q.front();
		toposort.push_back(node);
		q.pop();
		for(auto &v:adj_red[node])
		{
			indegree[v]--;
			if(indegree[v]==0)
			{
				q.push(v);
			}
		}
	}
	for(auto &node:toposort)
	{
		dp[node]=max(dp[node],coin_cnt[node]);
		for(auto &v:adj_red[node])
		{
			dp[v]=max(dp[v],dp[node]+coin_cnt[v]);
		}
	}
	cout<<*max_element(dp.begin(),dp.end())<<'\n';
	return 0;
}
