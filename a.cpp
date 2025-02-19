#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

bool check(ll mid,ll k,vector<ll> &a,vector<pair<ll,ll>> &edges)
{
	ll n=0;
	vector<bool> take((ll)a.size(),0);
	vector<ll> new_idx((ll)a.size(),-1);
	for(ll i=0;i<(ll)a.size();++i)
	{
		if(a[i]<=mid)
		{
			take[i]=1;
			new_idx[i]=n++;
		}
	}
	vector<ll> adj[n],indegree(n,0),topoSort;
	queue<ll> q;
	for(auto &edge:edges)
	{
		ll u=edge.first,v=edge.second;
		if(take[u]&&take[v])
		{
			adj[new_idx[u]].push_back(new_idx[v]);
			indegree[new_idx[v]]++;
		}
	}
	for(ll i=0;i<n;++i)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(q.size())
	{
		ll node=q.front();
		q.pop();
		topoSort.push_back(node);
		for(auto &v:adj[node])
		{
			indegree[v]--;
			if(indegree[v]==0)
			{
				q.push(v);
			}
		}
	}
	if((ll)topoSort.size()!=n)
	{
		return 1;
	}
	vector<ll> pathLength(n,-1e18);
	for(auto &v:topoSort)
	{
		if(pathLength[v]<0)
		{
			pathLength[v]=0;
		}
		if(pathLength[v]>=k-1)
		{
			return 1;
		}
		for(auto &node:adj[v])
		{
			pathLength[node]=max(pathLength[node],1+pathLength[v]);
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,k,lo=1e18,hi=-1e18,ans=-1;
	cin>>n>>m>>k;
	vector<ll> a(n);
	vector<pair<ll,ll>> edges(m);
	for(auto &v:a)
	{
		cin>>v;
		lo=min(lo,v);
		hi=max(hi,v);
	}
	for(auto &edge:edges)
	{
		cin>>edge.first>>edge.second;
		edge.first--;
		edge.second--;
	}
	while(lo<=hi)
	{
		ll mid=lo+(hi-lo)/2;
		if(check(mid,k,a,edges))
		{
			ans=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
