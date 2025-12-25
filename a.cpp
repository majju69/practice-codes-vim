#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x) 
#endif

const int N=2e5+10;
int a[N],pvs[2];
long long dp[2],ndp[2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,s;
        cin>>n>>s;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n-2;++i)
        {
            int lb=min(a[i+1]-s,s),ub=max(a[i+1]-s,s);
            ndp[0]=dp[0];
			ndp[1]=dp[1];
            if(lb<0)
            {
                lb=0;
            }
            if(ub>a[i+1])
            {
                ub=a[i+1];
            }
            if(i==0)
            {
                ndp[0]=1ll*a[0]*lb;
                ndp[1]=1ll*a[0]*ub;
            }
            else
            {
                ndp[0]=min(dp[0]+1ll*lb*(a[i]-pvs[0]),dp[1]+1ll*lb*(a[i]-pvs[1]));
                ndp[1]=min(dp[0]+1ll*ub*(a[i]-pvs[0]),dp[1]+1ll*ub*(a[i]-pvs[1]));
            }
            pvs[0]=lb;
            pvs[1]=ub;
            dp[0]=ndp[0];
			dp[1]=ndp[1];
        }
        cout<<min(dp[0]+1ll*a[n-1]*(a[n-2]-pvs[0]),dp[1]+1ll*a[n-1]*(a[n-2]-pvs[1]))<<'\n';
    }
    return 0;
}

/*


s>=xi, s>=ai-xi => xi<=s&&xi>=ai-s => ai-s<=xi<=s

s<=xi, s<=ai-xi => xi>=s&&xi<=ai-s => s<=xi<=ai-s


Take extreme

*/
