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
    ll n,h,ans=-1e18;
    vector<ll> cost,value;
    cin>>n>>h;
    vector<pair<ll,ll>> a(n);
    for(auto &v:a)
    {
        cin>>v.first>>v.second;
    }
    for(ll i=0;i<n;++i)
    {
        if(i>0)
        {
            cost.push_back(a[i].first-a[i-1].second);
            value.push_back(a[i].first-a[i-1].second);
        }
        cost.push_back(0);
        value.push_back(a[i].second-a[i].first);
    }
    for(ll i=1;i<(ll)cost.size();++i)
    {
        cost[i]+=cost[i-1];
        value[i]+=value[i-1];
    }
    for(ll i=0;i<(ll)cost.size();++i)
    {
        ll lo=i,hi=(ll)cost.size()-1,idx=-1;
        while(lo<=hi)
        {
            ll mid=lo+((hi-lo)>>1);
            ll cur=cost[mid]-((i==0)?0:cost[i-1]);
            if(cur<h)
            {
                idx=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        if(idx==-1)
        {
            ans=max(ans,h);
        }
        else
        {
            ll totCost=cost[idx]-((i==0)?0:cost[i-1]),totValue=value[idx]-((i==0)?0:value[i-1]);
            ans=max(ans,totValue+(h-totCost));
        }
    }
    cout<<ans<<'\n';
    return 0;
}
