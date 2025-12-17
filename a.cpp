#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=1e9+7;

inline int mul(int a,int b)
{
    return (1ll*(a%mod)*(b%mod))%mod;
}

inline int mul(int a,int b,int p)
{
    return (1ll*(a%p)*(b%p))%p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p,k,ans=1;
    cin>>p>>k;
    vector<bool> vis(p,0);
    vis[0]=1;
    for(int i=1;i<p;++i)
    {
        if(!vis[i])
        {
            ans=mul(ans,p);
            int cur=i;
            while(!vis[cur])
            {
                vis[cur]=1;
                cur=mul(cur,k,p);
            }
        }
    }
    if(k==1)
    {
        ans=mul(ans,p);
    }
    cout<<ans<<'\n';
    return 0;
}
