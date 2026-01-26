#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

void dfs(ll node,ll val,vector<ll> &pos,vector<pair<ll,ll>> adj[],bool &ok)
{
    if(pos[node]==1e18)
    {
        pos[node]=val;
    }
    else
    {
        if(pos[node]!=val)
        {
            ok=0;
            return;
        }
    }
    for(auto &v:adj[node])
    {
        if(pos[v.first]!=val+v.second)
        {
            dfs(v.first,val+v.second,pos,adj,ok);
        }
    }
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
        ll n,m;
        bool ok=1;
        cin>>n>>m;
        vector<pair<ll,ll>> adj[n];
        vector<ll> pos(n,1e18);
        for(ll i=0;i<m;++i)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            u--;
            v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,-w});
        }
        for(ll i=0;i<n;++i)
        {
            if(pos[i]==1e18)
            {
                dfs(i,0,pos,adj,ok);
            }
        }
        if(ok)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
