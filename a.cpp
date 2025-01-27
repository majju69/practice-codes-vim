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
	string s;
	cin>>s;
	int q,n=s.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i=n-1;i>=0;--i)
	{
		dp[i][i]=1;
		for(int j=i+1;j<n;++j)
		{
			dp[i][j]=(s[i]==s[j]&&(i+1>j-1||dp[i+1][j-1]));
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			dp[i][j]+=((i>=1)?dp[i-1][j]:0)+((j>=1)?dp[i][j-1]:0)-((i>=1&&j>=1)?dp[i-1][j-1]:0);
		}
	}
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		cout<<dp[r][r]-((l>=1)?(dp[l-1][r]+dp[r][l-1]-dp[l-1][l-1]):0)<<'\n';
	}
	return 0;
}
