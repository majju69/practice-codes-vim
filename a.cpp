#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;
typedef long double ld;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,t;
	ld p,ans=0;
	cin>>n>>p>>t;
	vector<vector<ld>> dp(n+1,vector<ld>(t+1,0));
	dp[n][0]=1;
	for(ll i=0;i<n;++i)
	{
		dp[i][0]=0;
	}
	for(ll i=1;i<=t;++i)
	{
		dp[n][i]=dp[n][i-1]*(1-p);
	}
	for(ll i=n-1;i>=0;--i)
	{
		for(ll j=1;j<=t;++j)
		{
			dp[i][j]+=dp[i+1][j-1]*p+dp[i][j-1]*(1-p);
		}
	}
	for(ll i=1;i<=n;++i)
	{
		ans+=i*dp[i][t];
	}
	cout<<fixed<<setprecision(7)<<n-ans<<'\n';
	return 0;
}
