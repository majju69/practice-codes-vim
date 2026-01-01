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
        int n,dp[]={1,0,0,0},ndp[]={-1,-1,-1,-1};
        string s[2];
        cin>>n>>s[0]>>s[1];
        for(int i=0;i<n;++i)
        {
            memset(ndp,0,sizeof(ndp));
            if(s[0][i]=='#'&&s[1][i]=='#')
            {
                ndp[0]=dp[0];
            }
            if(s[0][i]=='#'&&s[1][i]!='#')
            {
                ndp[0]=dp[1];
                ndp[1]=dp[0];
            }
            if(s[0][i]!='#'&&s[1][i]=='#')
            {
                ndp[0]=dp[2];
                ndp[2]=dp[0];
            }
            if(s[0][i]!='#'&&s[1][i]!='#')
            {
                ndp[0]=dp[0]+dp[3];
                ndp[3]=dp[0];
                ndp[1]=dp[2];
                ndp[2]=dp[1];
            }
            for(int j=0;j<4;++j)
            {
                dp[j]=ndp[j];
                if(dp[j]>2)
                {
                    dp[j]=2;
                }
            }
        }
        if(dp[0]==0)
        {
            cout<<"None\n";
        }
        else if(dp[0]==1)
        {
            cout<<"Unique\n";
        }
        else
        {
            cout<<"Multiple\n";
        }
    }
    return 0;
}
