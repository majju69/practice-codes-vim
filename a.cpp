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
    int n,m,s,t,ans=0;
    cin>>n>>m>>s>>t;
    vector<int> adj[n],distFwd(n,1e9),distRev(n,1e9);
    map<pair<int,int>,bool> isEdge;
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        isEdge[make_pair(min(u,v)-1,max(u,v)-1)]=true;
    }
    dijkstra(s-1,adj,distFwd);
    dijkstra(t-1,adj,distRev);
    for(int i=0;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(!isEdge[make_pair(i,j)])
            {
                int minCost=min(distFwd[i]+distRev[j]+1,distFwd[j]+distRev[i]+1);
                ans+=(minCost>=distFwd[t-1]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

