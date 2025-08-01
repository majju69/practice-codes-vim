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
    ll n;
    cin>>n;
    vector<vector<vector<ll>>> a(n,vector<vector<ll>>(3));
    vector<vector<ll>> dp(n,vector<ll>(10,-1e18));
    for(ll i=0;i<n;++i)
    {
        ll k;
        cin>>k;
        vector<vector<ll>> tmp(3);
        while(k--)
        {
            ll c,d;
            cin>>c>>d;
            tmp[c-1].push_back(d);
        }
        sort(tmp[0].rbegin(),tmp[0].rend());
        sort(tmp[1].rbegin(),tmp[1].rend());
        sort(tmp[2].rbegin(),tmp[2].rend());
        for(ll j=0;j<min(3LL,(ll)tmp[0].size());++j)
        {
            a[i][0].push_back(tmp[0][j]);
        }
        while((ll)a[i][0].size()<3)
        {
            a[i][0].push_back((ll)-1e18);
        }
        for(ll j=0;j<min(1LL,(ll)tmp[1].size());++j)
        {
            a[i][1].push_back(tmp[1][j]);
        }
        while((ll)a[i][1].size()<1)
        {
            a[i][1].push_back((ll)-1e18);
        }
        for(ll j=0;j<min(1LL,(ll)tmp[2].size());++j)
        {
            a[i][2].push_back(tmp[2][j]);
        }
        while((ll)a[i][2].size()<1)
        {
            a[i][2].push_back((ll)-1e18);
        }
    }
    dp[0][3]=a[0][0][0]+a[0][0][1]+a[0][0][2];
    dp[0][2]=max(a[0][0][0]+a[0][0][1],a[0][1][0]+a[0][0][0]);
    dp[0][1]=max({a[0][0][0],a[0][1][0],a[0][2][0]});
    dp[0][0]=0;
    for(ll i=1;i<n;++i)
    {
        for(ll j=0;j<10;++j)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if((j+7)%10>j)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][(j+7)%10]+a[i][0][0]+a[i][0][1]+a[i][0][2]+max({a[i][0][0],a[i][0][1],a[i][0][2]}));
            }
            else
            {
                dp[i][j]=max(dp[i][j],dp[i-1][(j+7)%10]+a[i][0][0]+a[i][0][1]+a[i][0][2]);
            }
            if((j+8)%10>j)
            {
                dp[i][j]=max({dp[i][j],dp[i-1][(j+8)%10]+a[i][0][0]+a[i][0][1]+max({a[i][0][0],a[i][0][1]}),dp[i-1][(j+8)%10]+a[i][1][0]+a[i][0][0]+max({a[i][1][0],a[i][0][0]})});
            }
            else
            {
                dp[i][j]=max({dp[i][j],dp[i-1][(j+8)%10]+a[i][0][0]+a[i][0][1],dp[i-1][(j+8)%10]+a[i][1][0]+a[i][0][0]});
            }
            if((j+9)%10>j)
            {
                dp[i][j]=max({dp[i][j],dp[i-1][(j+9)%10]+2*a[i][0][0],dp[i-1][(j+9)%10]+2*a[i][1][0],dp[i-1][(j+9)%10]+2*a[i][2][0]});
            }
            else
            {
                dp[i][j]=max({dp[i][j],dp[i-1][(j+9)%10]+a[i][0][0],dp[i-1][(j+9)%10]+a[i][1][0],dp[i-1][(j+9)%10]+a[i][2][0]});
            }
            if(dp[i][j]<0)
            {
                dp[i][j]=-1e18;
            }
        }
    }
    cout<<(*max_element(dp[n-1].begin(),dp[n-1].end()))<<'\n';
    return 0;
}
