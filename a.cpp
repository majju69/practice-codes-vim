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
    ll n,k,ans=0,cnt=0;
    map<ll,ll> mp;
    cin>>n>>k;
    vector<pair<ll,ll>> a(n);   //{beauty,length}
    for(ll i=0;i<n;++i)
    {
        cin>>a[i].second>>a[i].first;
    }
    sort(a.rbegin(),a.rend());
    for(ll i=0;i<k;++i)
    {
        cnt+=a[i].second;
        ans=max(ans,cnt*a[i].first);
        mp[a[i].second]++;
    }
    for(ll i=k;i<n;++i)
    {
        ll x=(*mp.begin()).first;
        if(a[i].second>x)
        {
            mp[x]--;
            mp[a[i].second]++;
            cnt-=x;
            cnt+=a[i].second;
            if(mp[x]==0)
            {
                mp.erase(x);
            }
            ans=max(ans,cnt*a[i].first);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
