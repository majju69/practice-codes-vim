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
			seg[ind]=val;
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
		seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
	}

	ll query(ll ind,ll lo,ll hi,ll l,ll r)
	{
		if(l>hi||lo>r)
		{
			return 1e18;
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		ll mid=lo+(hi-lo)/2;
		return min(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
	}

};

bool check(ll mid,vector<ll> &a)
{
	ll n=a.size(),sum=0,ans=1e18;
	vector<ll> pre(n),jump(n,n),dp(n);
	pre[0]=a[0];
	for(ll i=1;i<n;++i)
	{
		pre[i]=pre[i-1]+a[i];
	}
	for(ll i=0;i<n-1;++i)
	{
		ll idx=upper_bound(pre.begin()+i+1,pre.end(),mid+pre[i])-pre.begin();
		jump[i]=idx;
	}
	SegmentTree st(n);
	for(ll i=n-1;i>=0;--i)
	{
		if(jump[i]==n)
		{
			dp[i]=a[i];
		}
		else
		{
			dp[i]=a[i]+st.query(0,0,n-1,i+1,jump[i]);
		}
		st.update(0,0,n-1,i,dp[i]);
	}
	for(ll i=0;i<n;++i)
	{
		ans=min(ans,dp[i]);
		sum+=a[i];
		if(sum>mid)
		{
			break;
		}
	}
	return (ans<=mid);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,lo=-1e18,hi=0,ans=-1;
		cin>>n;
		vector<ll> a(n);
		for(auto &v:a)
		{
			cin>>v;
			hi+=v;
			lo=max(lo,v);
		}
		while(lo<=hi)
		{
			ll mid=lo+(hi-lo)/2;
			if(check(mid,a))
			{
				ans=mid;
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
