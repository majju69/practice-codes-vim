#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void dfs(int node,int p,int total,int mid,int &cnt,int &sum,vector<int> adj[],vector<int> &sub)
{
	sub[node]=1;
	for(auto &v:adj[node])
	{
		if(v!=p)
		{
			dfs(v,node,total,mid,cnt,sum,adj,sub);
			sub[node]+=sub[v];
		}
	}
	if(sub[node]>=mid)
	{
		if(total-sum-sub[node]>=mid)
		{
			sum+=sub[node];
			cnt++;
			sub[node]=0;
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
		int n,k,lo=1,hi=0,ans=-1;
		cin>>n>>k;
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
		hi=n;
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2,total=n,cnt=0,sum=0;
			vector<int> sub(n,0);
			dfs(0,0,total,mid,cnt,sum,adj,sub);
			if(cnt>=k)
			{
				ans=mid;
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
