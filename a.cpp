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

	void build(int ind,int lo,int hi,vector<pair<int,int>> &a)
	{
		if(lo==hi)
		{
			seg[ind]=a[lo].second;
			return;
		}
		int mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid,a);
		build(2*ind+2,mid+1,hi,a);
		seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
	}

	int query(int ind,int lo,int hi,int l,int r)
	{
		if(l>hi||lo>r)
		{
			return -1e9;
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		int mid=lo+(hi-lo)/2;
		return max(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
	}

};

int dp[1000001];

int solve(int i,vector<int> &cost,vector<int> &value)
{
	if(i>=(int)cost.size())
	{
		return 0;
	}
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	int take=solve(i+1,cost,value),skip=solve(cost[i]+1,cost,value)+value[i];
	return dp[i]=max(take,skip);
}

int maxCats(int n,vector<pair<int,int>> &intervals)
{
	int m=intervals.size();
	vector<int> left(m),right(m),cost(n),value(n,0);
	sort(intervals.begin(),intervals.end());
	iota(cost.begin(),cost.end(),0);
	for(int i=0;i<m;++i)
	{
		left[i]=intervals[i].first;
		right[i]=intervals[i].second;
	}
	sort(left.begin(),left.end());
	sort(right.begin(),right.end());
	SegmentTree st(m);
	st.build(0,0,m-1,intervals);
	for(int i=0;i<n;++i)
	{
		int v=m-((upper_bound(left.begin(),left.end(),n)-lower_bound(left.begin(),left.end(),i+1))+(upper_bound(right.begin(),right.end(),i-1)-lower_bound(right.begin(),right.end(),0))),c=i;
		int idx=upper_bound(intervals.begin(),intervals.end(),make_pair(i,(int)1e9))-intervals.begin()-1;
		if(idx>=0)
		{
			c=st.query(0,0,m-1,0,idx);
		}
		value[i]=v;
		cost[i]=max(cost[i],c);
	}
	for(int i=0;i<=n;++i)
	{
		dp[i]=-1;
	}
	return solve(0,cost,value);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		vector<pair<int,int>> intervals(m);
		for(auto &v:intervals)
		{
			cin>>v.first>>v.second;
			v.first--;
			v.second--;
		}
		cout<<maxCats(n,intervals)<<'\n';
	}
	return 0;
}
