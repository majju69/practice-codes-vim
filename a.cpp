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
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
    ll n,k,ans=0;
    map<ll,ll> mp1,mp2,mp3;
    cin>>n>>k;
    for(ll i=0;i<n;++i)
    {
        ll x;
        cin>>x;
        mp1[x]++;
        if(x%k==0)
        {
            if(mp1.find(x/k)!=mp1.end())
            {
                mp2[x]+=mp1[x/k];
            }
            if(mp2.find(x/k)!=mp2.end())
            {
                mp3[x]+=mp2[x/k];
            }
        }
    }
    if(k!=1)
    {
        for(auto &v:mp3)
        {
            if(v.first!=0)
            {
                ans+=v.second;
            }
        }
        for(auto &v:mp1)
        {
            if(v.first==0)
            {
                ll x=v.second;
                ans+=(x*(x-1)*(x-2)/6);
            }
        }
    }
    else
    {
        for(auto &v:mp1)
        {
            ll x=v.second;
            ans+=(x*(x-1)*(x-2)/6);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
