#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

void dfs(int node,int cur,vector<bool> &vis,vector<int> adj[],vector<vector<int>> &mark)
{
    vis[node]=1;
    mark[node].push_back(cur);
    for(auto &v:adj[node])
    {
        if(!vis[v])
        {
            dfs(v,cur,vis,adj,mark);
        }
    }
}

void dfs(int node,vector<bool> &vis,vector<int> adj[],int &cnt)
{
    vis[node]=1;
    cnt++;
    for(auto &v:adj[node])
    {
        if(!vis[v])
        {
            dfs(v,vis,adj,cnt);
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
        int n,m,a,b,cnt[]={0,0};
        cin>>n>>m>>a>>b;
        vector<int> _a,_b;
        vector<vector<int>> mark(n);
        vector<bool> vis(n,0);
        a--;
        b--;
        if(a>b)
        {
            swap(a,b);
        }
        vector<int> adj[n],adj_a[n],adj_b[n];
        for(int i=0;i<m;++i)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            if(u>v)
            {
                swap(u,v);
            }
            if(u==a&&v==b)
            {
                continue;
            }
            if(u==a)
            {
                _a.push_back(v);
                continue;
            }
            if(v==a)
            {
                _a.push_back(u);
                continue;
            }
            if(v==b)
            {
                _b.push_back(u);
                continue;
            }
            if(u==b)
            {
                _b.push_back(v);
                continue;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(auto &v:_a)
        {
            if(!vis[v])
            {
                dfs(v,0,vis,adj,mark);
            }
        }
        fill(vis.begin(),vis.end(),0);
        for(auto &v:_b)
        {
            if(!vis[v])
            {
                dfs(v,1,vis,adj,mark);
            }
        }
        for(int i=0;i<n;++i)
        {
            if((int)mark[i].size()==2||(int)mark[i].size()==0)
            {
                continue;
            }
            if(mark[i][0]==0)
            {
                for(auto &v:adj[i])
                {
                    assert((int)mark[v].size()==1);
                    adj_a[i].push_back(v);
                }
            }
            else
            {
                for(auto &v:adj[i])
                {
                    assert((int)mark[v].size()==1);
                    adj_b[i].push_back(v);
                }
            }
        }
        fill(vis.begin(),vis.end(),0);
        for(int i=0;i<n;++i)
        {
            if((int)mark[i].size()==2||(int)mark[i].size()==0||mark[i][0]==1)
            {
                continue;
            }
            if(!vis[i])
            {
                dfs(i,vis,adj_a,cnt[0]);
            }
        }
        fill(vis.begin(),vis.end(),0);
        for(int i=0;i<n;++i)
        {
            if((int)mark[i].size()==2||(int)mark[i].size()==0||mark[i][0]==0)
            {
                continue;
            }
            if(!vis[i])
            {
                dfs(i,vis,adj_b,cnt[1]);
            }
        }
        cout<<1ll*cnt[0]*cnt[1]<<'\n';
    }
    return 0;
}
