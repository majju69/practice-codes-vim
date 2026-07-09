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
    int n,m,k,ans=0;
    string s,t;
    cin>>n>>m>>k>>s>>t;
    int dp[n+1][m+1][k+1][2];
    memset(dp,0xc0,sizeof(dp));
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            dp[i][j][0][0]=0;
        }
    }
    for(int i1=1;i1<=n;++i1)
    {
        for(int i2=1;i2<=m;++i2)
        {
            for(int i3=1;i3<=k;++i3)
            {
                dp[i1][i2][i3][0]=max({dp[i1][i2][i3][0],dp[i1-1][i2][i3][0],dp[i1-1][i2][i3][1],dp[i1][i2-1][i3][0],dp[i1][i2-1][i3][1]});
                if(s[i1-1]==t[i2-1])
                {
                    dp[i1][i2][i3][1]=max({dp[i1][i2][i3][1],dp[i1-1][i2-1][i3-1][0]+1,dp[i1-1][i2-1][i3-1][1]+1,dp[i1-1][i2-1][i3][1]+1});
                }
                if(i3==k)
                {
                    ans=max({ans,dp[i1][i2][i3][0],dp[i1][i2][i3][1]});
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
