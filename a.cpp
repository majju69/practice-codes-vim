#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll N=2e5+10;
ll sub[N],cost[N],dist[N];
vector<ll> adj[N];

void dfs(ll node,ll p)
{
    sub[node]=1;
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

void dfs(ll node,ll p,ll n)
{
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            ll s=sub[v];
            cost[v]=cost[node]+n-(s<<1);
            dfs(v,node,n);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
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
        cost[0]+=dist[i];
    }
    dfs(0,-1,n);
    for(ll i=0;i<n;++i)
    {
        cout<<cost[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
