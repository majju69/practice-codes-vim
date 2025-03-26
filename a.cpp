#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int get(int k,vector<int> &a)
{
	int n=a.size(),ans=1e9;
	for(int i=0;i<=k;++i)
	{
		int left=a[i],right=a[n-1-(k-i)];
		ans=min(ans,max(0,right-left+1));
	}
	return ans;
}

int dp[501][501];

int solve(int i,int k,vector<vector<int>> &a)
{
	if(i>=(int)a.size())
	{
		return 0;
	}
	if(dp[i][k]!=-1)
	{
		return dp[i][k];
	}
	int ans=1e9;
	for(int j=0;j<(int)a[i].size();++j)
	{
		if(j>k)
		{
			break;
		}
		ans=min(ans,solve(i+1,k-j,a)+a[i][j]);
	}
	return dp[i][k]=ans;
}

int minTime(int k,vector<vector<int>> &a)
{
	int n=a.size();
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			dp[i][j]=-1;
		}
	}
	return solve(0,k,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	vector<vector<int>> a;
	cin>>n>>m>>k;
	for(int i=0;i<n;++i)
	{
		vector<int> tmp,cur;
		string s;
		cin>>s;
		for(int j=0;j<m;++j)
		{
			if(s[j]=='1')
			{
				tmp.push_back(j);
			}
		}
		for(int i=0;i<(int)tmp.size();++i)
		{
			cur.push_back(get(i,tmp));
		}
		cur.push_back(0);
		a.push_back(cur);
	}
	cout<<minTime(k,a)<<'\n';
	return 0;
}
