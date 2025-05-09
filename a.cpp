#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int get(long long n,int x)
{
	int ans=0;
	while(n%x==0)
	{
		ans++;
		n/=x;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,mx=0,ans=0;
	vector<int> two,five;
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		long long x;
		int f=0,t=0;
		cin>>x;
		f=get(x,5);
		t=get(x,2);
		mx+=f;
		two.push_back(t);
		five.push_back(f);
	}
	vector<vector<int>> dp(k+1,vector<int>(mx+1,-1e9));
	dp[0][0]=0;
	dp[1][five[0]]=two[0];
	for(int i1=1;i1<n;++i1)
	{
		vector<vector<int>> ndp=dp;
		for(int i2=1;i2<=k;++i2)
		{
			for(int i3=five[i1];i3<=mx;++i3)
			{
				ndp[i2][i3]=max(ndp[i2][i3],dp[i2-1][i3-five[i1]]+two[i1]);
			}
		}
		dp=ndp;
	}
	for(int i=0;i<=mx;++i)
	{
		ans=max(ans,min(dp[k][i],i));
	}
	cout<<ans<<'\n';
	return 0;
}
