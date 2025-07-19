#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,c;
	cin>>n>>c;
	vector<int> a(n-1),b(n-1);
	vector<vector<int>> dp(n,vector<int>(2,0));
	for(auto &v:a)
	{
		cin>>v;
	}
	for(auto &v:b)
	{
		cin>>v;
	}
	dp[1][0]=a[0];
	dp[1][1]=c+b[0];
	for(int i=2;i<n;++i)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i-1];
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+c)+b[i-1];
	}
	for(int i=0;i<n;++i)
	{
		cout<<min(dp[i][0],dp[i][1])<<' ';
	}
	cout<<'\n';
	return 0;
}

