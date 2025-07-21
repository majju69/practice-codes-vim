#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1e5;
int removed[MAX_N],subtree[MAX_N];

void init(int n)
{
    for(int i=0;i<n;++i)
    {
        removed[i]=subtree[i]=0;
    }
}

int getSize(int node,vector<int> adj[],int par=-1)
{
    subtree[node]=1;
    for(auto &v:adj[node])
    {
        if(v!=par&&!removed[v])
        {
            subtree[node]+=getSize(v,adj,node);
        }
    }
    return subtree[node];
}

int getCentroid(int node,int sz,vector<int> adj[],int par=-1)
{
    for(auto &v:adj[node])
    {
        if(!removed[v]&&v!=par)
        {
            if(subtree[v]*2>sz)
            {
                return getCentroid(v,sz,adj,node);
            }
        }
    }
    return node;
}

void build(int node,vector<int> adj[],string &s,char ch)
{
    int centroid=getCentroid(node,getSize(node,adj),adj);
    s[centroid]=ch;
    ch=(char)(ch+1);
    removed[centroid]=1;
    for(auto &v:adj[centroid])
    {
        if(!removed[v])
        {
            build(v,adj,s,ch);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    char ch='A';
    cin>>n;
    init(n);
    vector<int> adj[n];
    string s(n,'Z');
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    build(0,adj,s,ch);
    for(auto &v:s)
    {
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}

