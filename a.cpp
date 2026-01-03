#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

ll gcd(const ll a,const ll b)
{
    return ((b==0)?a:gcd(b,a%b));
}

inline ll lcm(const ll a,const ll b)
{
    return (a/gcd(a,b))*b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,ans=1,g=0,l=1;
        cin>>n;
        while(n--)
        {
            ll a,b;
            cin>>a>>b;
            l=lcm(l,b);
            g=gcd(g,a*b);
            if(g%l)
            {
                ans++;
                g=a*b;
                l=b;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

