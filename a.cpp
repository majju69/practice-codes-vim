#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

inline bool isSetBit(ll a,ll i)
{
    return ((a&(1LL<<i))!=0);
}

inline ll switchBit(ll a,ll i)
{
    return (a^(1LL<<i));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,k,ans=0;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<vector<ll>> dp((1<<n),vector<ll>(n,0)),rules(n,vector<ll>(n,0));
    for(auto &v:a)
    {
        cin>>v;
    }
    for(ll i=0;i<k;++i)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        x--;
        y--;
        rules[x][y]=c;
    }
    for(ll i=0;i<n;++i)
    {
        dp[(1<<i)][i]=a[i];
    }
    for(ll mask=1;mask<(1<<n);++mask)
    {
        if(__builtin_popcount(mask)==1)
        {
            continue;
        }
        for(ll i=0;i<n;++i)
        {
            if(isSetBit(mask,i))
            {
                ll x=switchBit(mask,i),cur=dp[mask][i];
                for(ll j=0;j<n;++j)
                {
                    if(isSetBit(x,j))
                    {
                        cur=max(cur,dp[x][j]+a[i]+rules[j][i]);
                    }
                }
                dp[mask][i]=cur;
            }
        }
    }
    for(ll i=1;i<(1<<n);++i)
    {
        if(__builtin_popcount(i)==m)
        {
            for(ll j=0;j<n;++j)
            {
                if(isSetBit(i,j))
                {
                    ans=max(ans,dp[i][j]);
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
