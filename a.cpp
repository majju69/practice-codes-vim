#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[200001][5][3];

int solve(int i,int pvs,bool left,vector<int> &a)
{
	if(i>=((int)a.size()))
	{
		if(left)
		{
			if(pvs==0)
			{
				return 0;
			}
			return 1e9;
		}
		if(pvs==0)
		{
			return 1e9;
		}
		if(pvs==1||pvs==2)
		{
			return 0;
		}
		return 1;
	}
	if(dp[i][pvs][left]!=-1)
	{
		return dp[i][pvs][left];
	}
	if(pvs==0)
	{
		return dp[i][pvs][left]=solve(i+1,a[i],left,a);
	}
	if(pvs==1)
	{
		return dp[i][pvs][left]=min({solve(i+1,(a[i]|1),left,a)+1,solve(i+1,(a[i]|2),left,a)+2,((left)?(int)1e9:solve(i+1,a[i],1,a))});
	}
	if(pvs==2)
	{
		return dp[i][pvs][left]=min({solve(i+1,(a[i]|2),left,a)+1,solve(i+1,(a[i]|1),left,a)+2,((left)?(int)1e9:solve(i+1,a[i],1,a))});
	}
	return dp[i][pvs][left]=min({solve(i+1,(a[i]|2),left,a)+2,solve(i+1,(a[i]|1),left,a)+2,solve(i+1,3,left,a)+2,((left)?(int)1e9:solve(i+1,a[i],1,a))+1});
}

int minCost(vector<string> &s)
{
	int n=s[0].size();
	vector<int> a(n);
	for(int i=0;i<n;++i)
	{
		a[i]=(s[0][i]=='*')+2*(s[1][i]=='*');
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<5;++j)
		{
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-1;
		}
	}
	return solve(1,a[0],0,a);
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
		int n;
		vector<string> a(2);
		cin>>n>>a[0]>>a[1];
		cout<<minCost(a)<<'\n';
	}
	return 0;
}	
