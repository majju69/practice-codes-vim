#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

inline bool bit(int a,int i)
{
    return a>>i&1;
}

inline bool check(int n)
{
    assert(n<16);
    return !((bit(n,0)==bit(n,1)&&bit(n,1)==bit(n,2))||(bit(n,1)==bit(n,2)&&bit(n,2)==bit(n,3)));
}

int dp[200001][4];

int solve(int i,int pvs,int endStart,vector<int> &a)
{
    if(i==(int)a.size()-2)
    {
        int mask=(pvs<<2)+(endStart>>2);
        if(check(mask))
        {
            return 0;
        }
        return 1e9;
    }
    if(dp[i][pvs]!=-1)
    {
        return dp[i][pvs];
    }
    if(bit(pvs,0)==bit(pvs,1))
    {
        if(a[i]!=bit(pvs,0))
        {
            return dp[i][pvs]=solve(i+1,((pvs&1)<<1)+a[i],endStart,a);
        }
        return dp[i][pvs]=solve(i+1,((pvs&1)<<1)+1-a[i],endStart,a)+1;
    }
    return dp[i][pvs]=min(solve(i+1,((pvs&1)<<1)+a[i],endStart,a),solve(i+1,((pvs&1)<<1)+1-a[i],endStart,a)+1);
}

int getMin(vector<int> &a)
{
    int n=a.size(),ans=1e9;
    for(int mask=0;mask<16;++mask)
    {
        if(check(mask))
        {
            int cur=((bit(mask,3)!=a[n-2])+(bit(mask,2)!=a[n-1])+(bit(mask,1)!=a[0])+(bit(mask,0)!=a[1]));
            for(int i=0;i<=n;++i)
            {
                memset(dp[i],-1,sizeof(dp[i]));
            }
            cur+=solve(2,(mask&3),mask,a);
            ans=min(ans,cur);
        }
    }
    return ans;
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
        string s;
        vector<int> a;
        cin>>n>>s;
        for(auto &v:s)
        {
            a.push_back(v=='R');
        }
        if(n<=5)
        {
            int ans=1e9;
            for(int mask=0;mask<(1<<n);++mask)
            {
                bool ok=1;
                for(int i=0;i<n;++i)
                {
                    if(bit(mask,i)==bit(mask,(i+1)%n)&&bit(mask,(i+1)%n)==bit(mask,(i+2)%n))
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)
                {
                    int cur=0;
                    for(int i=0;i<n;++i)
                    {
                        cur+=(bit(mask,i)!=a[i]);
                    }
                    ans=min(ans,cur);
                }
            }
            cout<<ans<<'\n';
        }
        else
        {
            cout<<getMin(a)<<'\n';
        }
    }
    return 0;
}
