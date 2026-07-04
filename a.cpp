#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;
const ll mod=998244353,mult[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000};
ll cnt[20][2][2][1024],dp[20][2][2][1024];

ll add(const ll &a,const ll &b)
{
    return ((a%mod)+(b%mod))%mod;
}

ll mul(const ll &a,const ll &b)
{
    return ((a%mod)*(b%mod))%mod;
}

ll sub(const ll &a,const ll &b)
{
    return ((a%mod)-(b%mod)+mod)%mod;
}

ll get(ll i,bool put,bool tight,ll mask,const ll &k,const string &s)
{
    if(i>=(ll)s.size())
    {
        return __builtin_popcountll(mask)<=k;
    }
    if(cnt[i][put][tight][mask]!=-1)
    {
        return cnt[i][put][tight][mask];
    }
    ll ans=0,till=(tight?(s[i]-'0'):9);
    for(ll j=0;j<=till;++j)
    {
        if(j==0&&!put)
        {
            ans+=get(i+1,0,(tight&&(j==till)),mask,k,s);
        }
        else
        {
            ans+=get(i+1,1,(tight&&(j==till)),(mask|(1ll<<j)),k,s);
        }
    }
    return cnt[i][put][tight][mask]=ans;
}

ll solve(ll i,bool put,bool tight,ll mask,const ll &k,const string &s)
{
    if(i>=(ll)s.size())
    {
        return 0;
    }
    if(dp[i][put][tight][mask]!=-1)
    {
        return dp[i][put][tight][mask];
    }
    ll ans=0,till=(tight?(s[i]-'0'):9),placeValue=(ll)s.size()-1-i;
    for(ll j=0;j<=till;++j)
    {
        if(j==0&&!put)
        {
            ans=add(ans,solve(i+1,0,(tight&&(j==till)),mask,k,s));
        }
        else
        {
            ll nmask=(mask|(1ll<<j));
            if(__builtin_popcountll(nmask)<=k)
            {
                ans=add(ans,add(mul(mul(mult[placeValue],j),get(i+1,1,(tight&&(j==till)),nmask,k,s)),solve(i+1,1,(tight&&(j==till)),nmask,k,s)));
            }
        }
    }
    return dp[i][put][tight][mask]=ans;
}

ll get(const ll &n,const ll &k)
{
    memset(dp,-1,sizeof(dp));
    memset(cnt,-1,sizeof(cnt));
    string s=to_string(n);
    return solve(0,0,1,0,k,s);
}

ll get(const ll &l,const ll &r,const ll &k)
{
    return sub(get(r,k),get(l-1,k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll l,r,k;
    cin>>l>>r>>k;
    cout<<get(l,r,k)<<'\n';
    return 0;
}
