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
	int n,m,t,cur_node=-1,cur_cnt=-1;
	queue<int> q;
	cin>>n>>m>>t;
	vector<int> indegree(n,0),topoSort,ans;
	vector<pair<int,int>> adj[n];
	vector<vector<int>> dp(n,vector<int>(n,1e9+10));
	vector<vector<int>> par(n,vector<int>(n,-1));
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		adj[u].push_back({v,w});
		indegree[v]++;
	}
	for(int i=0;i<n;++i)
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
		topoSort.push_back(node);
		for(auto &v:adj[node])
		{
			indegree[v.first]--;
			if(indegree[v.first]==0)
			{
				q.push(v.first);
			}
		}
	}
	dp[0][0]=0;
	for(auto &node:topoSort)
	{
		for(auto &v:adj[node])
		{
			for(int i=1;i<n;++i)
			{
				if(dp[node][i-1]+v.second>t)
				{
					continue;
				}
				if(dp[v.first][i]>dp[node][i-1]+v.second)
				{
					dp[v.first][i]=dp[node][i-1]+v.second;
					par[v.first][i]=node;
				}
			}
		}
	}
	for(int i=n-1;i>=0;--i)
	{
		if(dp[n-1][i]<=t)
		{
			cur_cnt=i;
			break;
		}
	}
	cur_node=n-1;
	while(cur_node!=-1)
	{
		ans.push_back(cur_node+1);
		cur_node=par[cur_node][cur_cnt];
		cur_cnt--;
	}
	reverse(ans.begin(),ans.end());
	cout<<(int)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}

