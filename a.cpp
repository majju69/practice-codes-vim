#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<int> get(vector<int> &a,int k)
{
	int n=a.size();
	vector<int> ans(k,-1e9);
	vector<vector<int>> dp(n/2+1,vector<int>(k,-1e9));
	dp[0][0]=0;
	dp[1][a[0]%k]=a[0];
	for(int i1=0;i1<n-1;++i1)
	{
		vector<vector<int>> ndp=dp;
		for(int i2=1;i2<=n/2;++i2)
		{
			for(int i3=0;i3<k;++i3)
			{
				ndp[i2][i3]=max({ndp[i2][i3],dp[i2][i3],dp[i2-1][((i3-a[i1+1])%k+k)%k]+a[i1+1]});
			}
		}
		dp=ndp;
	}
	for(int i=0;i<k;++i)
	{
		for(int j=0;j<=n/2;++j)
		{
			ans[i]=max(ans[i],dp[j][i]);
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> a(n,vector<int>(m,0));
	for(auto &vec:a)
	{
		for(auto &v:vec)
		{
			cin>>v;
		}
	}
	if(m==1)
	{
		cout<<0<<'\n';
	}
	else
	{
		vector<vector<int>> mxSum;
		vector<int> dp(k,0);
		for(int i=0;i<n;++i)
		{
			mxSum.push_back(get(a[i],k));
		}
		dp=mxSum[0];
		for(int i1=0;i1<n-1;++i1)
		{
			vector<int> ndp=dp;
			for(int i2=0;i2<k;++i2)
			{
				for(int i3=0;i3<k;++i3)
				{
					ndp[i2]=max({ndp[i2],dp[i2],dp[((i2-i3)%k+k)%k]+mxSum[i1+1][i3]});
				}
			}
			dp=ndp;
		}
		cout<<dp[0]<<'\n';
	}
	return 0;
}
