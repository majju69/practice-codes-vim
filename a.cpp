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
    int n,w,h,mx=0,idx=-1;
    cin>>n>>w>>h;
    vector<int> dp(n,1);
    vector<pair<pair<int,int>,int>> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first.first>>a[i].first.second;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    for(int i=n-2;i>=0;--i)
    {
        for(int j=n-1;j>i;--j)
        {
            if(a[j].first.first>a[i].first.first&&a[j].first.second>a[i].first.second)
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if(a[i].first.first>w&&a[i].first.second>h)
        {
            if(dp[i]>mx)
            {
                mx=dp[i];
                idx=i;
            }
        }
    }
    cout<<mx<<'\n';
    if(idx!=-1)
    {
        int cur=idx;
        vector<int> ans;
        ans.push_back(a[cur].second);
        while(1)
        {
            int nxt=-1;
            for(int i=cur+1;i<n;++i)
            {
                if(a[i].first.first>a[cur].first.first&&a[i].first.second>a[cur].first.second)
                {
                    if(dp[i]==dp[cur]-1)
                    {
                        nxt=i;
                        break;
                    }
                }
            }
            if(nxt==-1)
            {
                break;
            }
            cur=nxt;
            ans.push_back(a[cur].second);
        }
        for(auto &v:ans)
        {
            cout<<v+1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
