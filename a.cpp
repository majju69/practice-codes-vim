#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void dfs(int node,vector<bool> &vis,vector<int> adj[],stack<int> &st)
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

void dfs(int node,vector<bool> &vis,vector<int> adjT[],vector<int> &a)
{
	vis[node]=1;
	a.push_back(node);
	for(auto &v:adjT[node])
	{
		if(!vis[v])
		{
			dfs(v,vis,adjT,a);
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
		int n,m;
		stack<int> st;
		vector<vector<int>> comp;
		cin>>n>>m;
		vector<int> adj[n],adjT[n],idx(n,-1);
		vector<bool> vis(n,0),isSelf(n,0);
		for(int i=0;i<m;++i)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			if(u==v)
			{
				isSelf[u]=1;
				continue;
			}
			adj[u].push_back(v);
			adjT[v].push_back(u);
		}
		for(int i=0;i<n;++i)
		{
			if(!vis[i])
			{
				dfs(i,vis,adj,st);
			}
		}
		for(int i=0;i<n;++i)
		{
			vis[i]=0;
		}
		while(st.size())
		{
			int node=st.top();
			st.pop();
			if(!vis[node])
			{
				vector<int> tmp;
				dfs(node,vis,adjT,tmp);
				comp.push_back(tmp);
			}
		}
		int len=comp.size();
		queue<int> q;
		vector<int> _adj[len],ways(len,0),indegree(len,0),topo;
		vector<bool> self(len,0);
		for(int i=0;i<len;++i)
		{
			for(auto &v:comp[i])
			{
				idx[v]=i;
			}
		}
		for(int i=0;i<n;++i)
		{
			if(isSelf[i])
			{
				self[idx[i]]=1;
			}
			for(auto &v:adj[i])
			{
				if(idx[v]==idx[i])
				{
					self[idx[i]]=1;
				}
				else
				{
					_adj[idx[i]].push_back(idx[v]);
					indegree[idx[v]]++;
				}
			}
		}
		for(int i=0;i<len;++i)
		{
			if(indegree[i]==0)
			{
				q.push(i);
			}
		}
		while(q.size())
		{
			int node=q.front();
			q.pop();
			topo.push_back(node);
			for(auto &v:_adj[node])
			{
				indegree[v]--;
				if(indegree[v]==0)
				{
					q.push(v);
				}
			}
		}
		for(auto &v:topo)
		{
			if(v==idx[0])
			{
				ways[v]=1;
			}
			if(self[v]&&ways[v]!=0)
			{
				ways[v]=-1;
			}
			for(auto &_v:_adj[v])
			{
				if(ways[v]==-1||ways[_v]==-1)
				{
					ways[_v]=-1;
					continue;
				}
				ways[_v]+=ways[v];
				ways[_v]=min(ways[_v],2);
			}
		}
		for(int i=0;i<n;++i)
		{
			cout<<ways[idx[i]]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
