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
    int n,x;
    long long ans=0;
    array<long long,3> dp={0,0,(long long)-1e18},ndp;
    cin>>n>>x;
    for(int i=0;i<n;++i)
    {
        int cur;
        cin>>cur;
        ndp[0]=max(dp[0]+cur,1ll*cur);
        ndp[1]=max({1ll*cur*x,dp[0]+1ll*cur*x,dp[1]+1ll*cur*x});
        ndp[2]=max({dp[1]+cur,1ll*cur,dp[2]+cur});
        dp=ndp;
        ans=max({ans,dp[0],dp[1],dp[2]});
    }
    cout<<ans<<'\n';
    return 0;
}
