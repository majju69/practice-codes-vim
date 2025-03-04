#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[201][201][201];

int solve(int i,int j,int k,vector<int> &red,vector<int> &green,vector<int> &blue)
{
	if(i>=(int)red.size()&&j>=(int)green.size()&&k>=(int)blue.size())
	{
		return 0;
	}
	if(dp[i][j][k]!=-1)
	{
		return dp[i][j][k];
	}
	int ans=0;
	if(i<(int)red.size()&&j<(int)green.size())
	{
		ans=max(ans,red[i]*green[j]+solve(i+1,j+1,k,red,green,blue));
	}
	if(i<(int)red.size()&&k<(int)blue.size())
	{
		ans=max(ans,red[i]*blue[k]+solve(i+1,j,k+1,red,green,blue));
	}
	if(j<(int)green.size()&&k<(int)blue.size())
	{
		ans=max(ans,green[j]*blue[k]+solve(i,j+1,k+1,red,green,blue));
	}
	return dp[i][j][k]=ans;
}

int maxArea(vector<int> &red,vector<int> &green,vector<int> &blue)
{
	int r=red.size(),g=green.size(),b=blue.size();
	sort(red.rbegin(),red.rend());
	sort(green.rbegin(),green.rend());
	sort(blue.rbegin(),blue.rend());
	for(int i=0;i<=r;++i)
	{
		for(int j=0;j<=g;++j)
		{
			for(int k=0;k<=b;++k)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	return solve(0,0,0,red,green,blue);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r,g,b;
	cin>>r>>g>>b;
	vector<int> red(r),green(g),blue(b);
	for(auto &v:red)
	{
		cin>>v;
	}
	for(auto &v:green)
	{
		cin>>v;
	}
	for(auto &v:blue)
	{
		cin>>v;
	}
	cout<<maxArea(red,green,blue)<<'\n';
	return 0;
}
