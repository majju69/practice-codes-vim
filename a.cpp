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
        int n,tar=0,s=0,ans=1e9;
        map<int,int> mp;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n));
        for(auto &v:a[0])
        {
            cin>>v;
            tar+=(v==1);
            tar-=(v==2);
        }
        for(auto &v:a[1])
        {
            cin>>v;
            tar+=(v==1);
            tar-=(v==2);
        }
        mp[0]=-1;
        reverse(a[0].begin(),a[0].end());
        for(int i=0;i<n;++i)
        {
            s+=(a[0][i]==1);
            s-=(a[0][i]==2);
            if(!mp.count(s))
            {
                mp[s]=i;
            }
        }
        s=0;
        if(mp.count(tar))
        {
            ans=mp[tar]+1;
        }
        for(int i=0;i<n;++i)
        {
            s+=(a[1][i]==1);
            s-=(a[1][i]==2);
            int req=tar-s;
            if(mp.count(req))
            {
                ans=min(ans,i+mp[req]+2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
