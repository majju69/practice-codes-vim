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
        ll a,b,ans=0;
        cin>>a>>b;
        for(ll i=1;i<32000;++i)
        {
            ll l=i+2,r=min(a/i,b+1);
            ans+=max(0LL,r-l+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
