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
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,cur=0;
        cin>>n;
        DisjointSet ds(n-1);
        vector<ll> a(n),d(n-1),ans(n,0);
        vector<bool> vis(n-1,0);
        vector<vector<ll>> idx(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        for(ll i=0;i<n-1;i++)
        {
            d[i]=abs(a[i]-a[i+1]);
        }
        for(ll i=0;i<n-1;i++)
        {
            idx[d[i]].push_back(i);
        }
        for(ll k=n-1;k>=1;k--)
        {
            for(auto &v:idx[k])
            {
                vis[v]=1;
                cur++;
                if(v>0&&vis[v-1])
                {
                    ll a=ds.findUltimateParent(v),b=ds.findUltimateParent(v-1);
                    if(a!=b)
                    {
                        cur-=ds.getSize(a)*(ds.getSize(a)+1)/2;
                        cur-=ds.getSize(b)*(ds.getSize(b)+1)/2;
                        ds.unionBySize(a,b);
                        ll r=ds.findUltimateParent(a);
                        cur+=ds.getSize(r)*(ds.getSize(r)+1)/2;
                    }
                }
                if(v+1<n-1&&vis[v+1])
                {
                    ll a=ds.findUltimateParent(v),b=ds.findUltimateParent(v+1);
                    if(a!=b)
                    {
                        cur-=ds.getSize(a)*(ds.getSize(a)+1)/2;
                        cur-=ds.getSize(b)*(ds.getSize(b)+1)/2;
                        ds.unionBySize(a,b);
                        ll r=ds.findUltimateParent(a);
                        cur+=ds.getSize(r)*(ds.getSize(r)+1)/2;
                    }
                }
            }
            ans[k]=cur;
        }
        for(int k=1;k<n;k++)
        {
            cout<<ans[k]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
