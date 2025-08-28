#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

inline ll ask(char c,ll k)
{
    cout<<"? "<<c<<' '<<k<<endl;
    ll x;
    cin>>x;
    if(x==-1)
    {
        exit(1);
    }
    return x;
}

inline void reply(ll x,ll y)
{
    cout<<"! "<<x<<' '<<y<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,d1=-1,d2=-1,idx=0,idx1=0;
        cin>>n;
        vector<pair<ll,ll>> a(n);
        for(auto &v:a)
        {
            cin>>v.first>>v.second;
        }
        for(ll i=1;i<n;++i)
        {
            if(-a[i].first+a[i].second>-a[idx].first+a[idx].second)
            {
                idx=i;
            }
            if(a[i].first+a[i].second>a[idx1].first+a[idx1].second)
            {
                idx1=i;
            }
        }
        d1=ask('U',1e9);
        d1=ask('U',1e9);
        d1=ask('L',1e9);
        d1=ask('L',1e9);
        d2=ask('R',1e9);
        d2=ask('R',1e9);
        d2=ask('R',1e9);
        d2=ask('R',1e9);
        d1+=a[idx].second-a[idx].first-4e9;
        d2+=a[idx1].second+a[idx1].first-4e9;
        reply((d2-d1)/2,(d1+d2)/2);
    }
    return 0;
}


