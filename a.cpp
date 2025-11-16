#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int dp[201][402];

int solve(int i,int j,vector<int> &a)
{
    if(i>=(int)a.size())
    {
        return 0;
    }
    if(j>2*(int)a.size())
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    return dp[i][j]=min(solve(i,j+1,a),solve(i+1,j+1,a)+abs(j-a[i]));
}

int minTime(vector<int> &a)
{
    int n=a.size();
    sort(a.begin(),a.end());
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=2*n+1;++j)
        {
            dp[i][j]=-1;
        }
    }
    return solve(0,1,a);
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
        vector<int> a(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        cout<<minTime(a)<<'\n';
    }
    return 0;
}
