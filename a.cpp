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

	vector<long long> seg;

public:

	SegmentTree(int n)
	{
		seg.resize(4*n+1);
	}

	void update(int ind,int lo,int hi,int i,long long val)
	{
		if(lo==hi)
		{
			seg[ind]=val;
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
		seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
	}

	long long query(int ind,int lo,int hi,int l,int r)
	{
		if(l>hi||lo>r)
		{
			return -1e18;
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		int mid=lo+(hi-lo)/2;
		return max(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	stack<pair<int,int>> stk;
	cin>>n;
	vector<int> h(n),b(n),nse(n,n);
	vector<long long> dp(n);
	SegmentTree st(n);
	for(auto &v:h)
	{
		cin>>v;
	}
	for(auto &v:b)
	{
		cin>>v;
	}
	for(int i=n-1;i>=0;--i)
	{
		while(!stk.empty()&&stk.top().first>=h[i])
		{
			stk.pop();
		}
		if(!stk.empty())
		{
			nse[i]=stk.top().second;
		}
		stk.push({h[i],i});
	}
	dp[n-1]=b[n-1];
	st.update(0,0,n-1,n-1,dp[n-1]);
	for(int i=n-2;i>=0;--i)
	{
		if(nse[i]==n)
		{
			dp[i]=max((long long)b[i],b[i]+st.query(0,0,n-1,i+1,n-1));
		}
		else
		{
			dp[i]=max(b[i]+st.query(0,0,n-1,i+1,nse[i]),dp[nse[i]]);
		}
		st.update(0,0,n-1,i,dp[i]);
	}
	cout<<dp[0]<<'\n';
	return 0;
}	
