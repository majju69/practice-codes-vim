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
        ll n,m,q;
        vector<pair<ll,bool>> a;
        cin>>n>>m>>q;
        vector<ll> a1(n+m),a2(n+m),pre(n+m),pre_a(n+m),pre_b(n+m);
        for(ll i=0;i<n;++i)
        {
            ll x;
            cin>>x;
            a.push_back({x,0});
        }
        for(ll i=0;i<m;++i)
        {
            ll x;
            cin>>x;
            a.push_back({x,1});
        }
        sort(a.rbegin(),a.rend());
        a1[0]=!a[0].second;
        a2[0]=a[0].second;
        pre[0]=a[0].first;
        pre_a[0]=(!a[0].second*a[0].first);
        pre_b[0]=(a[0].second*a[0].first);
        for(ll i=1;i<n+m;++i)
        {
            a1[i]=a1[i-1]+!a[i].second;
            a2[i]=a2[i-1]+a[i].second;
            pre[i]=pre[i-1]+a[i].first;
            pre_a[i]=pre_a[i-1]+(!a[i].second*a[i].first);
            pre_b[i]=pre_b[i-1]+(a[i].second*a[i].first);
        }
        while(q--)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            ll ub_x=upper_bound(a1.begin(),a1.end(),x)-a1.begin()-1,ub_y=upper_bound(a2.begin(),a2.end(),y)-a2.begin()-1;
            if(z==0)
            {
                cout<<0<<'\n';
                continue;
            }
            if(x==0)
            {
                if(y==0)
                {
                    cout<<0<<'\n';
                }
                else
                {
                    ll req=z,ans=0;
                    ll idx=lower_bound(a2.begin(),a2.end(),req)-a2.begin();
                    ans+=pre_b[idx];
                    cout<<ans<<'\n';
                }
                continue;
            }
            if(y==0)
            {
                if(x==0)
                {
                    cout<<0<<'\n';
                }
                else
                {
                    ll req=z,ans=0;
                    ll idx=lower_bound(a1.begin(),a1.end(),req)-a1.begin();
                    ans+=pre_a[idx];
                    cout<<ans<<'\n';
                }
                continue;
            }
            if(z<=min(ub_x,ub_y)+1)
            {
                cout<<pre[z-1]<<'\n';
            }
            else
            {
                if(ub_x<ub_y)
                {
                    ll ans=pre[ub_x],req=z-ub_x-1;
                    // in a2, from ub_x+1,...,n+m-1, find the 1st idx >= req
                    // a2[idx]-a2[ub_x] >= req => a2[idx]>=req+a2[ub_x]
                    ll idx=lower_bound(a2.begin(),a2.end(),req+a2[ub_x])-a2.begin();
                    ans+=pre_b[idx]-pre_b[ub_x];
                    cout<<ans<<'\n';
                }
                else
                {
                    ll ans=pre[ub_y],req=z-ub_y-1;
                    // in a1, from ub_y+1,...,n+m-1, find the 1st idx >= req
                    // a1[idx]-a1[ub_y] >= req => a1[idx]>=req+a1[ub_y]
                    ll idx=lower_bound(a1.begin(),a1.end(),req+a1[ub_y])-a1.begin();
                    ans+=pre_a[idx]-pre_a[ub_y];
                    cout<<ans<<'\n';
                }
            }
        }
    }
    return 0;
}
