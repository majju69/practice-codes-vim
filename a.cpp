#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline bool isConnected(pair<int,int> a,pair<int,int> b,int mid)
{
    if(a.first>b.first)
    {
        swap(a,b);
    }
    if(a.first==b.first)
    {
        return (abs(a.second-b.second)<=(mid<<1));
    }
    if(a.second==b.second)
    {
        return (abs(a.first-b.first)<=(mid<<1));
    }
    if(b.second<a.second)
    {
        return (a.first+mid>=b.first&&b.second+mid>=a.second);
    }
    return (a.first+mid>=b.first&&a.second+mid>=b.second);
}

void dfs(int node,vector<bool> &vis,vector<int> adj[])
{
	vis[node]=1;
	for(auto &v:adj[node])
	{
		if(!vis[v])
		{
			dfs(v,vis,adj);
		}
	}
}

int check(vector<pair<int,int>> &a,int mid)
{
	int n=a.size(),cnt=0;
	vector<int> adj[n];
	vector<bool> vis(n,0);
	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(isConnected(a[i],a[j],mid))
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		if(!vis[i])
		{
			cnt++;
			if(cnt>=2)
			{
				return 0;
			}
			dfs(i,vis,adj);
		}
	}
	return 1;
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
		int n,lo=0,hi=5e8,ans=5e8;
		cin>>n;
		vector<pair<int,int>> a(n);
		for(auto &v:a)
		{
			cin>>v.first>>v.second;
		}
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2;
			if(check(a,mid))
			{
				ans=mid;
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
