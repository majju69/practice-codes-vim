#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int mod=1e9+7;

inline int add(int a,int b)
{
	return (a%mod+b%mod)%mod;
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
	int n;
	cin>>n;
	vector<vector<int>> a(n,vector<int>(n,0));
	vector<int> dp((1<<n),0);
	dp[0]=1;
	for(auto &vec:a)
	{
		for(auto &v:vec)
		{
			cin>>v;
		}
	}
	for(int i=0;i<n;++i)
	{
		vector<int> ndp=dp;
		for(int j=0;j<n;++j)
		{
			if(a[i][j]==1)
			{
				for(int mask=0;mask<(1<<n);++mask)
				{
					if(!bit(mask,j))
					{
						ndp[mask^(1<<j)]=add(ndp[mask^(1<<j)],dp[mask]);
					}
				}
			}
		}
		dp=ndp;
	}
	cout<<dp.back()<<'\n';
	return 0;
}
