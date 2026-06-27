#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2010;
int umbrella[N],dp[N][N];
bool isRain[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(umbrella,-1,sizeof(umbrella));
    memset(dp,0x3f,sizeof(dp));
    int a,n,m,mn=1e9+10,ans=-1;
    cin>>a>>n>>m;
    for(int i=0;i<n;++i)
    {
        int l,r;
        cin>>l>>r;
        for(int j=l;j<r;++j)
        {
            isRain[j]=1;
        }
    }
    for(int i=0;i<m;++i)
    {
        int x,p;
        cin>>x>>p;
        if(umbrella[x+1]==-1)
        {
            umbrella[x+1]=p;
        }
        else
        {
            umbrella[x+1]=min(umbrella[x+1],p);
        }
    }
    if(!isRain[0])
    {
        dp[0][0]=0;
        mn=0;
    }
    if(umbrella[1]!=-1)
    {
        dp[0][1]=umbrella[1];
        mn=min(mn,umbrella[1]);
    }
    for(int i=1;i<a;++i)
    {
        if(!isRain[i])
        {
            dp[i][0]=min(mn,dp[i-1][0]);
        }
        if(umbrella[i+1]!=-1)
        {
            dp[i][i+1]=mn+umbrella[i+1];
        }
        mn=1e9+10;
        for(int j=1;j<=i;++j)
        {
            if(dp[i-1][j]<(int)1e9&&umbrella[j]!=-1)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j]+umbrella[j]);
                mn=min(mn,dp[i][j]);
            }
        }
        mn=min(mn,dp[i][i+1]);
        mn=min(mn,dp[i][0]);
    }
    ans=(*min_element(dp[a-1],dp[a-1]+a+5));
    if(ans>(int)2e8+10)
    {
        ans=-1;
    }
    cout<<ans<<'\n';
    return 0;
}
