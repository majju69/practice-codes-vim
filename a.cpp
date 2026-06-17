#include <bits/stdc++.h>
#include <deque>
#include <utility>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

void compress(deque<ll> &dq)
{
    deque<ll> a;
    for(auto &v:dq)
    {
        if(v!=0)
        {
            a.push_back(v);
        }
    }
    dq=a;
    a.clear();
    if(dq.empty())
    {
        return;
    }
    ll sum=dq[0],pvs=dq[0];
    const ll n=dq.size();
    for(ll i=1;i<n;++i)
    {
        if(dq[i]*pvs>0)
        {
            sum+=dq[i];
        }
        else
        {
            a.push_back(sum);
            sum=dq[i];
            pvs=dq[i];
        }
    }
    if(sum!=0)
    {
        a.push_back(sum);
    }
    dq=a;
}

deque<pair<ll,ll>> operate(deque<ll> &dq)
{
    ll sum=0,mn=0;
    deque<pair<ll,ll>> ans;
    for(auto &v:dq)
    {
        sum+=v;
        mn=min(mn,sum);
        if(sum>0)
        {
            ans.push_back({mn,sum});
            mn=0;
            sum=0;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x,k,idx=0;
    priority_queue<array<ll,3>> pq;
    deque<deque<pair<ll,ll>>> a;
    cin>>x>>k;
    while(k--)
    {
        ll l;
        deque<ll> dq;
        deque<pair<ll,ll>> ans;
        cin>>l;
        while(l--)
        {
            ll cur;
            cin>>cur;
            dq.push_back(cur);
        }
        compress(dq);
        ans=operate(dq);
        if(!ans.empty())
        {
            a.push_back(ans);
            pq.push({ans[0].first,ans[0].second,idx++});
        }
    }
    while(!pq.empty())
    {
        array<ll,3> cur=pq.top();
        pq.pop();
        if(x+cur[0]>=0)
        {
            x+=cur[1];
            a[cur[2]].pop_front();
            if(!a[cur[2]].empty())
            {
                pq.push({a[cur[2]][0].first,a[cur[2]][0].second,cur[2]});
            }
        }
        else
        {
            break;
        }
    }
    cout<<x<<'\n';
    return 0;
}
