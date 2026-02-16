#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

inline ll add(ll a,ll b)
{
    return ((a%mod)+(b%mod))%mod;
}

inline ll mul(ll a,ll b)
{
    return ((a%mod)*(b%mod))%mod;
}

inline ll sub(ll a,ll b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
}

long long power(long long a,long long b)        // Use when mod is of order 10^9 or less
{
    long long ans=1;
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

inline ll divide(ll a,ll b)
{
    return mul(a,power(b,mod-2));
}

inline ll sum_gp(ll a,ll n,ll r)
{
    if(r==1)
    {
        return mul(n,a);
    }
    return mul(a,divide(sub(power(r,n),1),sub(r,1)));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,n,x;
    cin>>a>>b>>n>>x;
    cout<<add(mul(power(a,n),x),sum_gp(b,n,a))<<'\n';
    return 0;
}

/*



a(ax+b)+b = a^2x+b(1+a)


a(a^2x+b(1+a))+b

f^n(x) = a^n*x + b(1+a+a^2+..+a^(n-1))



*/
