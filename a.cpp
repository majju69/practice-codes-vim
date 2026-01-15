#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

ll gcd(ll a,ll b)
{
    return ((b==0)?a:gcd(b,a%b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,g=0,ans=0;
    cin>>n;
    vector<ll> a(n),pre(n),suf(n);
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
        g=gcd(g,a[i]);
        pre[i]=g;
    }
    ans=g;
    g=0;
    for(ll i=n-1;i>=0;--i)
    {
        g=gcd(g,a[i]);
        suf[i]=g;
    }
    for(ll i=1;i<n-1;++i)
    {
        ans+=min(pre[i],suf[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
