#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

class SegmentTree
{

private:

	vector<int> seg;

public:

	SegmentTree(int n)
	{
		seg.resize(4*n+1);
	}

	void build(int ind,int lo,int hi,vector<int> &a)
	{
		if(lo==hi)
		{
			seg[ind]=a[lo];
			return;
		}
		int mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid,a);
		build(2*ind+2,mid+1,hi,a);
		seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
	}

	int firstAbove(int ind,int lo,int hi,int l,int r,int x)
	{
		if(seg[ind]<x||l>hi||lo>r)
		{
			return -1;
		}
		if(lo==hi)
		{
			return lo;
		}
		int mid=lo+(hi-lo)/2;
		int ans=firstAbove(2*ind+1,lo,mid,l,r,x);
		if(ans==-1)
		{
			ans=firstAbove(2*ind+2,mid+1,hi,l,r,x);
		}
		return ans;
	}

	int lastAbove(int ind,int lo,int hi,int l,int r,int x)
	{
		if(seg[ind]<x||l>hi||lo>r)
		{
			return -1;
		}
		if(lo==hi)
		{
			return lo;
		}
		int mid=lo+(hi-lo)/2;
		int ans=lastAbove(2*ind+2,mid+1,hi,l,r,x);
		if(ans==-1)
		{
			ans=lastAbove(2*ind+1,lo,mid,l,r,x);
		}
		return ans;
	}


};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ans=0;
	cin>>n;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	SegmentTree st(n);
	st.build(0,0,n-1,a);
	for(int i=0;i<n;++i)
	{
		int left=-1,right=-1;
		if(i>0)
		{
			left=st.lastAbove(0,0,n-1,0,i-1,a[i]);
		}
		if(i<n-1)
		{
			right=st.firstAbove(0,0,n-1,i+1,n-1,a[i]);
		}
		if(left!=-1)
		{
			ans=max(ans,(a[i]^a[left]));
		}
		if(right!=-1)
		{
			ans=max(ans,(a[i]^a[right]));
		}
	}
	cout<<ans<<'\n';
	return 0;
}
