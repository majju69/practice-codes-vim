#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x) 69
#endif

const int mod=1e9+7;

inline int add(int a,int b)
{
	return ((a%mod)+(b%mod))%mod;
}

inline int bit(int a,int i)
{
	return a>>i&1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,t,mx=0;
	cin>>n>>t;
	vector<pair<int,int>> a(n);
	for(auto &v:a)
	{
		cin>>v.first>>v.second;
		mx+=v.first;
		v.second--;
	}
	if(mx>=t)
	{
		int ans=0;
		vector<vector<vector<int>>> dp((1<<n),vector<vector<int>>(t+1,vector<int>(3,0)));
		sort(a.begin(),a.end());
		for(int i=0;i<n;++i)
		{
			if(a[i].first>t)
			{
				break;
			}
			dp[1<<i][a[i].first][a[i].second]=1;
		}
		for(int mask=1;mask<(1<<n);++mask)
		{
			if(__builtin_popcount(mask)!=1)
			{
				for(int i=0;i<n;++i)
				{
					if(bit(mask,i))
					{
						for(int j=0;j<=t;++j)
						{
							if(j+a[i].first>t)
							{
								break;
							}
							if(a[i].second==0)
							{
								dp[mask][j+a[i].first][0]=add(dp[mask][j+a[i].first][0],dp[mask^(1<<i)][j][1]);
								dp[mask][j+a[i].first][0]=add(dp[mask][j+a[i].first][0],dp[mask^(1<<i)][j][2]);
								continue;
							}
							if(a[i].second==1)
							{
								dp[mask][j+a[i].first][1]=add(dp[mask][j+a[i].first][1],dp[mask^(1<<i)][j][0]);
								dp[mask][j+a[i].first][1]=add(dp[mask][j+a[i].first][1],dp[mask^(1<<i)][j][2]);
								continue;
							}
							if(a[i].second==2)
							{
								dp[mask][j+a[i].first][2]=add(dp[mask][j+a[i].first][2],dp[mask^(1<<i)][j][1]);
								dp[mask][j+a[i].first][2]=add(dp[mask][j+a[i].first][2],dp[mask^(1<<i)][j][0]);
								continue;
							}
						}
					}
				}
			}
		}
		for(int mask=1;mask<(1<<n);++mask)
		{
			ans=add(ans,dp[mask][t][0]);
			ans=add(ans,dp[mask][t][1]);
			ans=add(ans,dp[mask][t][2]);
		}
		cout<<ans<<'\n';
	}
	else
	{
		cout<<0<<'\n';
	}
	return 0;
}	
