#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int dp[11][1001];

int solve(int i,int rem,vector<int> &a,vector<int> &b,vector<int> &c,vector<int> &d,int c0,int d0)
{
    if(i>=(int)a.size())
    {
        return (rem/c0)*d0;
    }
    if(dp[i][rem]!=-1)
    {
        return dp[i][rem];
    }
    int ans=0;
    for(int cnt=0;cnt<=100;++cnt)
    {
        if(rem>=c[i]*cnt&&a[i]>=cnt*b[i])
        {
            ans=max(ans,solve(i+1,rem-c[i]*cnt,a,b,c,d,c0,d0)+cnt*d[i]);
        }
        else
        {
            break;
        }
    }
    return dp[i][rem]=ans;
}

int maxCost(int rem,vector<int> &a,vector<int> &b,vector<int> &c,vector<int> &d,int c0,int d0)
{
    int n=a.size();
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=rem;++j)
        {
            dp[i][j]=-1;
        }
    }
    return solve(0,rem,a,b,c,d,c0,d0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int rem,n,c0,d0;
    cin>>rem>>n>>c0>>d0;
    vector<int> a(n),b(n),c(n),d(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    cout<<maxCost(rem,a,b,c,d,c0,d0)<<'\n';
    return 0;
}
