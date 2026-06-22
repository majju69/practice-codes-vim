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
    int n,m,ind=0;
    map<int,int> mp;
    vector<array<int,3>> edges;
    cin>>n>>m;
    vector<int> dp(n,0),ndp(n,0);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        edges.push_back({u,v,w});
        mp[w]=0;
    }
    for(auto &v:mp)
    {
        v.second=ind++;
    }
    vector<vector<pair<int,int>>> comp(ind);
    for(auto &edge:edges)
    {
        comp[mp[edge[2]]].push_back({edge[0],edge[1]});
    }
    for(auto &vec:comp)
    {
        assert(!vec.empty());
        for(auto &edge:vec)
        {
            ndp[edge.second]=max(ndp[edge.second],dp[edge.first]+1);
        }
        for(auto &edge:vec)
        {
            dp[edge.second]=max(dp[edge.second],ndp[edge.second]);
        }
    }
    cout<<(*max_element(dp.begin(),dp.end()))<<'\n';
    return 0;
}
