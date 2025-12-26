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
        int n;
        cin>>n;
        vector<int> a(n),dp={1,0,(int)-1e9},ndp;
        for(auto &v:a)
        {
            cin>>v;
        }
        for(int i=1;i<n;++i)
        {
            ndp=dp;
            ndp[0]=dp[0]-(dp[0]>a[i])+(dp[0]<a[i]);
            ndp[1]=max(dp[0],dp[1]);
            ndp[2]=max(dp[2]-(dp[2]>a[i])+(dp[2]<a[i]),dp[1]-(dp[1]>a[i])+(dp[1]<a[i]));
            dp=ndp;
        }
        cout<<max(dp[1],dp[2])<<'\n';
    }
    return 0;
}
