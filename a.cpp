#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void dfs(int node,int p,vector<int> adj[],vector<int> &depth)
{
	for(auto &v:adj[node])
	{
		if(v!=p)
		{
			depth[v]=depth[node]+1;
			dfs(v,node,adj,depth);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k,node0=-1,node1=-1,mn=1e9;
		cin>>n>>k;
		vector<bool> marked(n,0);
		vector<int> adj[n],depth0(n,0),depth1(n,0);
		while(k--)
		{
			int x;
			cin>>x;
			x--;
			marked[x]=1;
			node0=x;
		}
		for(int i=1;i<n;++i)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(node0,-1,adj,depth0);
		for(int i=0;i<n;++i)
		{
			if(marked[i])
			{
				if(node1==-1||depth0[node1]<depth0[i])
				{
					node1=i;
				}
			}
		}
		dfs(node1,-1,adj,depth1);
		node0=-1;
		for(int i=0;i<n;++i)
		{
			if(marked[i])
			{
				if(node0==-1||depth1[node0]<depth1[i])
				{
					node0=i;
				}
			}
		}
		depth0.assign(n,0);
		depth1.assign(n,0);
		if(node0!=-1)
		{
			dfs(node0,-1,adj,depth0);
		}
		if(node1!=-1)
		{
			dfs(node1,-1,adj,depth1);
		}
		for(int i=0;i<n;++i)
		{
			mn=min(mn,max(depth0[i],depth1[i]));
		}
		cout<<mn<<'\n';
	}
	return 0;
}
