#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll dp[5002][5002];

ll solve(int i,int j,int n,vector<int> &a,vector<int> &cold,vector<int> &hot)
{
	if(max(i,j)+1>n)
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	int to_take=max(i,j)+1;
	ll cpu1=1e18,cpu2=1e18;
	if(i==0||a[i]!=a[to_take])
	{
		cpu1=solve(to_take,j,n,a,cold,hot)+cold[a[to_take]];
	}
	else
	{
		cpu1=solve(to_take,j,n,a,cold,hot)+hot[a[to_take]];
	}
	if(j==0||a[j]!=a[to_take])
	{
		cpu2=solve(i,to_take,n,a,cold,hot)+cold[a[to_take]];
	}
	else
	{
		cpu2=solve(i,to_take,n,a,cold,hot)+hot[a[to_take]];
	}
	return dp[i][j]=min(cpu1,cpu2);
}

ll minTime(int n,vector<int> &a,vector<int> &hot,vector<int> &cold)
{
	for(int i=0;i<=n+1;++i)
	{
		for(int j=0;j<=n+1;++j)
		{
			dp[i][j]=-1;
		}
	}
	return solve(0,0,n,a,cold,hot);
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
		int n,k;
		cin>>n>>k;
		vector<int> a(n+1),cold(k+1),hot(k+1);
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		for(int i=1;i<=k;++i)
		{
			cin>>cold[i];
		}
		for(int i=1;i<=k;++i)
		{
			cin>>hot[i];
		}
		cout<<minTime(n,a,hot,cold)<<'\n';
	}
	return 0;
}
