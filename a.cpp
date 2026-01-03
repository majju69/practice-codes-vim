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
        int n,pvs=0;
        long long ans=0;
        cin>>n;
        vector<int> a(n),cost(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        for(int i=1;i<n;++i)
        {
            if(a[i]==a[i-1])
            {
                cost[i]=0;
            }
            else if(a[i]>a[i-1])
            {
                int cnt=0,x=a[i-1];
                while(a[i]>=x)
                {
                    x<<=1;
                    cnt++;
                }
                cnt--;
                cost[i]=-cnt;
            }
            else
            {
                int cnt=0,x=a[i];
                while(a[i-1]>x)
                {
                    x<<=1;
                    cnt++;
                }
                cost[i]=cnt;
            }
        }
        for(auto &v:cost)
        {
            ans+=max(v+pvs,0);
            pvs=max(v+pvs,0);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
