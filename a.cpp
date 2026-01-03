#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,m,d,sum=0,ans=0;
        multiset<ll> st;
        cin>>n>>m>>d;
        for(ll i=1;i<=n;++i)
        {
            ll x;
            cin>>x;
            if(x<=0)
            {
                continue;
            }
            if((ll)st.size()<m) 
            {
                sum+=x;
                st.insert(x);
            }
            else
            {
                auto it=st.begin();
                sum-=*it;
                st.erase(it);
                sum+=x;
                st.insert(x);
            }
            ans=max(ans,sum-i*d);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
