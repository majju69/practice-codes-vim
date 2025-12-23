#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=1e9+7;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        if(k>=10)
        {
            cout<<0<<'\n';
        }
        else
        {
            int x=(10/k)+1-((10%k)==0);
            cout<<sub(power(x,r),power(x,l))<<'\n';
        }
    }
    return 0;
}
