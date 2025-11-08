#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

inline bool bit(ll a,ll i)
{
    return (a>>i&1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n=0,m,ans=-1;
    string s;
    cin>>s>>m;
    n=s.size();
    vector<ll> mult(n,1),fact(n+1,1),freq(10,0);
    vector<vector<ll>> dp((1<<n),vector<ll>(m,0));
    for(ll i=n-2;i>=0;--i)
    {
        mult[i]=(mult[i+1]*10)%m;
    }
    for(ll i=2;i<=n;++i)
    {
        fact[i]=i*fact[i-1];
    }
    for(ll i=0;i<n;++i)
    {
        freq[s[i]-'0']++;
        if(s[i]!='0')
        {
            dp[(1<<i)][((s[i]-'0')%m*mult[0])%m]=1;
        }
    }
    for(ll mask=2;mask<(1<<n);++mask)
    {
        if(__builtin_popcountll(mask)<2)
        {
            continue;
        }
        ll cnt=__builtin_popcountll(mask);
        for(ll i=0;i<n;++i)
        {
            if(bit(mask,i))
            {
                ll nmask=(mask^(1<<i));
                for(ll j=0;j<m;++j)
                {
                    dp[mask][(j+(s[i]-'0')*mult[cnt-1])%m]+=dp[nmask][j];
                }
            }
        }
    }
    ans=dp[(1<<n)-1][0];
    for(auto &v:freq)
    {
        assert(ans%fact[v]==0);
        ans/=fact[v];
    }
    cout<<ans<<'\n';
    return 0;
}
