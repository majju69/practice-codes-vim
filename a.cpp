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
    int n,m,mx=-1e9,len=-1,ans=1e9;
    cin>>n>>m;
    vector<pair<int,int>> a(n),b(m),res;
    vector<int> suf;
    for(auto &v:a)
    {
        cin>>v.first>>v.second;
    }
    for(auto &v:b)
    {
        cin>>v.first>>v.second;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            res.push_back({max(0,b[j].first-a[i].first+1),max(0,b[j].second-a[i].second+1)});
        }
    }
    sort(res.begin(),res.end());
    len=res.size();
    suf.resize(len);
    for(int i=len-1;i>=0;--i)
    {
        mx=max(mx,res[i].second);
        suf[i]=mx;
    }
    ans=suf[0];
    for(int i=0;i<len;++i)
    {
        int right=((i+1>=len)?0:suf[i+1]);
        ans=min(ans,res[i].first+right);
    }
    cout<<ans<<'\n';
    return 0;
}
