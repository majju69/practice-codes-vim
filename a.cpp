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
        int n,pvs=-1,a0=-1,mn_val=0;
        cin>>n;
        while(n--)
        {
            if(pvs==-1)
            {
                cin>>pvs;
                a0=pvs;
            }
            else
            {
                int x;
                cin>>x;
                mn_val+=max(0,pvs-x);
                pvs=x;
            }
        }
        cout<<((a0<mn_val)?"NO":"YES")<<'\n';
    }
    return 0;
}
