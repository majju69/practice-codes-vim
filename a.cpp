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
        multiset<int> st;
        cin>>n;
        vector<int> adj[n],sub(n);
        vector<vector<int>> dp(n,vector<int>(2));
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;++i)
        {
            st.insert((int)adj[i].size());
        }
        for(int i=0;i<n;++i)
        {
            st.erase(st.find((int)adj[i].size()));
            for(auto &v:adj[i])
            {
                ans=max(ans,(int)adj[v].size()+(int)adj[i].size()-2);
                st.erase(st.find((int)adj[v].size()));
            }
            if((int)st.size()>0)
            {
                int x=(*(--st.end()));
                ans=max(ans,(int)adj[i].size()+x-1);
            }
            st.insert((int)adj[i].size());
            for(auto &v:adj[i])
            {
                st.insert((int)adj[v].size());
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
