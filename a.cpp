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
        return a.second>b.second;
    }
    return a.first<b.first;
}

ll get(const pair<ll,ll> &a,pair<ll,ll> &b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    array<ll,2> dp={0,0},ndp={(ll)1e18,(ll)1e18};     // ended last at [0/1]
    map<ll,vector<pair<ll,ll>>> mp;
    vector<array<pair<ll,ll>,2>> a={{make_pair(0ll,0ll),make_pair(0ll,0ll)}};
    cin>>n;
    while(n--)
    {
        ll x,y;
        cin>>x>>y;
        mp[max(x,y)].push_back({x,y});
    }
    for(auto &v:mp)
    {
        sort(v.second.begin(),v.second.end(),cmp);
        a.push_back({v.second[0],v.second.back()});
    }
    const ll len=a.size();
    for(ll i=1;i<len;++i)
    {
        ll cost=get(a[i][0],a[i][1]);
        ndp[0]=cost+min(dp[0]+get(a[i-1][0],a[i][1]),dp[1]+get(a[i-1][1],a[i][1]));
        ndp[1]=cost+min(dp[0]+get(a[i-1][0],a[i][0]),dp[1]+get(a[i-1][1],a[i][0]));
        dp=ndp;
    }
    cout<<min(dp[0],dp[1])<<'\n';
    return 0;
}

/*




1,mx 2,mx .... mx,mx mx,mx-1 mx,mx-2 ... mx,1





*/
