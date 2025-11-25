#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

ll minCost(vector<ll> &a,vector<ll> &c)
{
    ll n=a.size();
    if(n==1)
    {
        return 0;
    }
    ll ind=0;
    map<ll,ll> mp;
    for(auto &v:a)
    {
        mp[v]=0;
    }
    for(auto &v:mp)
    {
        v.second=ind++;
    }
    for(auto &v:a)
    {
        v=mp[v];
    }
    vector<ll> dp(ind+1,c[0]);
    dp[a[0]]=0;
    for(ll i=1;i<n;++i)
    {
        vector<ll> ndp(ind+1,1e18);
        ll mn=1e18;
        for(ll j=0;j<ind;++j)
        {
            mn=min(mn,dp[j]);
            if(j==a[i])
            {
                ndp[j]=mn;
            }
            else
            {
                ndp[j]=mn+c[i];
            }
        }
        dp=ndp;
    }
    return *min_element(dp.begin(),dp.end());
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
        ll n;
        cin>>n;
        vector<ll> a(n),c(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        for(auto &v:c)
        {
            cin>>v;
        }
        cout<<minCost(a,c)<<'\n';
    }
    return 0;
}
