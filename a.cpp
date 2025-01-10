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

	void update(ll ind,ll lo,ll hi,ll i,ll val)
	{
		if(lo==hi)
		{
			seg[ind]+=val;
			return;
		}
		ll mid=lo+(hi-lo)/2;
		if(i<=mid)
		{
			update(2*ind+1,lo,mid,i,val);
		}
		else
		{
			update(2*ind+2,mid+1,hi,i,val);
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
	ll n,k,_n=0,total=0;
	map<ll,ll> mp;
	cin>>n>>k;
	vector<ll> a(n);
	for(auto &v:a)
	{
		cin>>v;
		mp[v]=0;
	}
	for(auto &v:mp)
	{
		v.second=_n++;
	}
	for(auto &v:a)
	{
		v=mp[v];
	}
	SegmentTree st(n);
	for(auto &v:a)
	{
		if(v!=_n-1)
		{
			total+=(st.query(0,0,_n-1,v+1,_n-1));
		}
		st.update(0,0,_n-1,v,1);
	}
	if(total<=k)
	{
		cout<<n*(n-1)/2<<'\n';
	}
	else
	{
		// total-cnt<=k => cnt>=total-k => cnt>=req
		ll i=1,j=0,cnt=0,req=total-k,ans=0;
		SegmentTree st_left(_n),st_right(_n);
		for(int idx=0;idx<n;++idx)
		{
			if(idx==0)
			{
				st_left.update(0,0,_n-1,a[idx],1);
			}
			else
			{
				st_right.update(0,0,_n-1,a[idx],1);
			}
		}
		while(i<n-1&&j<n-1)
		{
			if(cnt<req)
			{
				while(cnt<req)
				{
					j++;
					st_right.update(0,0,_n-1,a[j],-1);
					if(a[j]!=_n-1)
					{
						cnt+=st_left.query(0,0,_n-1,a[j]+1,_n-1);
					}
					if(a[j]!=0)
					{
						cnt+=st_right.query(0,0,_n-1,0,a[j]-1);
					}
				}
			}
			else
			{
				while(cnt>=req)		// j....n-2   n-1-j
				{
					ans+=n-1-j;
					st_left.update(0,0,_n-1,a[i],1);
					if(a[i]!=_n-1)
					{
						cnt-=st_left.query(0,0,_n-1,a[i]+1,_n-1);
					}
					if(a[i]!=0)
					{
						cnt-=st_right.query(0,0,_n-1,0,a[i]-1);
					}
					i++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
