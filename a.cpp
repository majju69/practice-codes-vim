#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[201][201][201];

int solve(int one,int two,int three)
{
	if(one==0&&two==0&&three==0)
	{
		return 0;
	}
	if(dp[one][two][three]!=-1)
	{
		return dp[one][two][three];
	}
	int ans=0,cur=((((one&1)?1:0)^((two&1)?2:0)^((three&1)?3:0))==0);
	if(one>=1)
	{
		ans=max(ans,solve(one-1,two,three)+cur);
	}
	if(two>=1)
	{
		ans=max(ans,solve(one,two-1,three)+cur);
	}
	if(three>=1)
	{
		ans=max(ans,solve(one,two,three-1)+cur);
	}
	return dp[one][two][three]=ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	int tc;
	cin>>tc;
	while(tc--)
	{
		int one,two,three,four;
		cin>>one>>two>>three>>four;
		cout<<solve(one,two,three)+four/2<<'\n';
	}
	return 0;
}
