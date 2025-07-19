#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

inline ll add(ll a,ll b)
{
    return (a%mod+b%mod)%mod;
}

inline ll mul(ll a,ll b)
{
    return (a%mod*b%mod)%mod;
}

long long power(long long a,long long b)        // Use when mod is of order 10^9 or less
{
    long long ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;       
        b>>=1;
    }
    return ans%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,m,ans=1;
        cin>>n>>m;
        vector<ll> adj[n];
        vector<vector<ll>> colour(2,vector<ll>(n,-1));
        for(ll i=0;i<m;++i)
        {
            ll u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(ll i=0;i<n;++i)
        {
            if(colour[0][i]==-1)
            {
                ll cnt[2]={0,0};
                ll cur_cnt=0;
                queue<pair<ll,ll>> q;
                q.push({i,0});
                colour[0][i]=0;
                while(q.size())
                {
                    ll node=q.front().first,col=q.front().second;
                    q.pop();
                    cnt[col]++;
                    for(auto &v:adj[node])
                    {
                        if(colour[0][v]==-1)
                        {
                            colour[0][v]=1-col;
                            q.push({v,1-col});
                        }
                        else
                        {
                            if(colour[0][v]==colour[0][node])
                            {
                                cnt[0]=cnt[1]=-1e18;
                                break;
                            }
                        }
                    }
                }
                if(cnt[0]<0||cnt[1]<0)
                {
                    ans=0;
                    break;
                }
                cur_cnt=add(cur_cnt,power(2,cnt[1]));
                while(q.size())
                {
                    q.pop();
                }
                cnt[0]=0;
                cnt[1]=0;
                q.push({i,1});
                colour[1][i]=1;
                while(q.size())
                {
                    ll node=q.front().first,col=q.front().second;
                    q.pop();
                    cnt[col]++;
                    for(auto &v:adj[node])
                    {
                        if(colour[1][v]==-1)
                        {
                            colour[1][v]=1-col;
                            q.push({v,1-col});
                        }
                        else
                        {
                            if(colour[1][v]==colour[1][node])
                            {
                                cnt[0]=cnt[1]=-1e18;
                                break;
                            }
                        }
                    }
                }
                if(cnt[0]<0||cnt[1]<0)
                {
                    ans=0;
                    break;
                }
                cur_cnt=add(cur_cnt,power(2,cnt[1]));
                ans=mul(ans,cur_cnt);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
