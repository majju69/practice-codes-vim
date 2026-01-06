#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=60;
int degree[N];
vector<pair<int,int>> edges;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(degree,0,sizeof(degree));
        edges.clear();
        int n,m,node=-1;
        cin>>n>>m;
        for(int i=0;i<m;++i)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            edges.push_back({u,v});
            degree[u]++;
            degree[v]++;
        }
        for(int i=0;i<n;++i)
        {
            if(degree[i]!=n-1)
            {
                node=i;
                break;
            }
        }
        if(node!=-1)
        {
            cout<<2<<'\n';
            for(auto &edge:edges)
            {
                cout<<(edge.first==node||edge.second==node)+1<<' ';
            }
            cout<<'\n';
        }
        else
        {
            int cur=1;
            cout<<3<<'\n';
            for(auto &edge:edges)
            {
                if(edge.first==0||edge.second==0)
                {
                    cout<<cur<<' ';
                    cur=3-cur;
                }
                else
                {
                    cout<<3<<' ';
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}
