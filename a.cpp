#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[101][101][101][3];

int solve(int i,int odd,int even,int pvs,vector<int> &a)	// pvs=1 => pvs odd
{
	if(i>=(int)a.size())
	{
		return 0;
	}
	if(dp[i][odd][even][pvs]!=-1)
	{
		return dp[i][odd][even][pvs];
	}
	if(a[i]!=-1)
	{
		return dp[i][odd][even][pvs]=solve(i+1,odd,even,(a[i]&1),a)+((a[i]+pvs)&1);
	}
	else
	{
		int ans=1e9;
		if(odd>=1)
		{
			ans=min(ans,solve(i+1,odd-1,even,1,a)+(pvs==0));
		}
		if(even>=1)
		{
			ans=min(ans,solve(i+1,odd,even-1,0,a)+(pvs==1));
		}
		return dp[i][odd][even][pvs]=ans;
	}
}

int minComplexity(vector<int> &a)
{
	int n=a.size();
	int even=((n-1)>>1)+1;
	int odd=n-even;
	for(auto &v:a)
	{
		if(v!=-1)
		{
			if(v&1)
			{
				odd--;
			}
			else
			{
				even--;
			}
		}
	}
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=odd;++j)
		{
			for(int k=0;k<=even;++k)
			{
				dp[i][j][k][0]=dp[i][j][k][1]=dp[i][j][k][2]=-1;
			}
		}
	}
	if(a[0]!=-1)
	{
		return solve(1,odd,even,(a[0]&1),a);
	}
	else
	{
		int ans=1e9;
		if(odd>=1)
		{
			ans=min(ans,solve(1,odd-1,even,1,a));
		}
		if(even>=1)
		{
			ans=min(ans,solve(1,odd,even-1,0,a));
		}
		return ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
		v--;
	}
	cout<<minComplexity(a)<<'\n';
	return 0;
}
