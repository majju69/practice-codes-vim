#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll dp[61][61][61];

ll solve(ll i,ll x,ll y)
{
	if(x==0&&y==0)
	{
		return 0;
	}
	if(i>=60)
	{
		return 1e18;
	}
	if(dp[i][x][y]!=-1)
	{
		return dp[i][x][y];
	}
	ll skip=solve(i+1,x,y),take_x=1e18,take_y=1e18;
	if(i<=x)
	{
		take_x=solve(i+1,x-i,y)+(1LL<<i);
	}
	if(i<=y)
	{
		take_y=solve(i+1,x,y-i)+(1LL<<i);
	}
	return dp[i][x][y]=min({skip,take_x,take_y});
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll x,y,ans=1e18;
		cin>>x>>y;
		for(ll i=0;i<60;++i)
		{
			for(ll j=0;j<60;++j)
			{
				if((x>>i)==(y>>j))
				{
					ans=min(ans,solve(0,i,j));
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
