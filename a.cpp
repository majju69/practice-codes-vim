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
		seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
	}

	int firstBelow(int ind,int lo,int hi,int l,int r,int x)
	{
		if(l>hi||lo>r||seg[ind]>=x)
		{
			return -1;
		}
		if(lo==hi)
		{
			return lo;
		}
		int mid=lo+(hi-lo)/2;
		int ans=firstBelow(2*ind+1,lo,mid,l,r,x);
		if(ans==-1)
		{
			ans=firstBelow(2*ind+2,mid+1,hi,l,r,x);
		}
		return ans;
	}

	int lastBelow(int ind,int lo,int hi,int l,int r,int x)
	{
		if(l>hi||lo>r||seg[ind]>=x)
		{
			return -1;
		}
		if(lo==hi)
		{
			return lo;
		}
		int mid=lo+(hi-lo)/2;
		int ans=lastBelow(2*ind+2,mid+1,hi,l,r,x);
		if(ans==-1)
		{
			ans=lastBelow(2*ind+1,lo,mid,l,r,x);
		}
		return ans;
	}


};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> a(n),ans(n,-1);
	for(auto &v:a)
	{
		cin>>v;
	}
	SegmentTree st(n);
	st.build(0,0,n-1,a);
	for(int i=0;i<n;++i)
	{
		int left=st.lastBelow(0,0,n-1,0,i,a[i]),right=st.firstBelow(0,0,n-1,i,n-1,a[i]);
		if(right==-1)
		{
			right=n;
		}
		ans[right-left-2]=max(ans[right-left-2],a[i]);
	}
	for(int i=n-1;i>=0;--i)
	{
		if(ans[i]==-1)
		{
			ans[i]=ans[i+1];
		}
	}
	for(int i=n-2;i>=0;--i)
	{
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
