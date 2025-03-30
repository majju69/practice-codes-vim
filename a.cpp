#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[200001][4];

int solve(int i,int pvs,vector<int> &a)		// 0 -> pos    1 -> neg    2 -> no op
{
	if(i>=(int)a.size())
	{
		return 0;
	}
	if(dp[i][pvs]!=-1)
	{
		return dp[i][pvs];
	}
	if(a[i-1]>a[i])
	{
		if(pvs==1)
		{
			return dp[i][pvs]=min({solve(i+1,1,a),solve(i+1,0,a)+1,solve(i+1,2,a)});
		}
		else if(pvs==0)
		{
			return dp[i][pvs]=solve(i+1,0,a)+1;
		}
		else
		{
			return dp[i][pvs]=solve(i+1,0,a)+1;
		}
	}
	else if(a[i-1]<a[i])
	{
		if(pvs==0)
		{
			return dp[i][pvs]=solve(i+1,0,a);
		}
		else if(pvs==1)
		{
			return dp[i][pvs]=min({solve(i+1,0,a),solve(i+1,1,a)+1,solve(i+1,2,a)});
		}
		else
		{
			return dp[i][pvs]=min(solve(i+1,2,a),solve(i+1,0,a)+1);
		}
	}
	else
	{
		if(pvs==0)
		{
			return dp[i][pvs]=solve(i+1,0,a)+1;
		}
		else if(pvs==1)
		{
			return dp[i][pvs]=min({solve(i+1,0,a),solve(i+1,1,a)+1,solve(i+1,2,a)});
		}
		else
		{
			return dp[i][pvs]=solve(i+1,0,a)+1;
		}
	}
}

int countOperations(vector<int> &a)
{
	int n=a.size();
	for(int i=0;i<=n;++i)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=-1;
	}
	return min({solve(1,1,a)+1,solve(1,0,a)+1,solve(1,2,a)});
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
		cin>>n;
		vector<int> a(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		cout<<countOperations(a)<<'\n';
	}
	return 0;
}
