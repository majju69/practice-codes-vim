#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

inline ll add(const ll a,const ll b)
{
    return ((a%mod)+(b%mod))%mod;
}

inline ll mul(const ll a,const ll b)
{
    return ((a%mod)*(b%mod))%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n=0,_s=0,ans=0;
        vector<ll> pre;
        map<ll,vector<ll>> mp,mp_suf;
        string s;
        cin>>s;
        n=s.size();
        for(ll i=0;i<n;++i)
        {
            _s+=((s[i]=='1')?1:-1);
            pre.push_back(_s);
            mp[_s].push_back(i);
        }
        for(auto &v:mp)
        {
            ll x=v.first,cur=0;
            vector<ll> &vec=v.second,suf;
            reverse(vec.begin(),vec.end());
            for(auto &v1:vec)
            {
                cur+=(n-v1);
                suf.push_back(cur);
            }
            reverse(vec.begin(),vec.end());
            reverse(suf.begin(),suf.end());
            mp_suf[x]=suf;
        }
        for(ll i=0;i<n;++i)
        {
            // a[i]+...+a[r]=0 => pre[r]-pre[i-1]=0 => pre[r]=pre[i-1]
            ll req=((i==0)?0:pre[i-1]);
            if(mp.count(req))
            {
                const vector<ll> &vec=mp[req];
                ll idx=lower_bound(vec.begin(),vec.end(),i)-vec.begin();
                if(idx<(ll)vec.size())
                {
                    ans=add(ans,mul(i+1,mp_suf[req][idx]));
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
} 
