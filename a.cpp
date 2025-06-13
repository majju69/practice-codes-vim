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
	int n,m,idx=0,ans=0;
	cin>>n>>m;
	vector<int> mn(n,0),mx(n,0);
	DisjointSet ds(n);
	iota(mn.begin(),mn.end(),0);
	iota(mx.begin(),mx.end(),0);
	for(int i=0;i<m;++i)
	{
		int u,v,mn_u=-1,mn_v=-1,mx_u=-1,mx_v=-1;
		cin>>u>>v;
		u--;
		v--;
		mn_u=mn[ds.findUltimateParent(u)];
		mn_v=mn[ds.findUltimateParent(v)];
		mx_u=mx[ds.findUltimateParent(u)];
		mx_v=mx[ds.findUltimateParent(v)];
		ds.unionBySize(u,v);
		mn[ds.findUltimateParent(u)]=min({mn_u,mn_v,u,v});
		mx[ds.findUltimateParent(u)]=max({mx_u,mx_v,u,v});
	}
	while(idx<n)
	{
		if(ds.getSize(ds.findUltimateParent(idx))==mx[ds.findUltimateParent(idx)]-mn[ds.findUltimateParent(idx)]+1)
		{
			idx++;
		}
		else
		{
			int cur=idx+1;
			while(ds.getSize(ds.findUltimateParent(idx))!=mx[ds.findUltimateParent(idx)]-mn[ds.findUltimateParent(idx)]+1)
			{
				if(ds.findUltimateParent(idx)==ds.findUltimateParent(cur))
				{
					cur++;
					continue;
				}
				int u=idx,v=cur;
				int mn_u=mn[ds.findUltimateParent(u)],mn_v=mn[ds.findUltimateParent(v)],mx_u=mx[ds.findUltimateParent(u)],mx_v=mx[ds.findUltimateParent(v)];
				ds.unionBySize(u,v);
				ans++;
				mn[ds.findUltimateParent(u)]=min({mn_u,mn_v,u,v});
				mx[ds.findUltimateParent(u)]=max({mx_u,mx_v,u,v});
				cur++;
			}
			idx=cur;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
