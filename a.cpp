#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

inline bool mul_check(long long a,long long b)
{
    return (a==0||b==0||(a<=(long long)2e18/b&&b<=(long long)2e18/a));
}

inline ll mul(ll a,ll b)
{
    return ((a%mod)*(b%mod))%mod;
}

inline ll add(ll a,ll b)
{
    return ((a%mod)+(b%mod))%mod;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x,n,ans=1;
    vector<ll> primes;
    cin>>x>>n;
    if(x%2==0)
    {
        primes.push_back(2);
        while(x%2==0)
        {
            x/=2;
        }
    }
    for(ll i=3;i*i<=x;i+=2)
    {
        if(x%i==0)
        {
            primes.push_back(i);
            while(x%i==0)
            {
                x/=i;
            }
        }
    }
    if(x>2)
    {
        primes.push_back(x);
    }
    for(auto &p:primes)
    {
        ll cur=p;
        while(cur<=n)
        {
            ll big=(mul_check(cur,p)?cur*p:2e18),small=cur;
            ans=mul(ans,power(cur,n/small-n/big));
            if(mul_check(cur,p))
            {
                cur*=p;
            }
            else
            {
                cur=2e18;
            }
        }

    }
    cout<<ans<<'\n';
    return 0;
}
