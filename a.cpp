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
    ll n,maxSum=0;
    cin>>n;
    vector<ll> a(n),idx(n),ans(n),segmentSums(n,0);
    vector<bool> isPresent(n,false);
    DisjointSet ds(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    for(auto &v:idx)
    {
        cin>>v;
        v--;
    }
    for(ll i=n-1;i>=0;--i)
    {
        ans[i]=maxSum;
        ll currentSum=a[idx[i]];
        if(idx[i]>=1)
        {
            if(isPresent[idx[i]-1])
            {
                currentSum+=segmentSums[ds.findUltimateParent(idx[i]-1)];
                ds.unionByRank(idx[i],idx[i]-1);
            }
        }
        if(idx[i]<n-1)
        {
            if(isPresent[idx[i]+1])
            {
                currentSum+=segmentSums[ds.findUltimateParent(idx[i]+1)];
                ds.unionByRank(idx[i],idx[i]+1);
            }
        }
        isPresent[idx[i]]=true;
        segmentSums[ds.findUltimateParent(idx[i])]=currentSum;
        maxSum=max(maxSum,currentSum);
    }
    for(auto &v:ans)
    {
        cout<<v<<'\n';
    }
    return 0;
}
