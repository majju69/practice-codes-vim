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
        int n,k,ans=1e9;
        cin>>n>>k;
        vector<int> a(n+1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9));
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;++i)
        {
            a[i]=i-a[i];
        }
        dp[1][0]=(a[1]==0);
        dp[1][1]=0;
        for(int i=2;i<=n;++i)
        {
            dp[i][0]=max(dp[i-1][0]+(a[i]==0),(int)(a[i]==0));
            dp[i][i]=0;
            for(int j=1;j<i;++j)
            {
                dp[i][j]=max({dp[i-1][j]+(a[i]==j),(int)(a[i]==j),dp[i-1][j-1]});
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
            {
                if(dp[i][j]>=k)
                {
                    ans=min(ans,j);
                }
            }
        }
        if(ans>n)
        {
            ans=-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
