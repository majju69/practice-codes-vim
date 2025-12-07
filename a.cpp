#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=998244353;

inline int add(int a,int b)
{
    return ((a%mod)+(b%mod))%mod;
}

inline int mul(int a,int b)
{
    return (1ll*(a%mod)*(b%mod))%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,ans=0;
    cin>>n;
    vector<int> a(n),cnt(2,0),sum(2,0),_cnt(2,0),_sum(2,0);
    for(auto &v:a)
    {
        cin>>v;
    }
    for(int i=0;i<30;++i)
    {
        int cur_ans=0;
        cnt[0]=cnt[1]=0;
        sum[0]=sum[1]=0;
        for(auto &v:a)
        {
            bool bit=(v>>i&1);
            if(!bit)
            {
                _cnt[0]=cnt[0]+1;
                _cnt[1]=cnt[1];
                _sum[0]=add(1,add(sum[0],cnt[0]));
                _sum[1]=add(sum[1],cnt[1]);
            }
            else
            {
                _cnt[0]=cnt[1];
                _cnt[1]=cnt[0]+1;
                _sum[0]=add(sum[1],cnt[1]);
                _sum[1]=add(1,add(sum[0],cnt[0]));
            }
            cnt=_cnt;
            sum=_sum;
            cur_ans=add(cur_ans,sum[1]);
        }
        cur_ans=mul(cur_ans,(1<<i));
        ans=add(ans,cur_ans);
    }
    cout<<ans<<'\n';
    return 0;
}
