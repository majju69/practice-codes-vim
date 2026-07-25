#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2e5+10,MX=1e6+10;
int a[N],sub[N],par[N];
vector<int> adj[N];
bool isSquare[MX];

void dfs(int node,int p=-1)
{
    sub[node]=1;
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            par[v]=node;
            dfs(v,node);
            sub[node]+=sub[v];
        }
    }
}

array<long long,3> get(const vector<int> &a)
{
    array<long long,3> ans={0,0,0};
    for(auto &v:a)
    {
        ans[2]+=1ll*v*ans[1];
        ans[1]+=1ll*v*ans[0];
        ans[0]+=1ll*v;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i*i<MX;++i)
    {
        isSquare[i*i]=1;
    }
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        long long ans=0;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        for(int i=0;i<n;++i)
        {
            if(!isSquare[a[i]])
            {
                continue;
            }
            vector<int> cur;
            for(auto &v:adj[i])
            {
                if(v!=par[i])
                {
                    cur.push_back(sub[v]);
                }
            }
            if(i!=0)
            {
                cur.push_back(n-sub[i]);
            }
            array<long long,3> cur_ans=get(cur);
            ans+=cur_ans[1]+cur_ans[2];
        }
        cout<<ans<<'\n';
        for(int i=0;i<n;++i)
        {
            a[i]=sub[i]=par[i]=0;
            adj[i].clear();
        }
    }
    return 0;
}
