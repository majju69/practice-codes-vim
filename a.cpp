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
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,ind=0,ans=0;
		map<ll,ll> mp;
		cin>>n;
		vector<ll> a(n);
		for(auto &v:a)
		{
			cin>>v;
			mp[v]=0;
		}
		for(auto &v:mp)
		{
			v.second=ind++;
		}
		for(auto &v:a)
		{
			v=mp[v];
		}
		SegmentTree st(ind);
		for(auto &v:a)
		{
			ll small=0,big=0;
			if(v!=0)
			{
				small=st.query(0,0,ind-1,0,v-1);
			}
			if(v!=ind-1)
			{
				big=st.query(0,0,ind-1,v+1,ind-1);
			}
			ans+=min(small,big);
			st.update(0,0,ind-1,v);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
