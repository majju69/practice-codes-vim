#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void dfs(int node,int c,vector<int> adj[],vector<int> &col)
{
	col[node]=c;
	for(auto &v:adj[node])
	{
		if(col[v]==-1)
		{
			dfs(v,1-c,adj,col);
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
		int n;
		cin>>n;
		vector<int> adj[n],col(n,-1);
		for(int i=1;i<n;++i)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0,0,adj,col);
		for(int i=0;i<n;++i)
		{
			int d=adj[i].size();
			if(col[i])
			{
				cout<<d<<' ';
			}
			else
			{
				cout<<-d<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}
