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
    return a.second<b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,src,ans=0;
    set<pair<ll,ll>> st;
    map<pair<ll,ll>,pair<ll,ll>> mp;
    cin>>n>>m;
    vector<ll> dist(n,1e18),par(n,-1),edges;
    vector<pair<ll,ll>> adj[n];
    for(ll i=0;i<m;++i)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        if(u>v)
        {
            swap(u,v);
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        mp[{u,v}]={i+1,w};
    }
    cin>>src;
    src--;
    dist[src]=0;
    st.insert({dist[src],src});
    while(!st.empty())
    {
        auto it=st.begin();
        ll node=it->second,dis=it->first;
        st.erase(*it);
        for(auto &v:adj[node])
        {
            ll curNode=v.first,curDist=v.second;
            if(dist[curNode]>dis+curDist)
            {
                if(dist[curNode]!=(ll)1e18)
                {
                    st.erase({dist[curNode],curNode});
                }
                dist[curNode]=dis+curDist;
                st.insert({dist[curNode],curNode});
                par[curNode]=node;
            }
            else
            {
                if(dist[curNode]==dis+curDist)
                {
                    ll u=curNode,v=par[curNode];
                    if(v!=-1)
                    {
                        if(u>v)
                        {
                            swap(u,v);
                        }
                        if(curDist<mp[{u,v}].second)
                        {
                            par[curNode]=node;
                        }
                    }
                }
            }
        }
    }
    for(ll i=0;i<n;++i)
    {
        if(par[i]!=-1)
        {
            ll u=i,v=par[i];
            if(u>v)
            {
                swap(u,v);
            }
            pair<ll,ll> p=mp[{u,v}];
            edges.push_back(p.first);
            ans+=p.second;
        }
    }
    cout<<ans<<'\n';
    for(auto &v:edges)
    {
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
