#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2e5+10;
int p[N],a[N],mn[N],mx[N];
bool ok[N];
vector<int> adj[N];

bool checkCircularSorted(vector<int> &a)
{
    const int n=a.size();
    int cnt=0;
    for(int i=1;i<n;++i)
    {
        if(a[i-1]>a[i])
        {
            cnt++;
            if(cnt>1)
            {
                return 0;
            }
        }
    }
    if(cnt==1)
    {
        return (a[0]>a[n-1]);
    }
    return 1;
}

bool check(const vector<pair<int,int>> &a)
{
    const int n=a.size();
    int ind=0;
    vector<pair<int,int>> tmp=a;
    vector<int> perm;
    sort(tmp.begin(),tmp.end());
    for(int i=1;i<n;++i)
    {
        if(tmp[i].first<tmp[i-1].second)
        {
            return 0;
        }
    }
    for(auto &v:a)
    {
        perm.push_back(v.first);
    }
    return checkCircularSorted(perm);
}

void dfs(int node)
{
    if(a[node]==-1)
    {
        mn[node]=1e9;
        mx[node]=-1e9;
    }
    else
    {
        ok[node]=1;
        mn[node]=a[node];
        mx[node]=a[node];
    }
    bool node_ok=1;
    vector<pair<int,int>> a; 
    for(auto &v:adj[node])
    {
        if(v!=p[node])
        {
            dfs(v);
            mn[node]=min(mn[node],mn[v]);
            mx[node]=max(mx[node],mx[v]);
            node_ok=(node_ok&&ok[v]);
            a.push_back({mn[v],mx[v]});
        }
    }
    if(node_ok)
    {
        node_ok=check(a);
    }
    ok[node]=node_ok;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        for(int i=1;i<n;++i)
        {
            int x;
            cin>>x;
            x--;
            adj[i].push_back(x);
            adj[x].push_back(i);
            p[i]=x;
        }
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            a[i]--;
        }
        dfs(0);
        cout<<(ok[0]?"YES":"NO")<<'\n';
        for(int i=0;i<n;++i)
        {
            p[i]=a[i]=mn[i]=mx[i]=0;
            ok[i]=0;
            adj[i].clear();
        }
    }
    return 0;
}
