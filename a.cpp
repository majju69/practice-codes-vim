#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,ans=0;
        queue<int> q;
        cin>>n;
        vector<int> adj[n],adjT[n],indegree(n,0),topoSort;
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            while(x--)
            {
                int u;
                cin>>u;
                u--;
                adj[u].push_back(i);
                adjT[i].push_back(u);
                indegree[i]++;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(q.size())
        {
            int node=q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto &v:adj[node])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        if((int)topoSort.size()!=n)
        {
            cout<<-1<<'\n';
        }
        else
        {
            vector<int> dp(n,1e9);
            for(auto &v:topoSort)
            {
                int cur=1;
                for(auto &v1:adjT[v])
                {
                    cur=max(cur,dp[v1]+(v1>v));
                }
                dp[v]=cur;
            }
            for(auto &v:dp)
            {
                ans=max(ans,v);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
