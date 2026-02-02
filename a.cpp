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
        int n,ax,ay,bx,by,ans=0;
        long long dp[]={0,0},ndp[]={-1,-1};
        cin>>n>>ax>>ay>>bx>>by;
        map<int,pair<int,int>> mp;
        mp[ax]={ay,ay};
        mp[bx]={by,by};
        vector<int> x(n),y(n);
        vector<pair<int,int>> a;
        for(auto &v:x)
        {
            cin>>v;
        }
        for(auto &v:y)
        {
            cin>>v;
        }
        for(int i=0;i<n;++i)
        {
            if(!mp.count(x[i]))
            {
                mp[x[i]]={y[i],y[i]};
            }
            else
            {
                mp[x[i]].first=min(mp[x[i]].first,y[i]);
                mp[x[i]].second=max(mp[x[i]].second,y[i]);
            }
        }
        ans=bx-ax;
        for(auto &v:mp)
        {
            a.push_back(v.second);
        }
        n=a.size();
        for(int i=1;i<n;++i)
        {
            ndp[0]=min(dp[0]+abs(a[i-1].first-a[i].second),dp[1]+abs(a[i-1].second-a[i].second))+(a[i].second-a[i].first);
            ndp[1]=min(dp[0]+abs(a[i-1].first-a[i].first),dp[1]+abs(a[i-1].second-a[i].first))+(a[i].second-a[i].first);
            dp[0]=ndp[0];
            dp[1]=ndp[1];
        }
        cout<<ans+min(dp[0],dp[1])<<'\n';
    }
    return 0;
}
