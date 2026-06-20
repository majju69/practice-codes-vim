#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,n;
    ld ans=0;
    cin>>m>>n;
    for(ll i=1;i<=m;++i)
    {
        ans+=1.0l*i*(pow(1.0l*i/m,n)-pow(1.0l*(i-1)/m,n));
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';
    return 0;
}
