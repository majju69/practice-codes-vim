#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

vector<long long> spf(10000001,0);

void smallestPrimeFactor()
{
    long long n=spf.size();
    for(long long i=1;i<n;++i)
    {
        spf[i]=i;
    }
    for(long long i=4;i<n;i+=2)
    {
        spf[i]=2;
    }
    for(long long i=3;i*i<n;++i)
    {
        if(spf[i]==i)
        {
            for(long long j=i*i;j<n;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }   
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    smallestPrimeFactor();
    ll n,k,ans1=0,ans2=0;
    map<map<ll,ll>,ll> mp;
    cin>>n>>k;
    for(ll i=0;i<n;++i)
    {
        ll x;
        map<ll,ll> cur;
        cin>>x;
        while(x>1)
        {
            ll cnt=0,p=spf[x];
            while(x%p==0)
            {
                x/=p;
                cnt++;
            }
            cnt%=k;
            if(cnt>0)
            {
                cur[p]=cnt;
            }
        }
        mp[cur]++;
    }
    for(auto &v:mp)
    {
        ll cnt=v.second;
        map<ll,ll> cur=v.first,req;
        for(auto &v1:cur)
        {
            req[v1.first]=(k-v1.second)%k;
        }
        if(req==v.first)
        {
            ans1+=((cnt*(cnt-1))>>1);
        }
        else
        {
            if(mp.find(req)!=mp.end())
            {
                ans2+=cnt*mp[req];
            }
        }
    }
    cout<<(ans2>>1)+ans1<<'\n';
    return 0;
}
