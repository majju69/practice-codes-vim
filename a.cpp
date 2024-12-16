#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int get(int l,int r)
{
	int n=r-l+1;
	return ((n*(n-1))>>1);
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

	void update(int ind,int lo,int hi,int i)
	{
		if(lo==hi)
		{
			seg[ind]++;
			return;
		}
		int mid=lo+(hi-lo)/2;
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
		return query(2*ind+1,lo,mid,l,r)+query(2*ind+2,mid+1,hi,l,r);
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,cur_cnt=0;
	cin>>n;
	vector<int> a(n);
	vector<vector<int>> cnt(n,vector<int>(n,0));
	for(auto &v:a)
	{
		cin>>v;
		v--;
	}
	for(int i=0;i<n;++i)
	{
		int cur=0;
		SegmentTree st(n);
		for(int j=i;j<n;++j)
		{
			if(a[j]!=n-1)
			{
				cur+=st.query(0,0,n-1,a[j]+1,n-1);
			}
			st.update(0,0,n-1,a[j]);
			cnt[i][j]=cur;
		}
	}
	cur_cnt=cnt[0][n-1];
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		cur_cnt+=(get(l,r)-2*cnt[l][r]);
		cnt[l][r]=get(l,r)-cnt[l][r];
		cout<<((cur_cnt&1)?"odd":"even")<<'\n';
	}
	return 0;
}
