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

inline ll get(ll x)
{
	return ((x*(x-1))>>1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q,cur_ans=0;
	cin>>n>>q;
	deque<pair<ll,pair<ll,ll>>> edges(n-1);
	vector<pair<ll,ll>> qry(q);
	vector<ll> ans(q);
	DisjointSet ds(n);
	for(auto &edge:edges)
	{
		cin>>edge.second.first>>edge.second.second>>edge.first;
		edge.second.first--;
		edge.second.second--;
	}
	for(ll i=0;i<q;++i)
	{
		ll x;
		cin>>x;
		qry[i]={x,i};
	}
	sort(qry.begin(),qry.end());
	sort(edges.begin(),edges.end());
	for(auto &q:qry)
	{
		ll w=q.first,idx=q.second;
		while((ll)edges.size()&&edges[0].first<=w)
		{
			ll u=edges[0].second.first,v=edges[0].second.second;
			edges.pop_front();
			if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
			{
				cur_ans-=get(ds.getSize(ds.findUltimateParent(u)));
				cur_ans-=get(ds.getSize(ds.findUltimateParent(v)));
				ds.unionBySize(u,v);
				cur_ans+=get(ds.getSize(ds.findUltimateParent(u)));
			}
		}
		ans[idx]=cur_ans;
	}
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
