#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

bool check(int mid,vector<int> &a,vector<int> &b)
{
    int n=a.size(),pvs=-1,cnt=0;
    for(int i=0;i<n;++i)
    {
        int up=(a[i]>=mid),down=(b[i]>=mid);
        if(up==down)
        {
            if(up==1)
            {
                cnt++;
                pvs=1;
            }
            else
            {
                if(pvs!=0)
                {
                    cnt--;
                    pvs=0;
                }
            }
        }
    }
    return (cnt>0);
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
        int n,lo=1e9,hi=-1e9,ans=-1;
        cin>>n;
        vector<int> a(n),b(n);
        for(auto &v:a)
        {
            cin>>v;
            lo=min(lo,v);
            hi=max(hi,v);
        }
        for(auto &v:b)
        {
            cin>>v;
            lo=min(lo,v);
            hi=max(hi,v);
        }
        while(lo<=hi)
        {
            int mid=lo+((hi-lo)>>1);
            if(check(mid,a,b))
            {
                ans=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
