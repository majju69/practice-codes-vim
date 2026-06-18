#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int sz=19;
const int MASK=(1<<sz),mod=1e9+7,primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int freq[MASK],dp[MASK],ndp[MASK];

int add(const int &a,const int &b)
{
    return ((a%mod)+(b%mod))%mod;
}

int sub(const int &a,const int &b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
}

int mul(const int &a,const int &b)
{
    return (1ll*(a%mod)*(b%mod))%mod;
}

int power(int a,int b)        // Use when mod is of order 10^9 or less
{
    int ans=1;
    a=a%mod;
    while(b)
    {
        if(b&1)
        {
            ans=(1ll*(ans%mod)*(a%mod))%mod;
        }
        a=(1ll*(a%mod)*(a%mod))%mod;
        b>>=1;
    }
    return ans%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> present;
    vector<pair<int,int>> a;
    for(int i=0;i<n;++i)
    {
        int x,mask=0;
        cin>>x;
        for(int j=0;j<sz;++j)
        {
            const int p=primes[j];
            int cnt=0;
            while(x%p==0)
            {
                cnt=1-cnt;
                x/=p;
            }
            if(cnt==1)
            {
                mask^=(1<<j);
            }
        }
        if(mask==0)
        {
            freq[0]++;
            continue;
        }
        if(freq[mask]==0)
        {
            present.push_back(mask);
        }
        freq[mask]++;
    }
    for(auto &v:present)
    {
        a.push_back({v,freq[v]});
    }
    if(!a.empty())
    {
        dp[a[0].first]=power(2,a[0].second-1);
        dp[0]=sub(power(2,a[0].second-1),1);
        for(int i=1;i<(int)a.size();++i)
        {
            memset(ndp,0,sizeof(ndp));
            const int ways_odd=power(2,a[i].second-1),mask_odd=a[0].first,ways_even=sub(power(2,a[i].second-1),1),cur_mask=a[i].first;
            ndp[cur_mask]=ways_odd;
            ndp[0]=ways_even;
            for(int mask=0;mask<MASK;++mask)
            {
                ndp[mask]=add(ndp[mask],add(dp[mask],mul(dp[mask],ways_even)));
                ndp[mask]=add(ndp[mask],mul(dp[mask^a[i].first],ways_odd));
            }
            memcpy(dp,ndp,sizeof(dp));
        }
    }
    cout<<sub(mul(add(1,dp[0]),power(2,freq[0])),1)<<'\n';    
    return 0;
}
