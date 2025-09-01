#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

ll get(ll n)
{
    ll ans=0;
    for(ll i=1;i<=n;i*=10)
    {
        ans+=(n-i+1);
    }
    return ans;
}

ll dp[15][127][2];

ll solve(ll i,ll sum,bool last,string &s)
{
    if(i>=(ll)s.size())
    {
        return sum;
    }
    if(dp[i][sum][last]!=-1)
    {
        return dp[i][sum][last];
    }
    ll till=(last?(s[i]-'0'):9),ans=0;
    for(ll j=0;j<=till;++j)
    {
        ans+=(solve(i+1,sum+j,(last&&(j==till)),s));
    }
    return dp[i][sum][last]=ans;
}

ll get_pre(ll x)
{
    memset(dp,-1,sizeof(dp));
    string s=to_string(x);
    return solve(0,0,1,s);
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
        ll k,lo=0,hi=-1,num=0,ans=0;
        cin>>k;
        hi=k;
        while(lo<=hi)
        {
            ll mid=lo+((hi-lo)>>1);
            if(get(mid)<k)
            {
                num=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        ans=get_pre(num);
        k-=get(num);
        num++;
        string tmp=to_string(num);
        for(ll i=0;i<k;++i)
        {
            ans+=(tmp[i]-'0');
        }
        cout<<ans<<'\n';
    }
    return 0;
}
