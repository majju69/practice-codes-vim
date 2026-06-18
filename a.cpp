#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=998244353,N=2e5+10;
int p[N];

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

int divide(const int &a,const int &b)
{
    return mul(a,power(b,mod-2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,c1=0,c2=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
        p[i]=divide(p[i],100);
    }
    for(int i=n-1;i>=1;--i)
    {
        c1=add(1,mul(p[i],c1));
        c2=add(mul(p[i],c2),sub(1,p[i]));
    }
    cout<<divide(add(1,mul(p[0],c1)),sub(p[0],mul(p[0],c2)))<<'\n';
    return 0;
}
