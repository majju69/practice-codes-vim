#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

class DisjointSet
{

private:
	
	vector<int> ultimateParent,rank,size;

public:
	
	DisjointSet(int n)
	{
		ultimateParent.resize(n+1);
		rank.resize(n+1,0);
		size.resize(n+1,1);
		for(int i=0;i<=n;++i)
		{
			ultimateParent[i]=i;
		}
	}

	int findUltimateParent(int node)
	{
		if(ultimateParent[node]==node)
		{
			return node;
		}
		return ultimateParent[node]=findUltimateParent(ultimateParent[node]);
	}

	int getSize(int node)
	{
		return size[node];
	}

	int getRank(int node)
	{
		return rank[node];
	}

	void unionByRank(int u,int v)
	{
		int ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
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

	void unionBySize(int u,int v)
	{
		int ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
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
	int n;
	vector<pair<int,int>> unused;
	vector<pair<pair<int,int>,pair<int,int>>> ans;
	cin>>n;
	DisjointSet ds(n);
	for(int i=1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		if(u>v)
		{
			swap(u,v);
		}
		if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
		{
			ds.unionByRank(u,v);
		}
		else
		{
			unused.push_back({u,v});
		}
	}
	while((int)unused.size()>0)
	{
		pair<int,int> rem_edge=unused.back(),add_edge={-1,-1};
		vector<bool> bad(n,0);
		for(auto &edge:unused)
		{
			bad[ds.findUltimateParent(edge.first)]=1;
		}
		for(int i=0;i<n;++i)
		{
			if(!bad[ds.findUltimateParent(i)])
			{
				add_edge.first=i;
				break;
			}
		}
		add_edge.second=rem_edge.second;
		unused.pop_back();
		ds.unionByRank(add_edge.first,add_edge.second);
		ans.push_back({rem_edge,add_edge});
	}
	cout<<(int)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v.first.first+1<<' '<<v.first.second+1<<' '<<v.second.first+1<<' '<<v.second.second+1<<'\n';
	}
	return 0;
}
