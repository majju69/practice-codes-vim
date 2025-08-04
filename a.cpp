#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

class DisjointSet
{

private:

    vector<int> ultimateParent,rank,size;

public:

    DisjointSet(int n)
    {
        ultimateParent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;++i)
        {
            ultimateParent[i]=i;
        }
    }

    int findUltimateParent(int node)
    {
        if(ultimateParent[node]==node)
        {
            return node;
        }
        return ultimateParent[node]=findUltimateParent(ultimateParent[node]);
    }

    int getSize(int node)
    {
        return size[node];
    }

    int getRank(int node)
    {
        return rank[node];
    }

    void unionByRank(int u,int v)
    {
        int ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
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

    void unionBySize(int u,int v)
    {
        int ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
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
    int n,q;
    cin>>n>>q;
    DisjointSet ds(n),ds1(n),ds2(n);
    vector<int> mx(n);
    iota(mx.begin(),mx.end(),0);
    while(q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        u--;
        v--;
        if(type==1)
        {
            ds1.unionByRank(u,v);
            ds2.unionByRank(u,v);
        }
        else if(type==2)
        {
            int cur=u;
            while(ds.findUltimateParent(cur)!=ds.findUltimateParent(v))
            {
                int nxt=mx[ds.findUltimateParent(cur)]+1;
                int mx1=nxt-1,mx2=mx[ds.findUltimateParent(nxt)];
                ds.unionByRank(cur,nxt);
                ds2.unionByRank(cur,nxt);
                mx[ds.findUltimateParent(cur)]=max(mx1,mx2);
            }
        }
        else
        {
            cout<<((ds2.findUltimateParent(u)==ds2.findUltimateParent(v))?"YES":"NO")<<'\n';
        }
    }
    return 0;
}
