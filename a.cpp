#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=105,M=105,K=15;
int dp[N][M][K],a[N][M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n,m,k,idx=-1,mx=-1;
    cin>>n>>m>>k;
    k++;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;++j)
        {
            a[i][j]=(s[j]-'0');
        }
    }
    for(int i=n-1;i>=0;--i)
    {
        if(i==n-1)
        {
            for(int j=0;j<m;++j)
            {
                dp[i][j][a[i][j]%k]=a[i][j];
            }
        }
        else
        {
            for(int j=0;j<m;++j)
            {
                if(j+1<m)
                {
                    for(int rem=0;rem<k;++rem)
                    {
                        if(dp[i+1][j+1][(rem-(a[i][j]%k)+k)%k]!=-1)
                        {
                            dp[i][j][rem]=max(dp[i][j][rem],dp[i+1][j+1][(rem-(a[i][j]%k)+k)%k]+a[i][j]);
                        }
                    }
                }
                if(j-1>=0)
                {
                    for(int rem=0;rem<k;++rem)
                    {
                        if(dp[i+1][j-1][(rem-(a[i][j]%k)+k)%k]!=-1)
                        {
                            dp[i][j][rem]=max(dp[i][j][rem],dp[i+1][j-1][(rem-(a[i][j]%k)+k)%k]+a[i][j]);
                        }
                    }

                }
            }
        }
    }
    for(int j=0;j<m;++j)
    {
        if(dp[0][j][0]>mx)
        {
            mx=dp[0][j][0];
            idx=j;
        }
    }
    if(mx==-1)
    {
        cout<<-1<<'\n';
    }
    else
    {
        cout<<mx<<'\n';
        int cur_idx=idx,cur_rem=0;
        string ans;
        for(int i=1;i<n;++i)
        {
            if(cur_idx+1<m&&dp[i][cur_idx+1][(cur_rem-(a[i-1][cur_idx])%k+k)%k]==dp[i-1][cur_idx][cur_rem]-a[i-1][cur_idx])
            {
                ans.push_back('L');
                cur_rem=(cur_rem-(a[i-1][cur_idx])%k+k)%k;
                cur_idx++;
                continue;
            }
            ans.push_back('R');
            cur_rem=(cur_rem-(a[i-1][cur_idx])%k+k)%k;
            cur_idx--;
        }
        reverse(ans.begin(),ans.end());
        cout<<cur_idx+1<<'\n'<<ans<<'\n';
    }
    return 0;
}
