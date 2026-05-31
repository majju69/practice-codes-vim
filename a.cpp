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
    ll n,t,mn=1e18,ans=0;
    cin>>n>>t;
    vector<ll> a(n);
    for(auto &v:a)
    {
        cin>>v;
        mn=min(mn,v);
    }
    while(t>=mn)
    {
        ll cur=t,sum=0,cnt=0;
        for(auto &v:a)
        {
            if(v<=cur)
            {
                cur-=v;
                sum+=v;
                cnt++;
            }
        }
        ans+=(t/sum)*cnt;
        t%=sum;
    }
    cout<<ans<<'\n';
    return 0;
}
