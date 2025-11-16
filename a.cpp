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
    ll n,m,k,lo=1,hi=0,ans=-1;
    cin>>n>>m>>k;
    hi=n*m;
    while(lo<=hi)
    {
        ll mid=lo+((hi-lo)>>1);
        ll cnt=0;
        for(ll i=1;i<=n;++i)
        {
            cnt+=min(mid/i,m);
        }
        if(cnt>=k)
        {
            ans=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
