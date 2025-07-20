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
    ll n,k,maxx=-1,num=1e18;
    cin>>n>>k;
    vector<ll> a(n),pre(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    sort(a.begin(),a.end());
    pre[0]=a[0];
    for(ll i=1;i<n;++i)
    {
        pre[i]=pre[i-1]+a[i];
    }
    for(ll i=0;i<n;++i)
    {
        // idx-->a[i]-a[idx] idx+1-->a[i]-a[idx+1] ...... i-->a[i]-a[i]
        // total=(i-idx+1)*a[i]-pre[i]+pre[idx-1]
        ll lo=0,hi=i,idx=-1;
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2;
            ll sum=(i-mid+1)*a[i]-pre[i];
            if(mid!=0)
            {
                sum+=pre[mid-1];
            }
            if(sum<=k)
            {
                idx=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        if(i-idx+1>maxx)
        {
            maxx=i-idx+1;
            num=a[i];
        }
        else if(i-idx+1==maxx)
        {
            num=min(num,a[i]);
        }
        else
        {
            continue;
        }
    }
    cout<<maxx<<' '<<num<<'\n';
    return 0;
}
