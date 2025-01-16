#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int gcd(int a,int b)
{
	return ((b==0)?a:gcd(b,a%b));
}

inline pair<int,int> merge(pair<int,int> a,pair<int,int> b)
{
	return {min(a.first,b.first),gcd(a.second,b.second)};
}

class SegmentTree
{

private:

	vector<pair<int,int>> seg;

public:

	SegmentTree(int n)
	{
		seg.resize(4*n+1);
	}

	void build(int ind,int lo,int hi,vector<int> &a)
	{
		if(lo==hi)
		{
			seg[ind]={a[lo],a[lo]};
			return;
		}
		int mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid,a);
		build(2*ind+2,mid+1,hi,a);
		seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
	}

	pair<int,int> query(int ind,int lo,int hi,int l,int r)
	{
		if(l>hi||lo>r)
		{
			return {1e9,0};
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		int mid=lo+(hi-lo)/2;
		return merge(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
	}

};

bool check(int mid,int n,SegmentTree &st)
{
	for(int i=0;i<n;++i)
	{
		if(i+mid>=n)
		{
			break;
		}
		pair<int,int> p=st.query(0,0,n-1,i,i+mid);
		if(p.first==p.second)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,lo=0,hi=-1,ans=0;
	cin>>n;
	vector<int> a(n),idx;
	for(auto &v:a)
	{
		cin>>v;
	}
	SegmentTree st(n);
	st.build(0,0,n-1,a);
	hi=n-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(check(mid,n,st))
		{
			ans=mid;
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	for(int i=0;i<n;++i)
	{
		if(i+ans>=n)
		{
			break;
		}
		pair<int,int> p=st.query(0,0,n-1,i,i+ans);
		if(p.first==p.second)
		{
			idx.push_back(i+1);
		}
	}
	cout<<(int)idx.size()<<' '<<ans<<'\n';
	for(auto &v:idx)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
