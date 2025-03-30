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
	int n,k;
	cin>>n>>k;
	vector<int> a(n),ans;
	vector<vector<bool>> dp(k+1,vector<bool>(k+1,0));
	for(auto &v:a)
	{
		cin>>v;
	}
	dp[0][0]=1;
	for(int i=0;i<n;++i)
	{
		vector<vector<bool>> ndp=dp;
		for(int x=0;x<=k;++x)
		{
			for(int y=0;y<=k;++y)
			{
				if(x>=a[i]&&dp[x-a[i]][y])
				{
					ndp[x][y]=1;
				}
				if(y>=a[i]&&dp[x][y-a[i]])
				{
					ndp[x][y]=1;
				}
			}
		}
		dp=ndp;
	}
	for(int i=0;i<=k/2;++i)
	{
		int x=i,y=k-i;
		if(dp[x][y])
		{
			ans.push_back(x);
			if(x!=y)
			{
				ans.push_back(y);
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout<<(int)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
