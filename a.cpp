#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

inline ll get(ll a,ll i)
{
    return a>>i&1;
}

bool check(vector<ll> &a,ll k,ll bit)
{
    for(auto &v:a)
    {
        if(get(v,bit))
        {
            continue;
        }
        ll x=(v&((1ll<<(bit))-1));
        ll dec=(1ll<<bit)-x;
        k-=dec;
        if(k<0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    const vector<ll> _a=a;
    while(q--)
    {
        ll k,ans=(1ll<<62)-1;
        cin>>k;
        for(ll bit=60;bit>=0;--bit)
        {
            if(check(a,k,bit))
            {
                for(auto &v:a)
                {
                    if(get(v,bit))
                    {
                        continue;
                    }
                    ll new_v=(v^(1ll<<bit));
                    if(bit>0)
                    {
                        new_v&=(((1ll<<62)-1)-((1ll<<bit)-1));
                    }
                    k-=(new_v-v);
                    v=new_v;
                }
            }
        }
        for(auto &v:a)
        {
            ans&=v;
        }
        a=_a;
        cout<<ans<<'\n';
    }
    return 0;
} 
