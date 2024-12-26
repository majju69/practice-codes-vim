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

ll gcd(ll a,ll b)
{
	return ((b==0)?a:gcd(b,a%b));
}

class SegmentTree
{

private:

	vector<ll> seg;

public:

	SegmentTree(ll n)
	{
		seg.resize(4*n+1);
	}

	void build(ll ind,ll lo,ll hi,vector<ll> &a)
	{
		if(lo==hi)
		{
			seg[ind]=a[lo];
			return;
		}
		ll mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid,a);
		build(2*ind+2,mid+1,hi,a);
		seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
	}

	ll query(ll ind,ll lo,ll hi,ll l,ll r)
	{
		if(l>hi||lo>r)
		{
			return 0;
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		ll mid=lo+(hi-lo)/2;
		return gcd(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
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
		ll n,p,ans=0;
		cin>>n>>p;
		vector<ll> a(n);
		vector<pair<ll,ll>> b(n),ranges(n,{0,-1});
		for(ll i=0;i<n;++i)
		{
			cin>>a[i];
			b[i].first=a[i];
			b[i].second=i;
			ranges[i]={i,i};
		}
		sort(b.begin(),b.end());
		SegmentTree st(n);
		st.build(0,0,n-1,a);
		DisjointSet ds(n);
		for(auto &v:b)
		{
			if(v.first>=p)
			{
				break;
			}
			ll i=v.second,g=v.first;
			ll l=i,r=i;
			while(l>=0&&st.query(0,0,n-1,l,i)==g)
			{
				if(ds.findUltimateParent(l)!=ds.findUltimateParent(i))
				{
					ans+=g;
					ds.unionByRank(l,i);
				}
				ranges[ds.findUltimateParent(i)].first=min(ranges[ds.findUltimateParent(i)].first,l);
				l=ranges[ds.findUltimateParent(l)].first-1;
			}
			while(r<n&&st.query(0,0,n-1,i,r)==g)
			{
				if(ds.findUltimateParent(i)!=ds.findUltimateParent(r))
				{
					ans+=g;
					ds.unionByRank(i,r);
				}
				ranges[ds.findUltimateParent(i)].second=max(ranges[ds.findUltimateParent(i)].second,r);
				r=ranges[ds.findUltimateParent(r)].second+1;
			}	
		}
		for(ll i=1;i<n;++i)
		{
			if(ds.findUltimateParent(i)!=ds.findUltimateParent(0))
			{
				ans+=p;
				ds.unionByRank(0,i);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
