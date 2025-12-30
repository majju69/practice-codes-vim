#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

bool cmp(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first>b.first;
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
        ll n,m,k,ans=0,sum=0;
        multiset<ll> st;
        vector<ll> res;
        cin>>n>>m>>k;
        for(ll i=0;i<m;++i)
        {
            ll x;
            cin>>x;
            st.insert(x);
        }
        vector<pair<ll,ll>> a(n);
        for(auto &v:a)
        {
            ll y;
            cin>>v.second>>y>>v.first;
            k-=y;
            v.first-=y;
        }
        sort(a.begin(),a.end(),cmp);
        for(auto &v:a)
        {
            auto it=st.lower_bound(v.second);
            if(it==st.end())
            {
                res.push_back(v.first);
            }
            else
            {
                ans++;
                st.erase(it);
            }
        }
        sort(res.begin(),res.end());
        for(auto &v:res)
        {
            if(sum+v<=k)
            {
                ans++;
                sum+=v;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
