#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int gcd(int a,int b)
{
    return ((b==0)?a:gcd(b,a%b));
}

int get(int n,set<int> &bad)
{
    int ans=0,inc=(bad.count(2)?-1:1);
    while((n&1)==0)
    {
        ans+=inc;
        n>>=1;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0)
        {
            inc=(bad.count(i)?-1:1);
            while(n%i==0)
            {
                n/=i;
                ans+=inc;
            }
        }
    }
    if(n>2)
    {
        inc=(bad.count(n)?-1:1);
        ans+=inc;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,g=0;
    set<int> bad;
    cin>>n>>m;
    vector<int> a(n),score[2];
    vector<vector<int>> dp(n,vector<int>(n+1,-1e9));
    for(auto &v:a)
    {
        cin>>v;
    }
    while(m--)
    {
        int x;
        cin>>x;
        bad.insert(x);
    }
    for(auto &v:a)
    {
        g=gcd(g,v);
        score[0].push_back(get(v,bad));
        score[1].push_back(get(g,bad));
    }
    dp[n-1][n-1]=score[0][n-1]-score[1][n-1];
    dp[n-1][n]=score[0][n-1];
    for(int i=n-2;i>=0;--i)
    {
        dp[i][i]=score[0][i]-score[1][i]+(*max_element(dp[i+1].begin(),dp[i+1].end()));
        dp[i][n]=score[0][i]+dp[i+1][n];
        for(int j=i+1;j<n;++j)
        {
            dp[i][j]=score[0][i]-score[1][j]+dp[i+1][j];
        }
    }
    cout<<(*max_element(dp[0].begin(),dp[0].end()))<<'\n';
    return 0;
}
