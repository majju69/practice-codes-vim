#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,k,x,ans=0;
        cin>>n>>k>>x;
        ll dp[k+1],ndp[k+1];
        memset(dp,0xc0,sizeof(dp));
        dp[0]=0;
        for(ll i=0;i<n;++i)
        {
            ll cur;
            cin>>cur;
            ndp[0]=max(dp[0]+cur-x,cur-x);
            for(ll j=1;j<=k;++j)
            {
                ndp[j]=max(dp[j]+cur-x,dp[j-1]+cur+x);
                if(dp[j]>=(ll)-2e14)
                {
                    ndp[j]=max(ndp[j],cur-x);
                }
                if(dp[j-1]>=(ll)-2e14)
                {
                    ndp[j]=max(ndp[j],cur+x);
                }
            }
            memcpy(dp,ndp,sizeof(dp));
            for(ll j=0;j<=k;++j)
            {
                if(j+n-i-1>=k)
                {
                    ans=max(ans,dp[j]);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
