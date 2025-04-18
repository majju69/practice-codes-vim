#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[50001][5];

int solve(int i,int pvs,int x,vector<int> &a)
{
	if(i>=(int)a.size())
	{
		return 0;
	}
	if(dp[i][pvs]!=-1)
	{
		return dp[i][pvs];
	}
	if(pvs==0)
	{
		return dp[i][pvs]=max(solve(i+1,0,x,a),solve(i+1,1,x,a)+1);
	}
	if(pvs==1)
	{
		if(a[i]+a[i-1]>=2*x)
		{
			return dp[i][pvs]=max(solve(i+1,2,x,a),solve(i+1,3,x,a)+1);
		}
		else
		{
			return dp[i][pvs]=solve(i+1,2,x,a);
		}
	}
	if(pvs==2)
	{	
		return dp[i][pvs]=max(solve(i+1,0,x,a),solve(i+1,1,x,a)+1);
	}
	if(a[i-2]+a[i-1]+a[i]>=3*x&&a[i-1]+a[i]>=2*x)
	{
		return dp[i][pvs]=max(solve(i+1,3,x,a)+1,solve(i+1,2,x,a));
	}
	return dp[i][pvs]=solve(i+1,2,x,a);
}

int maxTake(vector<int> &a,int x)
{
	int n=a.size();
	if(n==1)
	{
		return 1;
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<5;++j)
		{
			dp[i][j]=-1;
		}
	}
	return max({solve(2,0,x,a),solve(2,1,x,a)+1,solve(2,2,x,a)+1,((a[0]+a[1]>=2*x)?solve(2,3,x,a)+2:(int)-1e9)});
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
		int n,x;
		cin>>n;
		vector<int> a(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		cin>>x;
		cout<<maxTake(a,x)<<'\n';
	}
	return 0;
}
