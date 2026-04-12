#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

inline char get(int n)
{
    return (char)(n+'0');
}

int dp[32][62][3][3];

int solve(int i,int k,int tight,int put,string &s)
{
    if(i>=(int)s.size())
    {
        return 1;      // maybe return 1 also works
    }
    if(dp[i][k][tight][put]!=-1)
    {
        return dp[i][k][tight][put];
    }
    int ans=0,till=(tight?(s[i]-'0'):1);
    for(int j=0;j<=till;++j)
    {
        if(!put)
        {
            if(j==0)
            {
                ans+=solve(i+1,k,(tight&&j==till),0,s);
            }
            else
            {
                if(k>=2)
                {
                    ans+=solve(i+1,k-2,(tight&&j==till),1,s);
                }
            }
        }
        else
        {
            if(j==0)
            {
                if(k>=1)
                {
                    ans+=solve(i+1,k-1,(tight&&j==till),1,s);
                }
            }
            else
            {
                if(k>=2)
                {
                    ans+=solve(i+1,k-2,(tight&&j==till),1,s);
                }
            }
        }
    }
    return dp[i][k][tight][put]=ans;
}

int get(int k,string &s)
{
    memset(dp,-1,sizeof(dp));
    return solve(0,k,1,0,s);
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
        int n,k;
        cin>>n>>k;
        if(k>=60)
        {
            cout<<0<<'\n';
        }
        else
        {
            int _n=n,x=-1;
            string s;
            while(_n>0)
            {
                s.push_back(get(_n&1));
                _n>>=1;
            }
            reverse(s.begin(),s.end());
            x=get(k+1,s);
            cout<<n-x+1<<'\n';
        }
    }
    return 0;
} 
