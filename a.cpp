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
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    if(n==1)
    {
        cout<<"1 1\n"<<-a[0]<<"\n1 1 \n0\n1 1 \n0\n";
    }
    else
    {
        cout<<"1 "<<n<<'\n';
        for(ll i=0;i<n;++i)
        {
            ll rem=((n-1)-((a[i]%(n-1))+(n-1))%(n-1))%(n-1);
            a[i]+=rem*n;
            cout<<rem*n<<' ';
        }
        cout<<'\n';
        cout<<"1 "<<n-1<<'\n';
        for(ll i=0;i<n-1;++i)
        {
            cout<<-a[i]<<' ';
            a[i]=0;
        }
        cout<<'\n';
        cout<<"2 "<<n<<'\n';
        for(ll i=1;i<n;++i)
        {
            cout<<-a[i]<<' ';
            a[i]=0;
        }
        cout<<'\n';
    }
    return 0;
}
