#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

bool check(int mid,int w,int f,vector<bool> &dp)
{
    int n=dp.size();
    for(int i=0;i<=(n>>1);++i)
    {
        if(!dp[i])
        {
            continue;
        }
        if(mid*f>=i&&mid*w>=(n-1-i))
        {
            return 1;
        }
    }
    return 0;
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
        int w,f,n,s=0,lo=1,hi=0,ans=-1;
        cin>>w>>f>>n;
        vector<int> a(n);
        for(auto &v:a)
        {
            cin>>v;
            s+=v;
        }
        if(w<f)
        {
            swap(w,f);
        }
        hi=(s+w-1)/w;
        vector<bool> dp(s+1,0),ndp;
        dp[0]=1;
        for(int i=0;i<n;++i)
        {
            ndp=dp;
            for(int j=0;j<=s;++j)
            {
                if(j-a[i]>=0)
                {
                    ndp[j]=(ndp[j]||dp[j-a[i]]);
                }
            }
            dp=ndp;
        }
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(mid,w,f,dp))
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
