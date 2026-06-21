#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long double ld;

const ld eps=1e-10;
ld a[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ld mx=0.0l;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(abs(a[i]-1.0l)<=eps)
        {
            mx=1.0l;
        }
    }
    if(abs(mx-1.0l)>eps)
    {
        ld sum=0.0l,pro=1.0l;
        sort(a,a+n);
        reverse(a,a+n);
        for(int i=0;i<n;++i)
        {
            mx=max(mx,sum*pro);
            sum+=a[i]/(1.0l-a[i]);
            pro*=(1.0l-a[i]);
            mx=max(mx,sum*pro);
        }
    }
    cout<<fixed<<setprecision(10)<<mx<<'\n';
    return 0;
}
