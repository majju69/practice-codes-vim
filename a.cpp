#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=1e9+7;
const int N=2e5+10,M=1024;
int a[N],p[N];
array<int,M> dp,ndp;

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

int sub(const int &a,const int &b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
}

int mul(const int &a,const int &b)
{
    return (1ll*(a%mod)*(b%mod))%mod;
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
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>p[i];
            p[i]=divide(p[i],10000);
        }
        dp[0]=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<M;++j)
            {
                ndp[j]=add(mul(sub(1,p[i]),dp[j]),mul(p[i],dp[j^a[i]]));
            }
            dp=ndp;
        }
        for(int i=1;i<M;++i)
        {
            ans=add(ans,mul(dp[i],mul(i,i)));
        }
        cout<<ans<<'\n';
        for(int i=0;i<M;++i)
        {
            dp[i]=ndp[i]=0;
        }
    }
    return 0;
}
