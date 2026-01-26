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

    void build(ll ind,ll lo,ll hi,vector<ll> &a)
    {
        if(lo==hi)
        {
            seg[ind]=a[lo];
            return;
        }
        ll mid=lo+(hi-lo)/2;
        build(2*ind+1,lo,mid,a);
        build(2*ind+2,mid+1,hi,a);
        seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
    }

    ll query(ll ind,ll lo,ll hi,ll l,ll r)
    {
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll> a(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        if(n>1)
        {
            vector<ll> diff(n-1);
            for(ll i=0;i<n-1;++i)
            {
                diff[i]=abs(a[i]-a[i+1]);
            }
            SegmentTree st(n-1);
            st.build(0,0,n-2,diff);
            while(q--)
            {
                ll l,r;
                cin>>l>>r;
                if(l==r)
                {
                    cout<<0<<' ';
                    continue;
                }
                l--;
                r-=2;
                cout<<st.query(0,0,n-2,l,r)<<' ';
            }
            cout<<'\n';
        }
        else
        {
            while(q--)
            {
                ll l,r;
                cin>>l>>r;
                cout<<0<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
