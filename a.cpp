#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

ll nCr(ll n,ll k)
{
    if(k>n||n<0||k<0)
    {
        return 0;
    }
    ll num=1,den=1;
    for(ll i=0;i<k;++i)
    {
        num*=(n-i);
        den*=(i+1);
    }
    return num/den;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,ans=0,d[]={1,0,1,2,9};
    cin>>n>>k;
    for(ll i=0;i<=k;++i)
    {
        ans+=nCr(n,i)*d[i];
    }
    cout<<ans<<'\n';
    return 0;
}
