#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N=1e5;
int mn[4*N+1],mx[4*N+1],nxt[N],a[N],dp[N];

void build(int ind,int lo,int hi)
{
	if(lo==hi)
	{
		mn[ind]=a[lo];
		mx[ind]=a[lo];
		return;
	}
	int mid=lo+(hi-lo)/2;
	build(2*ind+1,lo,mid);
	build(2*ind+2,mid+1,hi);
	mn[ind]=min(mn[2*ind+1],mn[2*ind+2]);
	mx[ind]=max(mx[2*ind+1],mx[2*ind+2]);
}

void update(int ind,int lo,int hi,int i,int val)
{
	if(lo==hi)
	{
		mn[ind]=val;
		mx[ind]=val;
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
	mn[ind]=min(mn[2*ind+1],mn[2*ind+2]);
	mx[ind]=max(mx[2*ind+1],mx[2*ind+2]);
}

pair<int,int> query(int ind,int lo,int hi,int l,int r)
{
	if(l>hi||lo>r)
	{
		return {1e9+10,-1e9-10};
	}
	if(l<=lo&&hi<=r)
	{
		return {mn[ind],mx[ind]};
	}
	int mid=lo+(hi-lo)/2;
	pair<int,int> left=query(2*ind+1,lo,mid,l,r),right=query(2*ind+2,mid+1,hi,l,r);
	return {min(left.first,right.first),max(left.second,right.second)};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,s,l;
	cin>>n>>s>>l;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	build(0,0,n-1);
	for(int i=0;i<n;++i)
	{
		int lo=i,hi=n-1,cur=-1;
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2;
			pair<int,int> p=query(0,0,n-1,i,mid);
			if(p.second-p.first<=s)
			{
				cur=mid;
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		nxt[i]=cur;
	}
	for(int i=n-1;i>=0;--i)
	{
		int lo=i+l-1,hi=nxt[i];
		if(lo>hi)
		{
			dp[i]=1e9;
		}
		else
		{
			if(hi==n-1)
			{
				dp[i]=1;
			}
			else
			{
				pair<int,int> p=query(0,0,n-1,lo+1,hi+1);
				dp[i]=p.first+1;
			}
		}
		update(0,0,n-1,i,dp[i]);
	}
	if(dp[0]>n)
	{
		dp[0]=-1;
	}
	cout<<dp[0]<<'\n';
	return 0;
}
