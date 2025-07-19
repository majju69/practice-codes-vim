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
        ll n,m,sum=0;
        cin>>n>>m;
        vector<ll> arr(n),a[2];
        for(auto &v:arr)
        {
            cin>>v;
            sum+=v;
        }
        for(ll i=0;i<n;++i)
        {
            ll x;
            cin>>x;
            x--;
            a[x].push_back(arr[i]);
        }
        if(sum<m)
        {
            cout<<-1<<'\n';
            continue;
        }
        sort(a[0].rbegin(),a[0].rend());
        sort(a[1].rbegin(),a[1].rend());
        if((ll)a[0].size()>0)
        {
            ll s=0,cnt2=0,ans=1e9;
            vector<ll> pre;
            pre.push_back(a[0][0]);
            for(ll i=1;i<(ll)a[0].size();++i)
            {
                pre.push_back(pre.back()+a[0][i]);
            }
            if(pre.back()>=m)
            {
                ans=0;
                for(auto &v:pre)
                {
                    ans++;
                    if(v>=m)
                    {
                        break;
                    }
                }
            }
            for(ll i=0;i<(ll)a[1].size();++i)
            {
                s+=a[1][i];
                cnt2+=2;
                if(s>=m)
                {
                    ans=min(ans,cnt2);
                    break;
                }
                ll req=m-s;
                ll idx=lower_bound(pre.begin(),pre.end(),req)-pre.begin();
                if(idx<(ll)pre.size())
                {
                    ans=min(ans,idx+1+cnt2);
                }
            }
            cout<<ans<<'\n';
        }
        else
        {
            ll s=0,ans=0;
            for(auto &v:a[1])
            {
                s+=v;
                ans+=2;
                if(s>=m)
                {
                    break;
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
