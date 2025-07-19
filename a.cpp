#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

class DisjointSet
{

private:

    vector<long long> ultimateParent,rank,size;

public:

    DisjointSet(long long n)
    {
        ultimateParent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(long long i=0;i<=n;++i)
        {
            ultimateParent[i]=i;
        }
    }

    long long findUltimateParent(long long node)
    {
        if(ultimateParent[node]==node)
        {
            return node;
        }
        return ultimateParent[node]=findUltimateParent(ultimateParent[node]);
    }

    long long getSize(long long node)
    {
        return size[node];
    }

    long long getRank(long long node)
    {
        return rank[node];
    }

    void unionByRank(long long u,long long v)
    {
        long long ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
        if(ultimateParentOfU==ultimateParentOfV)
        {
            return ;
        }
        if(rank[ultimateParentOfU]<rank[ultimateParentOfV])
        {
            ultimateParent[ultimateParentOfU]=ultimateParentOfV;
        }
        else if(rank[ultimateParentOfU]>rank[ultimateParentOfV])
        {
            ultimateParent[ultimateParentOfV]=ultimateParentOfU;
        }
        else
        {
            ultimateParent[ultimateParentOfV]=ultimateParentOfU;
            rank[ultimateParentOfU]++;
        }
    }

    void unionBySize(long long u,long long v)
    {
        long long ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
        if(ultimateParentOfU==ultimateParentOfV)
        {
            return ;
        }
        if(size[ultimateParentOfU]<size[ultimateParentOfV])
        {
            ultimateParent[ultimateParentOfU]=ultimateParentOfV;
            size[ultimateParentOfV]+=size[ultimateParentOfU];
        }
        else
        {
            ultimateParent[ultimateParentOfV]=ultimateParentOfU;
            size[ultimateParentOfU]+=size[ultimateParentOfV];
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,ans=0;
    vector<pair<ll,pair<ll,ll>>> edges;
    cin>>n>>m;
    DisjointSet ds(n);
    vector<pair<ll,ll>> a(n);
    for(ll i=0;i<n;++i)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    for(ll i=1;i<n;++i)
    {
        edges.push_back({a[0].first+a[i].first,{a[0].second,a[i].second}});
    }
    for(ll i=0;i<m;++i)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    for(auto &edge:edges)
    {
        ll u=edge.second.first,v=edge.second.second,w=edge.first;
        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
        {
            ds.unionByRank(u,v);
            ans+=w;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
