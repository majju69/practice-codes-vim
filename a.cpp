#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

ll dp[1001][2001];

ll solve(ll i,ll j,ll k,vector<ll> &a,vector<ll> &b)
{
    if(i>=(ll)a.size())
    {
        return 0;
    }
    if((ll)a.size()-i>(ll)b.size()-j)
    {
        return 1e18;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    ll take=max(solve(i+1,j+1,k,a,b),abs(a[i]-b[j])+abs(b[j]-k)),skip=solve(i,j+1,k,a,b);
    return dp[i][j]=min(take,skip);
}

ll minTime(vector<ll> &a,vector<ll> &b,ll k)
{
    ll n=a.size(),m=b.size();
    for(ll i=0;i<=n;++i)
    {
        for(ll j=0;j<=m;++j)
        {
            dp[i][j]=-1;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return solve(0,0,k,a,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m);
    for(auto &v:a)
    {
        cin>>v;
    }
    for(auto &v:b)
    {
        cin>>v;
    }
    cout<<minTime(a,b,k)<<'\n';
    return 0;
}
