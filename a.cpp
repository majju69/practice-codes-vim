#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src,vector<int> adj[],vector<int> &dist)
{
    queue<pair<int,int> > q;
    dist[src]=0;
    q.push(make_pair(src,0));
    while(q.size())
    {
        int node=q.front().first,dis=q.front().second;
        q.pop();
        for(auto &v:adj[node])
        {
            if(dist[v]>1+dis)
            {
                dist[v]=1+dis;
                q.push(make_pair(v,dist[v]));
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> adj[n],dist(n,INT_MAX);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        if(i!=x-1)
        {
            adj[i].push_back(x-1);
        }
    }
    for(int i=0;i<n;++i)
    {
        if(i!=0)
        {
            adj[i].push_back(i-1);
        }
        if(i!=n-1)
        {
            adj[i].push_back(i+1);
        }
    }
    dijkstra(0,adj,dist);
    for(int i=0;i<n;++i)
    {
        cout<<dist[i]<<' ';
    }
    cout<<endl;
    return 0;
}

