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
		seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
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
		return gcd(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,g=0,mx=0;
		cin>>n;
		vector<int> a(n);
		for(auto &v:a)
		{
			cin>>v;
			g=gcd(g,v);
		}
		for(int i=0;i<n;++i)
		{
			a.push_back(a[i]);
		}
		SegmentTree st(2*n);
		st.build(0,0,2*n-1,a);
		for(int i=0;i<n;++i)
		{
			int lo=i,hi=i+n-1,idx=-1;
			while(lo<=hi)
			{
				int mid=lo+(hi-lo)/2;
				int cur=st.query(0,0,2*n-1,i,mid);
				if(cur==g)
				{
					idx=mid;
					hi=mid-1;
				}
				else
				{
					lo=mid+1;
				}
			}
			mx=max(mx,idx-i);
		}
		cout<<mx<<'\n';
	}
	return 0;
}
