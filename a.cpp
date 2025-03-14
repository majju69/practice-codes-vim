#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll dp[300001][11];

ll solve(ll i,ll k,vector<ll> &a)
{
	if(i>=(ll)a.size())
	{
		return 0;
	}
	if(dp[i][k]!=-1)
	{
		return dp[i][k];
	}
	ll ans=1e18,mn=1e18;
	for(int j=i;j<=min(i+k,(ll)a.size()-1);++j)
	{
		mn=min(mn,a[j]);
		ans=min(ans,solve(j+1,k+i-j,a)+(j-i+1)*mn);
	}
	return dp[i][k]=ans;
}

ll minSum(vector<ll> &a,ll k)
{
	ll n=a.size();
	for(ll i=0;i<=n;++i)
	{
		for(ll j=0;j<=k;++j)
		{
			dp[i][j]=-1;
		}
	}
	return solve(0,k,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,k;
		cin>>n>>k;
		vector<ll> a(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		cout<<minSum(a,k)<<'\n';
	}
	return 0;
}
