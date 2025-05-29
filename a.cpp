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

	void update(int ind,int lo,int hi,int i)
	{
		if(lo==hi)
		{
			seg[ind]=1;
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
	int n,k,d;
	cin>>n>>k>>d;
	vector<int> a(n),dp(n);
	SegmentTree st(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	sort(a.begin(),a.end());
	for(int i=n-k;i>=0;--i)
	{
		if(a[n-1]-a[i]<=d)
		{
			dp[i]=1;
			st.update(0,0,n-1,i);
		}
	}
	for(int i=n-k-1;i>=0;--i)
	{
		if(dp[i])
		{
			continue;
		}
		int lb=i+k,ub=upper_bound(a.begin(),a.end(),a[i]+d)-a.begin();
		if(ub>=n)
		{
			dp[i]=1;
			st.update(0,0,n-1,i);
			continue;
		}
		if(lb<=ub)
		{
			int sum=st.query(0,0,n-1,lb,ub);
			if(sum>0)
			{
				dp[i]=1;
				st.update(0,0,n-1,i);
			}
		}
	}
	cout<<((dp[0]!=0)?"YES":"NO")<<'\n';
	return 0;
}
