#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,k,rem=-1,mul=1,a=-1,b=-1,c=-1;
        cin>>n>>k;
        rem=k-3;
        n-=rem;
        while(1)
        {
            if(n==4)
            {
                a=mul;
                b=mul;
                c=(mul<<1);
                break;
            }
            if(n&1)
            {
                a=mul*(n>>1);
                b=mul*(n>>1);
                c=mul;
                break;
            }
            mul<<=1;
            n>>=1;
        }
        cout<<a<<' '<<b<<' '<<c<<' ';
        while(rem--)
        {
            cout<<1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
