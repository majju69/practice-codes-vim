#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

inline ll add(ll a,ll b)
{
	return (a%mod+b%mod)%mod;
}

ll dp[1001][2001][5];

ll solve(ll i,ll k,ll pvs,ll n)
{
	if(i>=n)
	{
		return (k==0);
	}
	if(dp[i][k][pvs]!=-1)
	{
		return dp[i][k][pvs];
	}
	ll ans=0;
	for(int j=0;j<4;++j)
	{
		if(pvs==0||pvs==3)
		{
			if(pvs==j)
			{
				ans=add(ans,solve(i+1,k,j,n));
			}
			else
			{
				if(k>=1)
				{
					ans=add(ans,solve(i+1,k-1,j,n));
				}
			}
		}
		else
		{
			if(pvs+j==3)
			{
				if(k>=2)
				{
					ans=add(ans,solve(i+1,k-2,j,n));
				}
			}
			else
			{
				ans=add(ans,solve(i+1,k,j,n));
			}
		}
	}
	return dp[i][k][pvs]=ans;
}

ll countColourings(ll k,ll n)
{
	for(ll i=0;i<=n;++i)
	{
		for(ll j=0;j<=k;++j)
		{
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i][j][3]=dp[i][j][4]=-1;
		}
	}
	ll ans=0;
	ans=add(ans,solve(1,k-1,0,n));
	ans=add(ans,solve(1,k-1,3,n));
	if(k>=2)
	{
		ans=add(ans,solve(1,k-2,2,n));
		ans=add(ans,solve(1,k-2,1,n));
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	cout<<countColourings(k,n)<<'\n';
	return 0;
}
