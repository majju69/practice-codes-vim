#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

long long power(long long a,long long b)        // Use when mod is of order 10^9 or less
{
    long long ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;       
        b>>=1;
    }
    return ans%mod;
}

ll mergeOverlap(vector<pair<ll,ll>> &a)
{
    ll ans=0;
    sort(a.begin(),a.end());
    for(ll i=1;i<(ll)a.size();++i)
    {
        if(a[ans].second>=a[i].first)
        {
            a[ans].second=max(a[ans].second,a[i].second);
        }           
        else
        {            
            ans++;
            a[ans]=a[i];
        }
    }
    return (ans+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    vector<pair<ll,ll>> a;
    map<ll,pair<ll,ll>> mp;
    cin>>n;
    for(ll i=0;i<n;++i)
    {
        ll x;
        cin>>x;
        if(mp.find(x)==mp.end())
        {
            mp[x]={i,i};
        }
        else
        {
            mp[x].second=i;
        }
    }
    for(auto &v:mp)
    {
        a.push_back(v.second);
    }
    cout<<power(2,mergeOverlap(a)-1)<<'\n';
    return 0;
}
