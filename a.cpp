#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

vector<long long> lpf(300001,0);
vector<long long> primes;

void leastPrimeFactor()
{
    long long n=lpf.size();
    for(long long i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
        }
        for(long long j=0;i*primes[j]<n;++j)
        {
            lpf[i*primes[j]]=primes[j];
            if(primes[j]==lpf[i])
            {
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    leastPrimeFactor();
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        bool zero=0;
        map<ll,ll> mp;
        cin>>n;
        vector<ll> a(n),b(n);
        for(auto &v:a)
        {
            cin>>v;
            ll x=v;
            while(x>1)
            {
                ll p=lpf[x];
                mp[p]++;
                if(mp[p]>1)
                {
                    zero=1;
                    break;
                }
                while(x%p==0)
                {
                    x/=p;
                }
            }
        }
        for(auto &v:b)
        {
            cin>>v;
        }
        if(zero)
        {
            cout<<0<<'\n';
        }
        else
        {
            ll ans=1e18;
            vector<ll> idx;
            for(ll i=0;i<n;++i)
            {
                ll v=a[i];
                ll x=v;
                while(x>1)
                {
                    ll p=lpf[x];
                    mp[p]--;
                    while(x%p==0)
                    {
                        x/=p;
                    }
                }
                x=v+1;
                while(x>1)
                {
                    ll p=lpf[x];
                    if(mp[p]>0)
                    {
                        idx.push_back(i);
                        break;
                    }
                    while(x%p==0)
                    {
                        x/=p;
                    }
                }
                x=v;
                while(x>1)
                {
                    ll p=lpf[x];
                    mp[p]++;
                    while(x%p==0)
                    {
                        x/=p;
                    }
                }
            }
            if((ll)idx.size()>0)
            {
                for(auto &v:idx)
                {
                    ans=min(ans,b[v]);
                }
            }
            vector<pair<ll,ll>> odd,even,res;
            for(ll i=0;i<n;++i)
            {
                if(a[i]&1)
                {
                    odd.push_back({b[i],a[i]});
                }
                else
                {
                    even.push_back({b[i],a[i]});
                }
                res.push_back({b[i],a[i]});
            }
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            sort(res.begin(),res.end());
            if((ll)even.size()>0&&odd[0].first<=even[0].first)
            {
                ans=min(ans,odd[0].first);
            }
            else
            {
                ans=min(ans,res[0].first+res[1].first);
                vector<ll> cur_primes;
                for(ll i=1;i<n;++i)
                {
                    ll x=res[i].second;
                    while(x>1)
                    {
                        ll p=lpf[x];
                        cur_primes.push_back(p);
                        while(x%p==0)
                        {
                            x/=p;
                        }
                    }
                }
                for(auto &v:cur_primes)
                {
                    ans=min(ans,((v-res[0].second%v)%v)*res[0].first);
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
