#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<int> get(vector<int> &a)
{
	int n=a.size(),s=0;
	vector<int> ans,pre(n),suf(n);
	for(int i=0;i<n;++i)
	{
		s+=a[i];
		pre[i]=s;
	}
	s=0;
	for(int i=n-1;i>=0;--i)
	{
		s+=a[i];
		suf[n-i-1]=s;
	}
	for(int pick=0;pick<=n;++pick)
	{
		int cur=0;
		for(int pre_pick=0;pre_pick<=pick;++pre_pick)
		{
			int suf_pick=pick-pre_pick;
			int pre_sum=((pre_pick==0)?0:pre[pre_pick-1]),suf_sum=((suf_pick==0)?0:suf[suf_pick-1]);
			cur=max(cur,pre_sum+suf_sum);
		}
		ans.push_back(cur);
	}
	return ans;
}

int dp[101][10001];

int solve(int i,int m,vector<vector<int>> &a)
{
	if(i>=(int)a.size()||m==0)
	{
		return 0;
	}
	if(dp[i][m]!=-1)
	{
		return dp[i][m];
	}
	int ans=0;
	for(int j=0;j<(int)a[i].size();++j)
	{
		if(j>m)
		{
			break;
		}
		ans=max(ans,solve(i+1,m-j,a)+a[i][j]);
	}
	return dp[i][m]=ans;
}

int maxDamage(int m,vector<vector<int>> &a)
{
	int n=a.size();
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			dp[i][j]=-1;
		}
	}
	return solve(0,m,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a;
	for(int i=0;i<n;++i)
	{
		int len;
		cin>>len;
		vector<int> tmp(len);
		for(auto &v:tmp)
		{
			cin>>v;
		}
		a.push_back(get(tmp));
	}
	cout<<maxDamage(m,a)<<'\n';
	return 0;
}
