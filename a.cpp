#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline long long get(int n)
{
	return 1ll*n*(n-1)/2;
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
		int n;
		long long m,ans=0;
		cin>>n>>m;
		vector<long long> cnt(n+1,0),dp(n+1,0);
		for(int i=1;i<=n;++i)
		{
			cnt[i]=get(n/i);
		}
		for(int i=n;i>=1;--i)
		{
			if(cnt[i]==0)
			{
				continue;
			}
			dp[i]=cnt[i];
			for(int j=2*i;j<=n;j+=i)
			{
				dp[i]-=dp[j];
			}
		}
		for(int i=n;i>=2;--i)
		{
			int cost=i,batchSize=i-1;
			long long reqBatches=m/batchSize,maxBatches=dp[i]/batchSize;
			if(reqBatches<=maxBatches)
			{
				long long takenBatches=reqBatches;
				ans+=takenBatches*cost;
				m-=takenBatches*batchSize;
			}
			else
			{
				long long takenBatches=maxBatches;
				ans+=takenBatches*cost;
				m-=takenBatches*batchSize;
			}
		}
		if(m>0)
		{
			ans=-1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
