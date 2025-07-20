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
    ll n;
    map<ll,deque<ll>> mp;
    cin>>n;
    vector<ll> a(n);
    vector<string> adjMat(n);
    DisjointSet ds(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    for(auto &v:adjMat)
    {
        cin>>v;
    }
    for(ll i=0;i<n-1;++i)
    {
        for(ll j=i+1;j<n;++j)
        {
            if(adjMat[i][j]=='1')
            {
                ds.unionByRank(i,j);
            }
        }
    }
    for(ll i=0;i<n;++i)
    {
        mp[ds.findUltimateParent(i)].push_back(a[i]);
    }
    for(auto &v:mp)
    {
        sort(v.second.begin(),v.second.end());
    }
    for(ll i=0;i<n;++i)
    {
        cout<<mp[ds.findUltimateParent(i)][0]<<' ';
        mp[ds.findUltimateParent(i)].pop_front();
    }
    cout<<'\n';
    return 0;
}
