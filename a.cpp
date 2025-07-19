#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

void dfs(int node,int p,vector<int> adj[],vector<bool> &red,vector<int> &near,vector<int> &depth)
{
    near[node]=((red[node])?0:1e9);
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            depth[v]=depth[node]+1;
            dfs(v,node,adj,red,near,depth);
            near[node]=min(near[node],near[v]+1);
        }
    }
}

void dfs(int node,int p,vector<int> adj[],vector<bool> &red,vector<int> &near)
{
    near[node]=min(near[node],near[p]+1);
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            dfs(v,node,adj,red,near);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,k;
        bool ok=0;
        cin>>n>>k;
        vector<int> adj[n],near(n,1e9),depth(n,0);
        vector<bool> red(n,0);
        for(int i=0;i<k;++i)
        {
            int x;
            cin>>x;
            x--;
            red[x]=1;
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
        dfs(0,0,adj,red,near,depth);
        dfs(0,0,adj,red,near);
        for(int i=1;i<n;++i)
        {
            if((int)adj[i].size()==1)
            {
                if(near[i]>depth[i])
                {
                    ok=1;
                    break;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}
