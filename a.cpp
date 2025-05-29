#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll dp[20][3][5];

ll solve(int idx,bool last,int cnt,string &s)
{
	if(idx>=(int)s.size())
	{
		return 1;
	}
	if(dp[idx][last][cnt]!=-1)
	{
		return dp[idx][last][cnt];
	}
	int till=(last?(s[idx]-'0'):9);
	ll ans=0;
	for(int i=0;i<=till;++i)
	{
		if(i==0)
		{
			ans+=solve(idx+1,(last&&i==till),cnt,s);
		}
		else
		{
			if(cnt<3)
			{
				ans+=solve(idx+1,(last&&i==till),cnt+1,s);
			}
		}
	}
	return dp[idx][last][cnt]=ans;
}

ll countNumbers(ll n)
{
	string s=to_string(n);
	memset(dp,-1,sizeof(dp));
	return solve(0,1,0,s);
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
		ll l,r;
		cin>>l>>r;
		cout<<countNumbers(r)-countNumbers(l-1)<<'\n';
	}
	return 0;
}
