#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

inline bool bit(long long a,int i)
{
    return a>>i&1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long s,x;
    cin>>s>>x;
    if(s<x||((s-x)&1))
    {
        cout<<0<<'\n';
    }
    else
    {
        long long a=((s-x)>>1),ans=1;
        for(int i=0;i<45;++i)
        {
            if(bit(x,i))
            {
                if(bit(a,i))
                {
                    ans=0;
                    break;
                }
                ans<<=1;
            }
        }
        if(s==x&&ans!=0)
        {
            ans-=2;
            ans=max(ans,0ll);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
