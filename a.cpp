#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,sum=0,pvs=1e18;
        bool ok=1;
        cin>>n;
        vector<ll> a(n<<1);
        for(auto &v:a)
        {
            cin>>v;
        }
        sort(a.begin(),a.end());
        while(n>0)
        {
            if(a[2*n-1]!=a[2*n-2])
            {
                ok=0;
                break;
            }
            if((a[2*n-1]-2*sum)%(n<<1)||(a[2*n-1]-2*sum)<=0)
            {
                ok=0;
                break;
            }
            ll cur=(a[2*n-1]-2*sum)/(n<<1);
            if(cur>=pvs)
            {
                ok=0;
                break;
            }
            pvs=cur;
            sum+=cur;
            n--;
            a.pop_back();
            a.pop_back();
        }
        cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0;
}


// b+x+b-x=2b
