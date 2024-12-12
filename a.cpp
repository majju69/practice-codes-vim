#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void dfs(int node,vector<bool> &vis,vector<int> adj[],vector<int> &vis_pos,vector<int> &a,vector<int> &vis_elements)
{
	vis[node]=1;
	vis_elements.push_back(a[node]);
	vis_pos.push_back(node);
	for(auto &v:adj[node])
	{
		if(!vis[v])
		{
			dfs(v,vis,adj,vis_pos,a,vis_elements);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<int> a(n),adj[n];
	vector<bool> vis(n,0);
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		a[i]--;
	}
	for(int i=0;i<m;++i)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<n;++i)
	{
		if(!vis[i])
		{
			int len=0;
			vector<int> vis_pos,vis_elements;
			dfs(i,vis,adj,vis_pos,a,vis_elements);
			len=vis_pos.size();
			sort(vis_elements.rbegin(),vis_elements.rend());
			sort(vis_pos.begin(),vis_pos.end());
			for(int j=0;j<len;++j)
			{
				a[vis_pos[j]]=vis_elements[j];
			}
		}
	}
	for(auto &v:a)
	{
		cout<<v+1<<' ';
	}
	cout<<'\n';
	return 0;
}
