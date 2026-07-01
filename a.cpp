#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2e5+10;
int sub[N],par[N];
array<int,3> dp[N];
vector<int> adj[N];

array<int,3> get(const vector<array<int,3>> &children)
{
    const int n=children.size();
    array<int,3> dp=children[0],ndp;
    for(int i=1;i<n;++i)
    {
        ndp[0]=max({dp[0]+children[i][0],dp[1]+children[i][2],dp[2]+children[i][1]});
        ndp[1]=max({dp[0]+children[i][1],dp[1]+children[i][0],dp[2]+children[i][2]});
        ndp[2]=max({dp[1]+children[i][1],dp[0]+children[i][2],dp[2]+children[i][0]});
        dp=ndp;
    }
    return dp;
}

void dfs(int node,int p)
{
    sub[node]=((node!=0)&&((int)adj[node].size()==1));
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            par[v]=node;
            dfs(v,node);
            sub[node]+=sub[v];
        }
    }
}

void dfs(int node)
{
    if(node!=0&&(int)adj[node].size()==1)
    {
        dp[node]={0,1,0};
        return;
    }
    vector<array<int,3>> children;
    for(auto &v:adj[node])
    {
        if(v!=par[node])
        {
            dfs(v);
            children.push_back(dp[v]);
        }
    }
    dp[node]=get(children);
    dp[node][1]=sub[node];
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
        int n;
        cin>>n;
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
        dfs(0);
        cout<<((dp[0][0]==sub[0])?"YES":"NO")<<'\n';
        for(int i=0;i<n;++i)
        {
            adj[i].clear();
            dp[i][0]=dp[i][1]=dp[i][2]=0;
            sub[i]=0;
            par[i]=0;
        }
    }
    return 0;
}   
