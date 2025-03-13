#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N=1e5,LOG=18;
int up[N][LOG],depth[N];

void dfs(int node,int p,vector<int> adj[])
{
	for(auto &v:adj[node])
	{
		if(v!=p)
		{
			depth[v]=depth[node]+1;
			up[v][0]=node;
			for(int j=1;j<LOG;++j)
			{
				up[v][j]=up[up[v][j-1]][j-1];
			}
			dfs(v,node,adj);
		}
	}
}

int lowestCommonAncestor(int u,int v)
{
	if(depth[u]<depth[v])
	{
		swap(u,v);
	}
	int k=depth[u]-depth[v];
	for(int j=LOG-1;j>=0;--j)
	{
		if(k>>j&1)
		{
			u=up[u][j];
		}
	}
	if(u==v)
	{
		return u;
	}
	for(int j=LOG-1;j>=0;--j)
	{
		if(up[u][j]!=up[v][j])
		{
			u=up[u][j];
			v=up[v][j];
		}
	}
	return up[u][0];
}

inline int dist(int u,int v)
{
	return depth[u]+depth[v]-(depth[lowestCommonAncestor(u,v)]<<1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n;
	vector<int> adj[n];
	for(int i=1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,0,adj);
	cin>>q;
	while(q--)
	{
		int x,y,u,v,k;
		cin>>x>>y>>u>>v>>k;
		x--;
		y--;
		u--;
		v--;
		int d1=k-dist(u,v),d2=k-(dist(u,x)+dist(y,v)+1),d3=k-(dist(u,y)+dist(x,v)+1);
		cout<<(((d1>=0&&d1%2==0)||(d2>=0&&d2%2==0)||(d3>=0&&d3%2==0))?"YES":"NO")<<'\n';
	}
	return 0;
}
