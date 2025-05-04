#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll dp[100001][17];

ll solve(ll i,ll cur,string &s,vector<ll> &a)
{
	if(i>=(ll)s.size())
	{
		if(cur&1)
		{
			return 1e18;
		}
		return 0;
	}
	if(dp[i][cur]!=-1)
	{
		return dp[i][cur];
	}
	if(s[i]=='h')
	{
		ll keep=solve(i+1,(cur|8),s,a),remove=solve(i+1,cur,s,a)+a[i];
		return dp[i][cur]=min(keep,remove);
	}
	if(s[i]=='a')
	{
		if(cur&8)
		{
			ll keep=solve(i+1,(cur|4),s,a),remove=solve(i+1,cur,s,a)+a[i];
			return dp[i][cur]=min(keep,remove);
		}
		return dp[i][cur]=solve(i+1,cur,s,a);
	}
	if(s[i]=='r')
	{
		if(cur&4)
		{
			ll keep=solve(i+1,(cur|2),s,a),remove=solve(i+1,cur,s,a)+a[i];
			return dp[i][cur]=min(keep,remove);
		}
		return dp[i][cur]=solve(i+1,cur,s,a);
	}
	if(s[i]=='d')
	{
		if(cur&2)
		{
			ll keep=solve(i+1,(cur|1),s,a),remove=solve(i+1,cur,s,a)+a[i];
			return dp[i][cur]=min(keep,remove);
		}
		return dp[i][cur]=solve(i+1,cur,s,a);
	}
	return dp[i][cur]=solve(i+1,cur,s,a);
}

ll minAmbiguity(string &s,vector<ll> &a)
{
	ll n=a.size();
	for(ll i=0;i<=n;++i)
	{
		for(ll j=0;j<17;++j)
		{
			dp[i][j]=-1;
		}
	}
	return solve(0,0,s,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	string s;
	cin>>n>>s;
	vector<ll> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	cout<<minAmbiguity(s,a)<<'\n';
	return 0;
}
