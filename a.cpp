#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;
typedef long double ld;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll w,b;
	cin>>w>>b;
	ld dp[w+1][b+1][2];
	dp[0][0][0]=0;
	dp[0][0][1]=1;
	for(ll i=1;i<=w;++i)
	{
		dp[i][0][0]=1;
		dp[i][0][1]=1;
	}
	for(ll i=1;i<=b;++i)
	{
		dp[0][i][0]=0;
		dp[0][i][1]=1;
	}
	for(ll i=1;i<=w;++i)
	{
		for(ll j=1;j<=b;++j)
		{
			dp[i][j][1]=(ld)i/(i+j)+((ld)j/(i+j))*((ld)1-dp[i][j-1][0]);
			dp[i][j][0]=(ld)i/(i+j)+((ld)j/(i+j))*((ld)i/(i+j-1)*((ld)1-dp[i-1][j-1][1]));
			if(j>=2)
			{
				dp[i][j][0]+=((ld)j/(i+j))*((ld)(j-1)/(i+j-1)*((ld)1-dp[i][j-2][1]));
			}
		}
	}
	cout<<fixed<<setprecision(9)<<dp[w][b][0]<<'\n';
	return 0;
}


/*


i->white j->black

dp[i][j][chance] = i/(i+j) + (j/(i+j))(1-dp[i][j-1][1-chance])   if chance == dragon (ie 1)
dp[i][j][chance] = i/(i+j) + (j/(i+j))((j-1)/(i+j-1)(1-dp[i][j-2][1-chance]) + i/(i+j-1)(1-dp[i-1][j-1][1-chance])) if chance == princess (ie 0)

*/
