#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll N=2e5+10;
ll a[N],sub[N],cost[N],dist[N];
vector<ll> adj[N];

void dfs(ll node,ll p)
{
    sub[node]=a[node];
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            dist[v]=dist[node]+1;
            dfs(v,node);
            sub[node]+=sub[v];
        }
    }
}

void dfs(ll node,ll p,ll sum)
{
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            ll s=sub[v];
            cost[v]=cost[node]+sum-(s<<1);
            dfs(v,node,sum);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,sum=0;
    cin>>n;
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(ll i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    for(ll i=1;i<n;++i)
    {
        cost[0]+=a[i]*dist[i];
    }
    dfs(0,-1,sum);
    cout<<(*max_element(cost,cost+n))<<'\n';
    return 0;
}
