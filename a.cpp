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
    int n;
    queue<pair<int,int>> q;
    cin>>n;
    vector<int> a(n),dist(n,1e9),adj[n];
    for(auto &v:a)
    {
        cin>>v;
    }
    for(int i=0;i<n;++i)
    {
        if(i+a[i]<n)
        {
            if((a[i]&1)==(a[i+a[i]]&1))
            {
                adj[i+a[i]].push_back(i);
            }
            else
            {
                q.push({i,1});
                dist[i]=1;
            }
        }
        if(i-a[i]>=0)
        {
            if((a[i]&1)==(a[i-a[i]]&1))
            {
                adj[i-a[i]].push_back(i);
            }
            else
            {
                q.push({i,1});
                dist[i]=1;
            }
        }
    }
    while(q.size())
    {
        int node=q.front().first,dis=q.front().second;
        q.pop();
        for(auto &v:adj[node])
        {
            if(dist[v]>1+dis)
            {
                dist[v]=1+dis;
                q.push({v,dist[v]});
            }
        }
    }
    for(auto &v:dist)
    {
        cout<<((v>(int)1e8)?-1:v)<<' ';
    }
    cout<<'\n';
    return 0;
}
