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
        int dp[]={0,(int)1e9},ndp[]={-1,-1},n=0;
        string s,t;
        cin>>s>>t;
        n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0'&&t[i]=='0')
            {
                ndp[0]=min(dp[0],dp[1]+1);
                ndp[1]=min(dp[0]+2,dp[1]+1);
            }
            if(s[i]=='0'&&t[i]=='1')
            {
                ndp[0]=min(dp[0]+1,dp[1]+2);
                ndp[1]=min(dp[0]+1,dp[1]);
            }
            if(s[i]=='1'&&t[i]=='0')
            {
                ndp[0]=min(dp[0]+1,dp[1]);
                ndp[1]=min(dp[0]+1,dp[1]+2);
            }
            if(s[i]=='1'&&t[i]=='1')
            {
                ndp[0]=min(dp[0]+2,dp[1]+1);
                ndp[1]=min(dp[0],dp[1]+1);
            }
            dp[0]=ndp[0];
            dp[1]=ndp[1];
        }
        cout<<min(dp[0],dp[1])<<'\n';
    }
    return 0;
}
