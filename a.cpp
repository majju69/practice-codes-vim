#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

void dfs(ll node,ll p,vector<ll> adj[],vector<ll> &cum_sum,vector<ll> &a)
{
    if(cum_sum[node]==-1)
    {
        ll mn=1e18;
        for(auto &v:adj[node])
        {
            if(v!=p)
            {
                mn=min(mn,cum_sum[v]);
            }
        }
        if(mn==1e18)
        {
            a[node]=0;
            cum_sum[node]=cum_sum[p];
        }
        else
        {
            a[node]=mn-cum_sum[p];
            cum_sum[node]=mn;
        }
        for(auto &v:adj[node])
        {
            if(v!=p)
            {
                dfs(v,node,adj,cum_sum,a);
            }
        }
    }
    else
    {
        if(node==0)
        {
            a[node]=cum_sum[node];
        }
        else
        {
            a[node]=cum_sum[node]-cum_sum[p];
        }
        for(auto &v:adj[node])
        {
            if(v!=p)
            {
                dfs(v,node,adj,cum_sum,a);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,ans=0;
    cin>>n;
    vector<ll> adj[n],cum_sum(n),a(n);
    for(ll i=1;i<n;++i)
    {
        ll x;
        cin>>x;
        x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for(auto &v:cum_sum)
    {
        cin>>v;
    }
    dfs(0,0,adj,cum_sum,a);
    for(auto &v:a)
    {
        if(v<0)
        {
            ans=-1;
            break;
        }
        ans+=v;
    }
    cout<<ans<<'\n';
    return 0;
}
