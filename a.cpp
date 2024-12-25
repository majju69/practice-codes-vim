#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k,mn=1e9;
	pair<int,int> cur={-1,-1};
	set<pair<int,pair<int,int>>> forbidden;
	queue<pair<int,int>> q;
	cin>>n>>m>>k;
	vector<int> adj[n];
	vector<vector<int>> dist(n,vector<int>(n,1e9));    // {node,par}
	vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(n,{-1,-1}));
	for(int i=0;i<m;++i)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<k;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		a--;
		b--;
		c--;
		forbidden.insert({a,{b,c}});
	}
	dist[0][0]=0;
	q.push({0,0});
	while(q.size())
	{
		int node=q.front().first,p=q.front().second;
		q.pop();
		for(auto &v:adj[node])
		{
			if(forbidden.count({p,{node,v}}))
			{
				continue;
			}
			if(dist[v][node]>1+dist[node][p])
			{
				q.push({v,node});
				dist[v][node]=1+dist[node][p];
				par[v][node]=make_pair(node,p);
			}
		}
	}
	for(int i=0;i<n-1;++i)
	{
		if(cur==make_pair(-1,-1))
		{
			mn=dist[i][n-1];
			cur={i,n-1};
		}
		else
		{
			if(dist[cur.first][cur.second]>dist[i][n-1])
			{
				mn=dist[i][n-1];
				cur={i,n-1};
			}
		}
	}
	if(mn==(int)1e9)
	{
		cout<<-1<<'\n';
	}
	else
	{
		vector<int> ans;
		while(cur!=make_pair(0,0))
		{
			ans.push_back(cur.second);
			ans.push_back(cur.first);
			cur=par[cur.first][cur.second];
		}
		reverse(ans.begin(),ans.end());
		cout<<mn-1<<'\n';
		for(int i=1;i<(int)ans.size();i+=2)
		{
			cout<<ans[i]+1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
