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
    int r,n;
    cin>>r>>n;
    array<int,3> a[n];
    int dp[n],pre[n];
    memset(dp,0xc0,sizeof(dp));
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        int mx=-1e9;
        if(i>=2*r)
        {
            mx=max(mx,pre[i-2*r]);
        }
        for(int j=max(0,i-2*r+1);j<i;++j)
        {
            if(a[i][0]-a[j][0]>=abs(a[i][1]-a[j][1])+abs(a[i][2]-a[j][2]))
            {
                mx=max(mx,dp[j]);
            }
        }
        dp[i]=mx+1;
        if(a[i][0]>=a[i][1]+a[i][2]-2)
        {
            dp[i]=max(dp[i],1);
        }
        pre[i]=dp[i];
        if(i>0)
        {
            pre[i]=max(pre[i],pre[i-1]);
        }
    }
    cout<<max(pre[n-1],0)<<'\n';
    return 0;
}
