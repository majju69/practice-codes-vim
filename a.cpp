#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;
typedef long double ld;

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
    ll n;
    cin>>n;
    vector<vector<ld>> p(n,vector<ld>(n));
    vector<ld> dp((1LL<<n),0.0);
    for(auto &vec:p)
    {
        for(auto &v:vec)
        {
            cin>>v;
        }
    }
    dp[(1LL<<n)-1]=1.0;
    for(ll mask=(1LL<<n)-1;mask>0;--mask)
    {
        if(__builtin_popcountll(mask)==1)
        {
            continue;
        }
        for(ll i=0;i<n;++i)
        {
            if(!isSetBit(mask,i))
            {
                continue;
            }
            ll cnt=__builtin_popcountll(mask);
            for(ll j=0;j<n;++j)
            {
                if(!isSetBit(mask,j)||i==j)
                {
                    continue;
                }
                dp[switchBit(mask,i)]+=1.0*p[j][i]*dp[mask]/(cnt*(cnt-1));
                dp[switchBit(mask,j)]+=1.0*p[i][j]*dp[mask]/(cnt*(cnt-1));
            }
        }
    }
    for(ll i=0;i<n;++i)
    {
        cout<<fixed<<setprecision(10)<<dp[(1LL<<i)]<<' ';
    }
    cout<<'\n';
    return 0;
}
