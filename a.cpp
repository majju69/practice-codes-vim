#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2e5+10;
int pre[N];

inline int get(int l,int r)
{
    if(r<l)
    {
        return 0;
    }
    return (pre[r]-((l==0)?0:pre[l-1]));
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
        memset(pre,0,sizeof(pre));
        int n,y;
        long long ans=-1e18;
        cin>>n>>y;
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            pre[x]++;
        }
        for(int i=1;i<N;++i)
        {
            pre[i]+=pre[i-1];
        }
        for(int i=2;i<N;++i)
        {
            int new_tags=0;
            long long price=0;
            for(int j=0;j<N;j+=i)
            {
                int lb=j+1,ub=min(N-1,j+i);
                new_tags+=max(get(lb,ub)-get((j+i)/i,(j+i)/i),0);
                price+=1ll*get(lb,ub)*((j+i)/i);
            }
            ans=max(ans,price-1ll*y*new_tags);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
