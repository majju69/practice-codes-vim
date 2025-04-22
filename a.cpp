#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll N=2e5,LOG=19;
ll up[N][LOG],up_max[N][LOG],depth[N];

void dfs(ll node,ll p,vector<pair<ll,ll>> adj[])
{
	for(auto &v:adj[node])
	{
		if(v.first!=p)
		{
			depth[v.first]=depth[node]+1;
			up[v.first][0]=node;
			up_max[v.first][0]=v.second;
			for(ll j=1;j<LOG;++j)
			{
				up_max[v.first][j]=max(up_max[v.first][j-1],up_max[up[v.first][j-1]][j-1]);
				up[v.first][j]=up[up[v.first][j-1]][j-1];
			}
			dfs(v.first,node,adj);
		}
	}
}

ll pathMax(ll u,ll v)
{
	if(depth[u]<depth[v])
	{
		swap(u,v);
	}
	ll k=depth[u]-depth[v],mx=-1e18;
	for(ll j=LOG-1;j>=0;--j)
	{
		if(k>>j&1)
		{
			mx=max(mx,up_max[u][j]);
			u=up[u][j];
		}
	}
	if(u==v)
	{
		return mx;
	}
	for(ll j=LOG-1;j>=0;--j)
	{
		if(up[u][j]!=up[v][j])
		{
			mx=max(mx,up_max[u][j]);
			mx=max(mx,up_max[v][j]);
			u=up[u][j];
			v=up[v][j];
		}
	}
	return max({mx,up_max[u][0],up_max[v][0]});
}

class DisjointSet
{

private:
	
	vector<long long> ultimateParent,rank,size;

public:
	
	DisjointSet(long long n)
	{
		ultimateParent.resize(n+1);
		rank.resize(n+1,0);
		size.resize(n+1,1);
		for(long long i=0;i<=n;++i)
		{
			ultimateParent[i]=i;
		}
	}

	long long findUltimateParent(long long node)
	{
		if(ultimateParent[node]==node)
		{
			return node;
		}
		return ultimateParent[node]=findUltimateParent(ultimateParent[node]);
	}

	long long getSize(long long node)
	{
		return size[node];
	}

	long long getRank(long long node)
	{
		return rank[node];
	}

	void unionByRank(long long u,long long v)
	{
		long long ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
		if(ultimateParentOfU==ultimateParentOfV)
		{
			return;
		}
		if(rank[ultimateParentOfU]<rank[ultimateParentOfV])
		{
			ultimateParent[ultimateParentOfU]=ultimateParentOfV;
		}
		else if(rank[ultimateParentOfU]>rank[ultimateParentOfV])
		{
			ultimateParent[ultimateParentOfV]=ultimateParentOfU;
		}
		else
		{
			ultimateParent[ultimateParentOfV]=ultimateParentOfU;
			rank[ultimateParentOfU]++;
		}
	}

	void unionBySize(long long u,long long v)
	{
		long long ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
		if(ultimateParentOfU==ultimateParentOfV)
		{
			return;
		}
		if(size[ultimateParentOfU]<size[ultimateParentOfV])
		{
			ultimateParent[ultimateParentOfU]=ultimateParentOfV;
			size[ultimateParentOfV]+=size[ultimateParentOfU];
		}
		else
		{
			ultimateParent[ultimateParentOfV]=ultimateParentOfU;
			size[ultimateParentOfU]+=size[ultimateParentOfV];
		}
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,ans=0;
	cin>>n>>m;
	DisjointSet ds(n);
	vector<pair<ll,ll>> adj[n];
	vector<pair<ll,pair<ll,ll>>> edges(m),sortedEdges(m);
	for(auto &edge:edges)
	{
		cin>>edge.second.first>>edge.second.second>>edge.first;
		edge.second.first--;
		edge.second.second--;
	}
	sortedEdges=edges;
	sort(sortedEdges.begin(),sortedEdges.end());
	for(auto &edge:sortedEdges)
	{
		if(ds.findUltimateParent(edge.second.first)!=ds.findUltimateParent(edge.second.second))
		{
			ans+=edge.first;
			adj[edge.second.first].push_back({edge.second.second,edge.first});
			adj[edge.second.second].push_back({edge.second.first,edge.first});
			ds.unionByRank(edge.second.first,edge.second.second);
		}
	}
	dfs(0,0,adj);
	for(auto &edge:edges)
	{
		cout<<ans+edge.first-pathMax(edge.second.first,edge.second.second)<<'\n';
	}
	return 0;
}
