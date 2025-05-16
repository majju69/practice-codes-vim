#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int mod=1e9+7;

inline int add(int a,int b)
{
	return ((a%mod)+(b%mod))%mod;
}

class SegmentTree
{

private:

	vector<int> seg;

public:

	SegmentTree(int n)
	{
		seg.resize(4*n+1);
	}

	void update(int ind,int lo,int hi,int i,int val)
	{
		if(lo==hi)
		{
			seg[ind]=add(seg[ind],val);
			return;
		}
		int mid=lo+(hi-lo)/2;
		if(i<=mid)
		{
			update(2*ind+1,lo,mid,i,val);
		}
		else
		{
			update(2*ind+2,mid+1,hi,i,val);
		}
		seg[ind]=add(seg[2*ind+1],seg[2*ind+2]);
	}

	int query(int ind,int lo,int hi,int l,int r)
	{
		if(l>hi||lo>r)
		{
			return 0;
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		int mid=lo+(hi-lo)/2;
		return add(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ind=0,ans=0;
	map<int,int> mp;
	cin>>n;
	vector<int> a(n),dp(n);
	SegmentTree st(n);
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
	for(int i=0;i<n;++i)
	{
		if(a[i]==0)
		{
			dp[i]=1;
		}
		else
		{
			int cur=st.query(0,0,ind-1,0,a[i]-1);
			dp[i]=add(cur,1);
		}
		st.update(0,0,ind-1,a[i],dp[i]);
		ans=add(ans,dp[i]);
	}
	cout<<ans<<'\n';
	return 0;
}	
