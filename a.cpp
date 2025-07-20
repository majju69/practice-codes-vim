#include<bits/stdc++.h>
using namespace std;

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

void dfsPath(int node,int bee,vector<int> adj[],vector<bool> &vis,vector<int> &path)
{
    path.push_back(node);
    vis[node]=true;
    if(node==bee)
    {
        return ;
    }
    for(auto &v:adj[node])
    {
        if(!vis[v])
        {
            dfsPath(v,bee,adj,vis,path);
        }
    }
    if(path.back()!=bee)
    {
        path.pop_back();
    }
}

int main()
{
    int n,x,y,a=0,b=0;
    cin>>n>>x>>y;
    x--;
    y--;
    vector<int> adj[n],path;
    vector<bool> vis(n,false);
    map<pair<int,int>,bool> isInPath;
    DisjointSet ds(n);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        isInPath[make_pair(min(u,v),max(u,v))]=false;
    }
    dfsPath(x,y,adj,vis,path);
    for(int i=0;i<path.size()-1;++i)
    {
        int u=min(path[i],path[i+1]),v=max(path[i],path[i+1]);
        isInPath[make_pair(u,v)]=true;
    }
        
    for(int i=0;i<n;++i)
    {
        for(auto &v:adj[i])
        {
            int v1=min(i,v),v2=max(i,v);
            if(!isInPath[make_pair(v1,v2)])
            {
                ds.unionBySize(v1,v2);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        a+=(ds.findUltimateParent(i)==ds.findUltimateParent(x));
        b+=(ds.findUltimateParent(i)==ds.findUltimateParent(y));
    }
    cout<<(long long)n*(n-1)-(long long)a*b<<endl;
    return 0;
}

