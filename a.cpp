#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void dfs(int node,int p,vector<int> adj[],vector<int> &a,vector<int> &sub)
{
	sub[node]=a[node];
	for(auto &v:adj[node])
	{
		if(v!=p)
		{
			dfs(v,node,adj,a,sub);
			sub[node]+=sub[v];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> adj[n],a(n,0),sub(n,0),ans;
	for(int i=1;i<n;++i)
	{
		int u,v,t;
		cin>>u>>v>>t;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		a[u]+=(t==2);
		a[v]+=(t==2);
	}
	dfs(0,0,adj,a,sub);
	for(int i=0;i<n;++i)
	{
		if(sub[i]==1)
		{
			ans.push_back(i+1);
		}
	}
	cout<<(int)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}	
