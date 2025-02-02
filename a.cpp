#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int get(int u,int v,int n)
{
	return u*n+v;
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
		int n,s1,s2,m1,m2,ans=2e9;
		set<pair<int,int>> st;
		vector<pair<int,int>> edges1,edges2,common;
		cin>>n>>s1>>s2;
		s1--;
		s2--;
		vector<pair<int,int>> adj[n*n];
		vector<int> dist(n*n,2e9);
		vector<bool> present(n*n,0);
		cin>>m1;
		for(int i=0;i<m1;++i)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			if(u>v)
			{
				swap(u,v);
			}
			edges1.push_back({u,v});
			present[get(u,v,n)]=1;
		}
		cin>>m2;
		for(int i=0;i<m2;++i)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			if(u>v)
			{
				swap(u,v);
			}
			edges2.push_back({u,v});
			if(present[get(u,v,n)])
			{
				common.push_back({u,v});
			}
		}
		for(auto &edge1:edges1)
		{
			for(auto &edge2:edges2)
			{
				int u1=edge1.first,u2=edge1.second,v1=edge2.first,v2=edge2.second;
				adj[get(u1,v1,n)].push_back({get(u2,v2,n),abs(u2-v2)});
				adj[get(u2,v2,n)].push_back({get(u1,v1,n),abs(u1-v1)});
				adj[get(u1,v2,n)].push_back({get(u2,v1,n),abs(u2-v1)});
				adj[get(u2,v1,n)].push_back({get(u1,v2,n),abs(u1-v2)});
			}
		}
		dist[get(s1,s2,n)]=0;
		st.insert({0,get(s1,s2,n)});
		while(st.size())
		{
			auto it=st.begin();
			int node=it->second,dis=it->first;
			st.erase(*it);
			for(auto &v:adj[node])
			{
				int curNode=v.first,curDist=v.second;
				if(dist[curNode]>dis+curDist)
				{
					if(dist[curNode]!=2e9)
					{
						st.erase({dist[curNode],curNode});
					}
					dist[curNode]=dis+curDist;
					st.insert({dist[curNode],curNode});
				}
			}
		}
		for(auto &edge:common)
		{
			int u=edge.first,v=edge.second;
			ans=min(ans,dist[get(u,u,n)]);
			ans=min(ans,dist[get(v,v,n)]);
		}
		if(ans==2e9)
		{
			ans=-1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
