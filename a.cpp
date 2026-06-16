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
            return;
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
            return;
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

void dfs(ll node,vector<ll> adj[],vector<ll> &sub,ll &cnt)
{
    sub[node]=1;
    cnt++;
    for(auto &v:adj[node])
    {
        dfs(v,adj,sub,cnt);
        sub[node]+=sub[v];
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
        ll n,cntGood=0,ans=0,cur=0;
        cin>>n;
        vector<ll> a(n),zeroPath;
        vector<bool> good(n,0),vis(n,0);
        DisjointSet ds(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        for(ll i=0;i<n;++i)
        {
            ll nxt=i+a[i];
            if(nxt>=0&&nxt<n)
            {
                ds.unionBySize(i,nxt);
            }
        }
        for(ll i=0;i<n;++i)
        {
            ll nxt=i+a[i];
            if(nxt>=0&&nxt<n)
            {
                continue;
            }
            good[ds.findUltimateParent(i)]=1;
            cntGood+=ds.getSize(ds.findUltimateParent(i));
        }
        while(1)
        {
            if(cur>=n||cur<0)
            {
                break;
            }
            if(vis[cur])
            {
                break;
            }
            zeroPath.push_back(cur);
            vis[cur]=1;
            cur+=a[cur];
        }
        if(!good[ds.findUltimateParent(0)])
        {
            ans+=(ll)zeroPath.size()*(cntGood+n+1);
        }
        else
        {
            ll cnt=0;
            vector<ll> adj[n],sub(n,0);
            cntGood-=ds.getSize(ds.findUltimateParent(0));
            for(ll i=0;i<n;++i)
            {
                if(i+a[i]>=n||i+a[i]<0)
                {
                    continue;
                }
                if(ds.findUltimateParent(i)==ds.findUltimateParent(0))
                {
                    adj[i+a[i]].push_back(i);
                }
            }
            dfs(zeroPath.back(),adj,sub,cnt);
            for(auto &v:zeroPath)
            {
                ans+=cntGood+cnt-sub[v]+n+1;
            }
            ans+=((n<<1)+1)*(n-(ll)zeroPath.size());            
        }
        cout<<ans<<'\n';
    }
    return 0;
}
