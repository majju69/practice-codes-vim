#include<bits/stdc++.h>
using namespace std;

void fillSubordinates(int node,vector<int> adj[],vector<int> &subordinates)
{
    if(adj[node].size()==0)
    {
        subordinates[node]=0;
        return;
    }
    int curNodeSubordinates=0;
    for(auto &v:adj[node])
    {
        if(subordinates[v]==-1)
        {
            fillSubordinates(v,adj,subordinates);
        }
        curNodeSubordinates+=(1+subordinates[v]);
    }
    subordinates[node]=curNodeSubordinates;
    return;
}

void dfs(int node,vector<int> adj[],vector<int> &ans)
{
    ans.push_back(node);
    for(auto &v:adj[node])
    {
        dfs(v,adj,ans);
    }
}

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> adj[n],subordinates(n,-1),ans;
    unordered_map<int,int> index;
    for(int i=1;i<n;++i)
    {
        int x;
        cin>>x;
        adj[x-1].push_back(i);
    }
    for(int i=0;i<n;++i)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    fillSubordinates(0,adj,subordinates);
    dfs(0,adj,ans);
    for(int i=0;i<n;++i)
    {
        index[ans[i]]=i;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(y>subordinates[x])
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<ans[index[x]+y]+1<<endl;
        }
    }
    cout<<endl;
    return 0;
}

