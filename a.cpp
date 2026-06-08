#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

struct Query
{
    int idx,lt,rt,blk;
};

const int N=1e5+10,BLK=317;
int a[N],freq[N],pre[N],post[N],val[N],timer=0;
long long ans[N];
Query qry[N];
vector<int> adj[N];
map<int,long long> mp;

bool cmp(const Query &a,const Query &b)
{
    if(a.blk==b.blk)
    {
        if(a.blk&1)
        {
            return a.rt<b.rt;
        }
        return a.rt>b.rt;
    }
    return a.blk<b.blk;
}

void addElement(const int &pos)
{
    if(freq[val[pos]]!=0)
    {
        const int &key=freq[val[pos]];
        long long &value=mp[key];
        value-=(long long)val[pos];
        if(value==0)
        {
            mp.erase(key);
        }
    }
    freq[val[pos]]++;
    mp[freq[val[pos]]]+=(long long)val[pos];
}

void removeElement(const int &pos)
{
    const int &key=freq[val[pos]];
    long long &value=mp[key];
    value-=(long long)val[pos];
    if(value==0)
    {
        mp.erase(key);
    }
    freq[val[pos]]--;
    if(freq[val[pos]]!=0)
    {
        mp[freq[val[pos]]]+=(long long)val[pos];
    }
}

void dfs(int node,int p)
{
    pre[node]=timer;        
    val[timer]=a[node];
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            timer++;
            dfs(v,node);
        }
    }
    post[node]=timer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,l=0,r=-1;
    cin>>n;
    for(int i=0;i<n;++i)
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
    for(int i=0;i<n;++i)
    {
        qry[i].lt=pre[i];
        qry[i].rt=post[i];
        qry[i].blk=pre[i]/BLK;
        qry[i].idx=i;
    }
    sort(qry,qry+n,cmp);
    for(int i=0;i<n;++i)
    {
        Query &v=qry[i];
        while(v.lt<l)
        {
            l--;
            addElement(l);
        }
        while(v.rt>r)
        {
            r++;
            addElement(r);
        }
        while(v.lt>l)
        {
            removeElement(l);
            l++;
        }
        while(v.rt<r)
        {
            removeElement(r);
            r--;
        }
        pair<const int,long long> &p=(*(--mp.end()));
        ans[v.idx]=p.second;
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
