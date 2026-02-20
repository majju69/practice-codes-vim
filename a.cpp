#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const long long mod=1e9+7;

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

inline long long get(const long long a,const long long b)
{
    return power(power(2,a),b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n,m,k;
    cin>>n>>m>>k;
    cout<<((k==-1&&(abs(n-m)&1))?0:get(n-1,m-1));
    return 0;
}
