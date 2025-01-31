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

	vector<ll> seg,lazy;

public:

	SegmentTree(ll n)
	{
		for(ll i=0;i<=4*n;++i)
		{
			seg.push_back(0);
			lazy.push_back(-1);
		}
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
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}

	void update(ll ind,ll lo,ll hi,ll l,ll r,ll val)
	{
		if(lazy[ind]!=-1)
		{
			seg[ind]=(hi-lo+1)*lazy[ind];
			if(lo!=hi)
			{
				lazy[2*ind+1]=lazy[ind];
				lazy[2*ind+2]=lazy[ind];
			}
			lazy[ind]=-1;
		}
		if(l>hi||lo>r)
		{
			return;
		}
		if(l<=lo&&hi<=r)
		{
			seg[ind]=(hi-lo+1)*val;
			if(lo!=hi)
			{
				lazy[2*ind+1]=val;
				lazy[2*ind+2]=val;
			}
			return;
		}
		ll mid=lo+(hi-lo)/2;
		update(2*ind+1,lo,mid,l,r,val);
		update(2*ind+2,mid+1,hi,l,r,val);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}

	ll query(ll ind,ll lo,ll hi,ll l,ll r)
	{
		if(lazy[ind]!=-1)
		{
			seg[ind]=(hi-lo+1)*lazy[ind];
			if(lo!=hi)
			{
				lazy[2*ind+1]=lazy[ind];
				lazy[2*ind+2]=lazy[ind];
			}
			lazy[ind]=-1;
		}
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
	ll n,q;
	cin>>n;
	vector<ll> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	SegmentTree st(n);
	st.build(0,0,n-1,a);
	cin>>q;
	while(q--)
	{
		ll type;
		cin>>type;
		if(type==1)
		{
			ll i,val,lo=0,hi=-1,idx=-1;
			cin>>i>>val;
			i--;
			lo=i;
			hi=n-1;
			while(lo<=hi)
			{
				ll mid=lo+(hi-lo)/2;
				ll sum=st.query(0,0,n-1,i,mid);
				if(sum<val)
				{
					idx=mid;
					lo=mid+1;
				}
				else
				{
					hi=mid-1;
				}
			}
			if(idx==-1)
			{
				ll cur=st.query(0,0,n-1,i,i);
				st.update(0,0,n-1,i,i,cur-val);
			}
			else
			{
				val-=st.query(0,0,n-1,i,idx);
				st.update(0,0,n-1,i,idx,0);
				if(idx!=n-1)
				{
					ll cur=st.query(0,0,n-1,idx+1,idx+1);
					st.update(0,0,n-1,idx+1,idx+1,cur-val);
				}
			}
		}
		else
		{
			ll i;
			cin>>i;
			i--;
			cout<<a[i]-st.query(0,0,n-1,i,i)<<'\n';
		}
	}
	return 0;
}
