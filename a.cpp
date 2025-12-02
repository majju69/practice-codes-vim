#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int bfs(int s,int t,vector<int> &par,vector<int> adj[],vector<vector<int>> &capacity)
{
    fill(par.begin(),par.end(),-1);
    par[s]=-2;
    queue<pair<int,int>> q;
    q.push({s,1e9});
    while(q.size())
    {
        int node=q.front().first,flow=q.front().second;
        q.pop();
        for (auto &v:adj[node])
        {
            if(par[v]==-1&&capacity[node][v])
            {
                par[v]=node;
                int new_flow=min(flow,capacity[node][v]);
                if(v==t)
                {
                    return new_flow;
                }
                q.push({v,new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s,int t,int n,vector<int> adj[],vector<vector<int>> &capacity)
{
    int flow=0,new_flow=-1;
    vector<int> par(n);
    while(1)
    {
        new_flow=bfs(s,t,par,adj,capacity);
        if(new_flow==0)
        {
            break;
        }
        flow+=new_flow;
        int cur=t;
        while(cur!=s)
        {
            int pvs=par[cur];
            capacity[pvs][cur]-=new_flow;
            capacity[cur][pvs]+=new_flow;
            cur=pvs;
        }
    }
    return flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,ans=0;
    set<int> primes;
    cin>>n>>m;
    vector<int> a(n),candy;
    vector<pair<int,int>> edges(m);
    for(auto &v:a)
    {
        cin>>v;
        int x=v;
        if(!(x&1))
        {
            primes.insert(2);
            while(!(x&1))
            {
                x>>=1;
            }
        }
        for(int i=3;i*i<=x;i+=2)
        {
            if(x%i==0)
            {
                primes.insert(i);
                while(x%i==0)
                {
                    x/=i;
                }
            }
        }
        if(x>2)
        {
            primes.insert(x);
        }
    }
    for(auto &v:primes)
    {
        candy.push_back(v);
    }
    for(auto &edge:edges)
    {
        cin>>edge.first>>edge.second;
        if(edge.second&1)
        {
            swap(edge.first,edge.second);
        }
    }
    for(auto &p:candy)
    {
        vector<int> adj[n+2];
        vector<vector<int>> capacity(n+2,vector<int>(n+2,0));
        for(int i=1;i<=n;++i)
        {
            if(i&1)
            {
                adj[0].push_back(i);
                adj[i].push_back(0);
                int x=a[i-1],cnt=0;
                while(x%p==0)
                {
                    x/=p;
                    cnt++;
                }
                capacity[0][i]=cnt;
            }
            else
            {
                adj[n+1].push_back(i);
                adj[i].push_back(n+1);
                int x=a[i-1],cnt=0;
                while(x%p==0)
                {
                    x/=p;
                    cnt++;
                }
                capacity[i][n+1]=cnt;
            }
        }
        for(auto &edge:edges)
        {
            int x=a[edge.first-1],y=a[edge.second-1],cnt=0;
            while(x%p==0&&y%p==0)
            {
                cnt++;
                x/=p;
                y/=p;
            }
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
            capacity[edge.first][edge.second]=cnt;
        }
        ans+=maxflow(0,n+1,n+2,adj,capacity);
    }
    cout<<ans<<'\n';
    return 0;
}
