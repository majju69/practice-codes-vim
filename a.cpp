#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=998244353;
const int N=1e6+10;
array<int,2> dp[N];

int power(int a,int b)        // Use when mod is of order 10^9 or less
{
    int ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
        {
            ans=(1ll*(ans%mod)*(a%mod))%mod;
        }
        a=(1ll*(a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return ans%mod;
}

int add(const int &a,const int &b)
{
    return ((a%mod)+(b%mod))%mod;
}

int mul(const int &a,const int &b)
{
    return (1ll*(a%mod)*(b%mod))%mod;
}

int sub(const int &a,const int &b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
}

int divide(const int &a,const int &b)
{
    return mul(a,power(b,mod-2));
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
        int n,cnt=0,h0=-1;
        string s,t;
        cin>>n>>s>>t;
        for(int i=0;i<n;++i)
        {
            cnt+=(s[i]==t[i]);
        }
        dp[0]={0,1};
        dp[1]={sub(0,1),1};
        for(int i=1;i<n;++i)
        {
            const int a0=dp[i-1][0],a1=dp[i-1][1],b0=dp[i][0],b1=dp[i][1];
            dp[i+1][0]=add(dp[i+1][0],mul(b0,n));
            dp[i+1][0]=sub(dp[i+1][0],mul(a0,i));
            dp[i+1][0]=sub(dp[i+1][0],n);
            dp[i+1][0]=divide(dp[i+1][0],sub(n,i));
            dp[i+1][1]=add(dp[i+1][1],mul(b1,n));
            dp[i+1][1]=sub(dp[i+1][1],mul(a1,i));
            dp[i+1][1]=divide(dp[i+1][1],sub(n,i));
        }
        h0=divide(sub(0,dp[n][0]),dp[n][1]);
        cout<<add(dp[cnt][0],mul(dp[cnt][1],h0))<<'\n';
        for(int i=0;i<=n;++i)
        {
            dp[i]={0,0};
        }
    }
    return 0;
}
