#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

ll gcd(ll a,ll b)
{
    return ((b==0)?a:gcd(b,a%b));
}

class SegmentTree
{

private:

    vector<ll> seg;

public:

    SegmentTree(ll n)
    {
        seg.resize(4*n+1);
    }

    void build(ll ind,ll lo,ll hi,vector<ll> &diff)
    {
        if(lo==hi)
        {
            seg[ind]=diff[lo];
            return;
        }
        ll mid=lo+(hi-lo)/2;
        build(2*ind+1,lo,mid,diff);
        build(2*ind+2,mid+1,hi,diff);
        seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
    }

    ll query(ll ind,ll lo,ll hi,ll l,ll r)
    {
        if(l>r)
        {
            return 0;
        }
        if(l>hi||lo>r)
        {
            return 0;
        }
        if(l<=lo&&hi<=r)
        {
            return seg[ind];
        }
        ll mid=lo+(hi-lo)/2;
        return gcd(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
    }

};

ll maxSubarrayLen(vector<ll> &diff)
{
    ll n=diff.size(),l=0,r=0,ans=0;
    SegmentTree st(n);
    st.build(0,0,n-1,diff);
    while(r<n&&l<n)
    {
        if(st.query(0,0,n-1,l,r)==1)
        {
            l++;
        }
        ans=max(ans,r-l+1);
        r++;
    }
    return ans;
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
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        if(n==1)
        {
            cout<<1<<'\n';
        }
        else
        {
            ll ans=1,cnt=0;
            vector<ll> diff(n-1);
            for(ll i=0;i<n-1;++i)
            {
                diff[i]=abs(a[i]-a[i+1]);
                cnt+=(diff[i]==1);
            }
            n--;
            if(cnt==n)
            {
                cout<<1<<'\n';
                continue;
            }
            cout<<maxSubarrayLen(diff)+1<<'\n';
        }
    }
    return 0;
}
