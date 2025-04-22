#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,x,ans=-1;
	cin>>n>>k>>x;
	vector<ll> a(n);
	vector<vector<ll>> dp(n,vector<ll>(x,-1e18));
	for(auto &v:a)
	{
		cin>>v;
	}
	for(ll i=0;i<k;++i)
	{
		dp[i][0]=a[i];
	}
	for(ll i1=1;i1<n;++i1)
	{
		for(ll i2=1;i2<x;++i2)
		{
			for(ll i3=i1-1;i3>=max(0LL,i1-k);--i3)
			{
				dp[i1][i2]=max(dp[i3][i2-1]+a[i1],dp[i1][i2]);
			}
		}
	}
	for(ll i=n-1;i>=n-k;--i)
	{
		ans=max(ans,dp[i][x-1]);
	}
	cout<<ans<<'\n';
	return 0;
}
