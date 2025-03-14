#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

class SegmentTree
{

private:

	vector<ll> seg;

public:

	SegmentTree(ll n)
	{
		seg.resize(4*n+1);
	}

	void update(ll ind,ll lo,ll hi,ll i)
	{
		if(lo==hi)
		{
			seg[ind]++;
			return;
		}
		ll mid=lo+(hi-lo)/2;
		if(i<=mid)
		{
			update(2*ind+1,lo,mid,i);
		}
		else
		{
			update(2*ind+2,mid+1,hi,i);
		}
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
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
		return query(2*ind+1,lo,mid,l,r)+query(2*ind+2,mid+1,hi,l,r);
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,ans=0;
	map<ll,ll> mp;
	cin>>n;
	vector<ll> a(n),pre(n),suf(n);
	SegmentTree st(n+1);
	for(auto &v:a)
	{
		cin>>v;
	}
	for(ll i=0;i<n;++i)
	{
		mp[a[i]]++;
		pre[i]=mp[a[i]];
	}
	mp.clear();
	for(ll i=n-1;i>=0;--i)
	{
		mp[a[i]]++;
		suf[i]=mp[a[i]];
	}
	for(ll i=n-1;i>=0;--i)
	{
		if(pre[i]!=0)
		{
			ans+=st.query(0,0,n,0,pre[i]-1);
		}
		st.update(0,0,n,suf[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
