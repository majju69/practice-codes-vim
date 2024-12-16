#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int get(int n)
{
	return ((n*(n-1))>>1);
}

void dfs(int node,vector<bool> &vis,vector<int> adj[],vector<char> &label,char curLabel)
{
	vis[node]=1;
	label[node]=curLabel;
	for(auto &v:adj[node])
	{
		if(!vis[v])
		{
			dfs(v,vis,adj,label,curLabel);
		}
	}
}

bool check(vector<bool> &taken,vector<pair<int,int>> &edges)
{
	int n=taken.size(),len=0;
	char curLabel='0';
	map<int,int> mp;
	for(int i=0;i<n;++i)
	{
		if(taken[i])
		{
			mp[i]=len++;
		}
	}
	vector<int> adj[len];
	vector<bool> vis(len,0);
	vector<char> label(len);
	for(auto &edge:edges)
	{
		int u=edge.first,v=edge.second;
		if(taken[u]&&taken[v])
		{
			adj[mp[u]].push_back(mp[v]);
			adj[mp[v]].push_back(mp[u]);
		}
	}
	for(int i=0;i<len;++i)
	{
		if(!vis[i])
		{
			dfs(i,vis,adj,label,curLabel);
			curLabel++;
		}
	}
	if(curLabel>'2')
	{
		return 0;
	}
	for(int i=0;i<curLabel-'0';++i)
	{
		int nodeCount=0,edgeCount=0;
		for(int u=0;u<len;++u)
		{
			if(label[u]==(char)(i+'0'))
			{
				nodeCount++;
				for(auto &v:adj[u])
				{
					if(label[v]==(char)(i+'0'))
					{
						edgeCount++;
					}
					else
					{
						return 0;
					}
				}
			}
		}
		if(edgeCount&1)
		{
			return 0;
		}
		edgeCount>>=1;
		if(get(nodeCount)!=edgeCount)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	set<pair<int,int>> st;
	cin>>n>>m;
	vector<bool> taken(n,1);
	vector<pair<int,int>> edges(m);
	vector<char> label(n,'#');
	for(auto &edge:edges)
	{
		cin>>edge.first>>edge.second;
		if(edge.first>edge.second)
		{
			swap(edge.first,edge.second);
		}
		edge.first--;
		edge.second--;
		st.insert(edge);
	}
	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(st.count({i,j}))
			{
				continue;
			}
			taken[i]=0;
			taken[j]=0;
		}
	}
	if(check(taken,edges))
	{
		for(int i=0;i<n;++i)
		{
			if(taken[i])
			{
				label[i]='b';
			}
		}
		for(int i=0;i<n;++i)
		{
			taken[i]=!taken[i];
		}
		if(check(taken,edges))
		{
			vector<int> adj[n];
			vector<bool> vis(n,0);
			char curLabel='a';
			for(auto &edge:edges)
			{
				int u=edge.first,v=edge.second;
				if(taken[u]&&taken[v])
				{
					adj[u].push_back(v);
					adj[v].push_back(u);
				}
			}
			for(int i=0;i<n;++i)
			{
				if(!vis[i]&&taken[i])
				{
					dfs(i,vis,adj,label,curLabel);
					curLabel+=2;
				}
			}
			cout<<"Yes\n";
			for(auto &v:label)
			{
				cout<<v;
			}
			cout<<'\n';
		}
		else
		{
			cout<<"No\n";
		}
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}
