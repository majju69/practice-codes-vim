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

inline ll sub(ll a,ll b)
{
	return (a%mod-b%mod+mod)%mod;
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
		ll n,m,d_same,d_up=-1,ans=0;
		cin>>n>>m>>d_same;
		d_up+=d_same;
		vector<string> a(n);
		vector<vector<ll>> dp(n,vector<ll>(m,0));
		for(auto &v:a)
		{
			cin>>v;
		}
		for(ll i=0;i<n;++i)
		{
			if(i==0)
			{
				ll s=0;
				vector<ll> pre(m,0);
				for(ll j=0;j<m;++j)
				{
					s+=(a[i][j]=='X');
					pre[j]=s;
				}
				for(ll j=0;j<m;++j)
				{
					if(a[i][j]!='X')
					{
						continue;
					}
					ll lb=max(j-d_same,0LL),ub=min(m-1,j+d_same);
					dp[i][j]=sub(pre[ub],((lb==0)?0LL:pre[lb-1]));
				}
			}
			else
			{
				ll s=0;
				vector<ll> pre_pvs(m,0),pre_cur(m,0);
				for(ll j=0;j<m;++j)
				{
					s=add(s,dp[i-1][j]);
					pre_pvs[j]=s;
				}
				for(ll j=0;j<m;++j)
				{
					if(a[i][j]!='X')
					{
						continue;
					}
					ll lb=max(j-d_up,0LL),ub=min(m-1,j+d_up);
					pre_cur[j]=sub(pre_pvs[ub],((lb==0)?0LL:pre_pvs[lb-1]));
				}
				for(ll j=1;j<m;++j)
				{
					pre_cur[j]=add(pre_cur[j],pre_cur[j-1]);
				}
				for(ll j=0;j<m;++j)
				{
					if(a[i][j]!='X')
					{
						continue;
					}
					ll lb=max(j-d_same,0LL),ub=min(m-1,j+d_same);
					dp[i][j]=sub(pre_cur[ub],((lb==0)?0LL:pre_cur[lb-1]));
				}
			}
		}
		for(ll j=0;j<m;++j)
		{
			if(a[n-1][j]!='X')
			{
				continue;
			}
			ans=add(ans,dp[n-1][j]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
