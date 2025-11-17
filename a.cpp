#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=1e9+9;

inline int add(int a,int b)
{
    return ((a%mod)+(b%mod))%mod;
}

inline int mul(int a,int b)
{
    return (1ll*(a%mod)*(b%mod))%mod;
}

inline int sub(int a,int b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
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

inline int divide(int a,int b)
{
    return mul(a,power(b,mod-2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a,b,k,x=-1,s=0;
    string str;
    cin>>n>>a>>b>>k>>str;
    x=divide(b,a),s=0;
    for(int i=0;i<k;++i)
    {
        if(str[i]=='-')
        {
            s=sub(s,power(x,i));
        }
        else
        {
            s=add(s,power(x,i));
        }
    }
    if(power(x,k)!=1)
    {
        cout<<mul(power(a,n),mul(s,divide(sub(power(x,n+1),1),sub(power(x,k),1))))<<'\n';
    }
    else
    {
        cout<<mul(power(a,n),mul(s,(n+1)/k))<<'\n';
    }
    return 0;
}
