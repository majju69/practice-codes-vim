#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void bfs(vector<int> &src,vector<int> &dist,vector<int> adj[])
{
	queue<pair<int,int>> q;
	for(auto &v:src)
	{
		dist[v]=0;
		q.push({v,0});
	}
	while(q.size())
	{
		int node=q.front().first,dis=q.front().second;
		q.pop();
		for(auto &v:adj[node])
		{
			if(dist[v]>1+dis)
			{
				dist[v]=1+dis;
				q.push({v,1+dis});
			}
		}
	}
}

void dfs(int node,int dest,int p,vector<int> adj[],vector<int> &path)
{
	path.push_back(node);
	if(path.back()==dest)
	{
		return;
	}
	for(auto &v:adj[node])
	{
		if(v!=p)
		{
			dfs(v,dest,node,adj,path);
		}
	}
	if(path.back()!=dest)
	{
		path.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,node1=0,node2=0,node3=-1;
	cin>>n;
	vector<int> *adj=new vector<int>[n],src={0},dist1(n,1e9),dist2(n,1e9),dist3(n,1e9),path;
	for(int i=1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(src,dist1,adj);
	for(int i=0;i<n;++i)
	{
		if(dist1[i]>dist1[node1])
		{
			node1=i;
		}
	}
	src={node1};
	bfs(src,dist2,adj);
	for(int i=0;i<n;++i)
	{
		if(dist2[i]>dist2[node2])
		{
			node2=i;
		}
	}
	dfs(node1,node2,-1,adj,path);
	src.clear();
	for(auto &v:path)
	{
		if(v!=node1&&v!=node2)
		{
			src.push_back(v);
		}
	}
	bfs(src,dist3,adj);
	for(int i=0;i<n;++i)
	{
		if(i!=node1&&i!=node2)
		{
			if(node3==-1)
			{
				node3=i;
			}
			else
			{
				if(dist3[node3]<dist3[i])
				{
					node3=i;
				}
			}
		}
	}
	cout<<dist2[node2]+dist3[node3]<<'\n';
	cout<<node1+1<<' '<<node2+1<<' '<<node3+1<<'\n';
	return 0;
}
