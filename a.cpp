#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll N=1e5+10;
ll a[N],par[N],subSum[N],subSize[N];
vector<ll> adj[N];
multiset<array<ll,3>> st[N];

void dfs(ll node,ll p)
{
    subSize[node]=1;
    subSum[node]=a[node];
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            par[v]=node;
            dfs(v,node);
            subSize[node]+=subSize[v];
            subSum[node]+=subSum[v];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;++i)
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
        st[par[i]].insert({-subSize[i],i,subSum[i]});
    }
    while(m--)
    {
        ll t,x;
        cin>>t>>x;
        x--;
        if(t==1)
        {
            cout<<subSum[x]<<'\n';
        }
        else
        {
            if(!st[x].empty())
            {
                auto it=st[x].begin();
                array<ll,3> son=*it;
                st[x].erase(it);
                ll f=par[x],s=son[1];
                st[f].erase(st[f].find({-subSize[x],x,subSum[x]}));
                st[f].insert({-subSize[x],s,subSum[x]});
                par[s]=f;
                par[x]=s;
                ll old_x_sz=subSize[x],old_x_sum=subSum[x],old_s_sz=subSize[s],old_s_sum=subSum[s];
                subSize[x]-=old_s_sz;
                subSum[x]-=old_s_sum;
                subSum[s]+=subSum[x];
                subSize[s]+=subSize[x];
                st[s].insert({-subSize[x],x,subSum[x]});
            }
        }
    }
    return 0;
}
