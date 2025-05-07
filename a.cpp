#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

/*ll dp[200001][3];

ll solve(ll i,bool toAdd,vector<ll> &a)
{
	if(i>=(ll)a.size())
	{
		if(!toAdd)
		{
			return (ll)1e18;
		}
		return 0;
	}
	if(dp[i][toAdd]!=(ll)-1e18)
	{
		return dp[i][toAdd];
	}
	if(toAdd)
	{
		return dp[i][toAdd]=solve(i+2,0,a)+a[i];
	}
	return dp[i][toAdd]=min(solve(i+1,0,a),solve(i+1,1,a)-a[i]);
}

ll minDiversity(vector<ll> &a)
{
	ll n=a.size();
	sort(a.rbegin(),a.rend());
	for(ll i=0;i<=n;++i)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=(ll)-1e18;
	}
	return solve(0,1,a);
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,pvs_idx=0,cur_idx=3,cur=1;
	cin>>n;
	vector<pair<ll,ll>> a(n);
	vector<vector<ll>> dp(n+2,vector<ll>(2,0));
	vector<ll> ans(n,1);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].first;;
		a[i].second=i;
	}
	sort(a.rbegin(),a.rend());
	dp[n][0]=1e18;
	dp[n+1][0]=1e18;
	for(ll i=n-1;i>=0;--i)
	{
		dp[i][1]=dp[i+2][0]+a[i].first;
		dp[i][0]=min(dp[i+1][0],dp[i+1][1]-a[i].first);
	}
	while(cur_idx<n)
	{
		if(a[cur_idx-1].first-a[pvs_idx].first+dp[pvs_idx][1]==dp[cur_idx][1])
		{
			cur++;
			ans[a[cur_idx].second]=cur;
			ans[a[cur_idx+1].second]=cur;
			ans[a[cur_idx+2].second]=cur;
			pvs_idx=cur_idx;
			cur_idx+=3;
		}
		else
		{
			ans[a[cur_idx].second]=cur;
			cur_idx++;
		}
	}
	cout<<dp[0][1]<<' '<<cur<<'\n';
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
