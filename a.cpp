#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

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
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,m,k,ans=0,mn_big=1e18,mx_small=-1e18;
		bool taken=0;
		vector<pair<ll,pair<ll,ll>>> equalEdges,bigEdges,smallEdges;
		cin>>n>>m>>k;
		DisjointSet ds(n);
		for(ll i=0;i<m;++i)
		{
			ll u,v,w;
			cin>>u>>v>>w;
			u--;
			v--;
			if(w<k)
			{
				smallEdges.push_back({w,{u,v}});
			}
			else if(w>k)
			{
				bigEdges.push_back({w,{u,v}});
			}
			else
			{
				equalEdges.push_back({w,{u,v}});
			}
		}
		for(auto &edge:equalEdges)
		{
			ll u=edge.second.first,v=edge.second.second;
			if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
			{
				taken=1;
				ds.unionByRank(u,v);
			}
		}
		sort(smallEdges.rbegin(),smallEdges.rend());
		for(auto &edge:smallEdges)
		{
			ll u=edge.second.first,v=edge.second.second,w=edge.first;
			if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
			{
				mx_small=max(mx_small,w);
				ds.unionByRank(u,v);
			}
		}
		sort(bigEdges.begin(),bigEdges.end());
		for(auto &edge:bigEdges)
		{
			ll u=edge.second.first,v=edge.second.second,w=edge.first;
			if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
			{
				taken=1;
				ans+=(w-k);
				ds.unionByRank(u,v);
			}
			else
			{
				mn_big=min(mn_big,w);
			}

		}
		if(taken)
		{
			cout<<ans<<'\n';
		}
		else
		{
			cout<<ans+min(mn_big-k,k-mx_small)<<'\n';
		}
	}
	return 0;
}
