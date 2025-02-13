#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[101][10001];

bool solve(int i,int tar,vector<int> &a,vector<int> &b)
{
	if(i<0)
	{
		return (tar==0);
	}
	if(dp[i][tar]!=-1)
	{
		return dp[i][tar];
	}
	bool take_a=0,take_b=0;
	if(a[i]<=tar)
	{
		take_a=solve(i-1,tar-a[i],a,b);
	}
	if(b[i]<=tar)
	{
		take_b=solve(i-1,tar-b[i],a,b);
	}
	return dp[i][tar]=(take_a||take_b);
}

int minCost(vector<int> &a,vector<int> &b)
{
	int n=a.size(),sum=0,mx_sum=0,ans=0,mn=1e9;
	for(int i=0;i<n;++i)
	{
		sum+=(a[i]+b[i]);
		ans+=(a[i]*a[i]+b[i]*b[i]);
		mx_sum+=max(a[i],b[i]);
	}
	ans*=(n-2);
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=mx_sum;++j)
		{
			dp[i][j]=-1;
		}
	}
	for(int s=0;s<=mx_sum;++s)
	{
		if(solve(n-1,s,a,b))
		{
			int s1=s,s2=sum-s;
			mn=min(mn,s1*s1+s2*s2);
		}
	}
	ans+=mn;
	return ans;
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
		vector<int> a(n),b(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		for(auto &v:b)
		{
			cin>>v;
		}
		cout<<minCost(a,b)<<'\n';
	}
	return 0;
}
