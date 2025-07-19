#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int gcd(int a,int b)
{
    return ((b==0)?a:gcd(b,a%b));
}

vector<long long> spf(200001,0);

void smallestPrimeFactor()
{
    long long n=spf.size();
    for(long long i=1;i<n;++i)
    {
        spf[i]=i;
    }
    for(long long i=4;i<n;i+=2)
    {
        spf[i]=2;
    }
    for(long long i=3;i*i<n;++i)
    {
        if(spf[i]==i)
        {
            for(long long j=i*i;j<n;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }   
        }
    }
}

// 1 --> ending  0 --> passing
void dfs(int node,int p,vector<int> adj[],vector<int> &a,map<pair<int,pair<int,int>>,int> &dp)
{
    if(node!=0&&adj[node].size()==1)
    {
        int x=a[node];
        while(x>1)
        {
            dp[{node,{1,spf[x]}}]=1;
            x/=spf[x];
        }
        return;
    }
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            dfs(v,node,adj,a,dp);
        }
    }
    map<int,vector<int>> mp;
    int x=a[node];
    while(x>1)
    {
        dp[{node,{1,spf[x]}}]=1;
        x/=spf[x];
    }
    for(auto &v:adj[node])
    {
        if(v!=p)
        {
            int g=gcd(a[node],a[v]);
            while(g>1)
            {
                if(dp.find({v,{1,spf[g]}})!=dp.end())
                {
                    dp[{node,{1,spf[g]}}]=max(dp[{v,{1,spf[g]}}]+1,dp[{node,{1,spf[g]}}]);
                    mp[g].push_back(dp[{v,{1,spf[g]}}]);
                }
                g/=spf[g];
            }
        }
    }
    for(auto &v:mp)
    {
        sort(v.second.rbegin(),v.second.rend());
        if(v.second.size()>1)
        {
            dp[{node,{0,v.first}}]=v.second[0]+v.second[1]+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    smallestPrimeFactor();
    int n,ans=0;
    map<pair<int,pair<int,int>>,int> dp;
    cin>>n;
    vector<int> a(n),adj[n];
    for(auto &v:a)
    {
        cin>>v;
        int x=1;
        set<int> st;
        while(v>1)
        {
            if(st.find(spf[v])==st.end())
            {
                st.insert(spf[v]);
                x*=spf[v];
            }
            v/=spf[v];
        }
        v=x;
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
    dfs(0,0,adj,a,dp);
    for(auto &v:dp)
    {
        ans=max(ans,v.second);
    }
    cout<<ans<<'\n';
    return 0;
}
