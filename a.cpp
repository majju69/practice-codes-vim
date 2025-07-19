#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

inline ll mul(ll a,ll b)
{
    return (a%mod*b%mod)%mod;
}

inline ll add(ll a,ll b)
{
    return (a%mod+b%mod)%mod;
}

vector<long long> fact(1000001),calc(1000001);

void fillFact()
{
    long long n=fact.size();
    fact[0]=1;
    for(long long i=1;i<n;++i)
    {
        fact[i]=(i%mod*fact[i-1]%mod)%mod;
    }
}

void fillCalc()
{
    ll n=calc.size();
    calc[3]=3;
    for(ll i=4;i<n;++i)
    {
        calc[i]=mul(i,calc[i-1]-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<'\n';
    }
    else if(n==2)
    {
        cout<<2<<'\n';
    }
    else
    {
        fillFact();
        fillCalc();
        cout<<add(mul(fact[n],n-2),calc[n])<<'\n';
    }
    return 0;
}
