#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

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
		long long dp[]={0,0,0};
		cin>>n;
		vector<int> a(n),b(n);
		for(int i=0;i<n;++i)
		{
			cin>>a[i]>>b[i];
		}
		dp[1]=b[0];
		dp[2]=2*b[0];
		for(int i=1;i<n;++i)
		{
			long long ndp[]={(long long)2e18,(long long)2e18,(long long)2e18};
			for(int j=0;j<3;++j)
			{
				for(int k=0;k<3;++k)
				{
					if(a[i-1]+k!=a[i]+j)
					{
						ndp[j]=min(ndp[j],dp[k]+j*b[i]);
					}
				}
			}
			memcpy(dp,ndp,sizeof(dp));
		}
		cout<<min({dp[0],dp[1],dp[2]})<<'\n';
	}
	return 0;
}
