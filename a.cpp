#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=1e9+7,N=105,SZ=27;
int dp[N][N*SZ];

int add(const int &a,const int &b)
{
    return ((a%mod)+(b%mod))%mod;
}

int sub(const int &a)
{
    return ((a%mod)-1+mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[0][0]=1;
    for(int i=1;i<N;++i)
    {
        for(int c=1;c<SZ;++c)
        {
            for(int s=0;s<N*SZ;++s)
            {
                if(s<c)
                {
                    continue;
                }
                dp[i][s]=add(dp[i][s],dp[i-1][s-c]);
            }
        }
    }
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;
        const int n=s.size();
        int tar=0;
        for(auto &v:s)
        {
            tar+=((v-'a')+1);
        }
        cout<<sub(dp[n][tar])<<'\n';
    }
    return 0;
}
