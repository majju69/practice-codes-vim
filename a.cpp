#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

inline bool get(int n)
{
    if(n&1)
    {
        return 0;
    }
    if((n&(n-1))==0&&(__builtin_ctz(n)&1))
    {
        return 0;
    }
    return 1;
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
        int n;
        cin>>n;
        cout<<(get(n)?"Alice":"Bob")<<'\n';
    }
    return 0;
}
