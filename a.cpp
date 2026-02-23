#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=998244353;

inline int add(int a,int b)
{
    return ((a%mod)+(b%mod))%mod;
}

inline int mul(int a,int b)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,s=0,ans=0;
    string a,b;
    cin>>n>>m>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(n<m)
    {
        a.push_back('0');
        n++;
    }
    while(m<n)
    {
        b.push_back('0');
        m++;
    }
    assert(n==m);
    vector<int> suf(n);
    for(int i=n-1;i>=0;--i)
    {
        s+=(b[i]-'0');
        suf[i]=s;
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]=='1')
        {
            ans=add(ans,mul(suf[i],power(2,i)));
        }
    }
    cout<<ans<<'\n';
    return 0;
}
