#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

inline bool bit(long long a,int i)
{
    return (a>>i&1);
}

int bfs(int src,int n,vector<int> adj[])
{
    int mn=1e9;
    vector<int> dist(n,1e9),par(n,-1);
    queue<int> q;
    dist[src]=0;
    q.push(src);
    while(q.size())
    {
        int node=q.front();
        q.pop();
        for(auto &v:adj[node])
        {
            if(dist[v]>1+dist[node])
            {
                dist[v]=1+dist[node];
                q.push(v);
                par[v]=node;
            }
            else
            {
                if(par[node]!=v&&par[v]!=node)
                {
                    mn=min(mn,dist[node]+dist[v]+1);
                }
            }
        }
    }
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    bool three=0;
    vector<long long> a;
    vector<vector<int>> edges(60);
    for(int i=0;i<n;++i)
    {
        long long x;
        cin>>x;
        if(x!=0)
        {
            a.push_back(x);
        }
    }
    n=a.size();
    for(int i=0;i<n;++i)
    {
        if(three)
        {
            break;
        }
        for(int j=0;j<60;++j)
        {
            if(bit(a[i],j))
            {
                edges[j].push_back(i);
                if((int)edges[j].size()>=3)
                {
                    three=1;
                    break;
                }
            }
        }
    }
    if(three)
    {
        cout<<3<<'\n';
    }
    else
    {
        int mn=1e9;
        vector<int> adj[n];
        for(auto &vec:edges)
        {
            if((int)vec.size()>1)
            {
                adj[vec[0]].push_back(vec[1]);
                adj[vec[1]].push_back(vec[0]);
            }
        }
        for(int i=0;i<n;++i)
        {
            mn=min(mn,bfs(i,n,adj));
        }
        if(mn==(int)1e9)
        {
            mn=-1;
        }
        cout<<mn<<'\n';
    }
    return 0;
}
