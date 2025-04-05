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
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,ans=0;
		vector<vector<pair<int,int>>> a(10);
		cin>>n>>m;
		DisjointSet ds(n);
		for(int i=0;i<m;++i)
		{
			int _a,d,k;
			cin>>_a>>d>>k;
			_a--;
			d--;
			if(k>0)
			{
				a[d].push_back({_a,k});
			}
		}
		for(int d=0;d<10;++d)
		{
			if((int)a[d].size()==0)
			{
				continue;
			}
			vector<pair<int,int>> ranges(n);
			DisjointSet ds_cur(n);
			for(int i=0;i<n;++i)
			{
				ranges[i].first=ranges[i].second=i;
			}
			for(auto &v:a[d])
			{
				int lb=v.first,ub=v.first+(d+1)*v.second;
				int cur=lb;
				while(cur+d+1<=ub)
				{
					ds.unionByRank(cur,cur+d+1);
					ds_cur.unionByRank(cur,cur+d+1);
					ranges[ds_cur.findUltimateParent(cur)].second=max(ranges[ds_cur.findUltimateParent(cur)].second,cur+d+1);
					ranges[ds_cur.findUltimateParent(cur)].first=min(ranges[ds_cur.findUltimateParent(cur)].first,cur);
					cur=ranges[ds_cur.findUltimateParent(cur)].second;
				}
			}
		}
		for(int i=0;i<n;++i)
		{
			ans+=(ds.findUltimateParent(i)==i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
