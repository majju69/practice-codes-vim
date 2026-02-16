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
    int n,k,mn=0,mx=0;
    cin>>n>>k;
    vector<int> value(n),cost(n);
    for(auto &v:value)
    {
        cin>>v;
    }
    for(int i=0;i<n;++i)
    {
        cin>>cost[i];
        cost[i]=value[i]-k*cost[i];
        if(cost[i]<0)
        {
            mn+=cost[i];
        }
        else
        {
            mx+=cost[i];
        }
    }
    vector<int> dp(mx-mn+1,-1e9),ndp(mx-mn+1,-1e9);
    dp[-mn]=0;
    for(int i=0;i<n;++i)
    {
        ndp=dp;
        for(int sum=mn;sum<=mx;++sum)
        {
            if(sum-cost[i]-mn>=0&&sum-cost[i]<=mx)
            {
                ndp[sum-mn]=max(ndp[sum-mn],dp[sum-cost[i]-mn]+value[i]);
            }
        }
        dp=ndp;
    }
    if(dp[-mn]<=0||dp[-mn]>accumulate(value.begin(),value.end(),0))
    {
        dp[-mn]=-1;
    }
    cout<<dp[-mn]<<'\n';
    return 0;
}
