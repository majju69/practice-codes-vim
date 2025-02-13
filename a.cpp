#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline pair<ll,ll> merge(pair<ll,ll> a,pair<ll,ll> b)
{
	return {min(a.first,a.second+b.first),a.second+b.second};
}

class SegmentTree
{

private:

	vector<pair<ll,ll>> seg;	// {pref,sum}

public:

	SegmentTree(ll n)
	{
		seg.resize(4*n+1);
	}

	void build(ll ind,ll lo,ll hi,vector<ll> &a)
	{
		if(lo==hi)
		{
			seg[ind]={min(a[lo],0LL),a[lo]};
			return;
		}
		ll mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid,a);
		build(2*ind+2,mid+1,hi,a);
		seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
	}

	pair<ll,ll> query(ll ind,ll lo,ll hi,ll l,ll r)
	{
		if(l>hi||lo>r)
		{
			return {1e18,0};
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		ll mid=lo+(hi-lo)/2;
		return merge(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
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
		ll n,s,lo=1,hi=0,ans_l=-1,ans_r=-1;
		cin>>n>>s;
		vector<ll> a(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		SegmentTree st(n);
		st.build(0,0,n-1,a);
		hi=n;
		while(lo<=hi)
		{
			ll mid=lo+(hi-lo)/2;
			ll idx=-1;
			for(ll i=0;i<n-mid+1;++i)
			{
				pair<ll,ll> p=st.query(0,0,n-1,i,i+mid-1);
				if(p.first+s>=0)
				{
					idx=i;
					break;
				}
			}
			if(idx!=-1)
			{
				ans_l=idx;
				ans_r=idx+mid-1;
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		if(ans_l==-1)
		{
			cout<<-1<<'\n';
		}
		else
		{
			cout<<ans_l+1<<' '<<ans_r+1<<'\n';
		}
	}
	return 0;
}
