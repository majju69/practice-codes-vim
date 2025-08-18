#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

class SegmentTree
{

private:

    vector<ll> seg,lazy;

public:

    SegmentTree(ll n)
    {
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
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
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    void update(ll ind,ll lo,ll hi,ll l,ll r,ll val)
    {
        if(lazy[ind]!=0)
        {
            seg[ind]+=(hi-lo+1)*lazy[ind];
            if(hi!=lo)
            {
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        if(l>hi||lo>r)
        {
            return;
        }
        if(l<=lo&&hi<=r)
        {
            seg[ind]+=val;
            if(hi!=lo)
            {
                lazy[2*ind+1]+=val;
                lazy[2*ind+2]+=val;
            }
            return;
        }
        ll mid=lo+(hi-lo)/2;
        update(2*ind+1,lo,mid,l,r,val);
        update(2*ind+2,mid+1,hi,l,r,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    ll query(ll ind,ll lo,ll hi,ll i)
    {
        if(lazy[ind]!=0)
        {
            seg[ind]+=lazy[ind];
            if(hi!=lo)
            {
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }
        if(lo==hi)
        {
            return seg[ind];
        }
        ll mid=lo+(hi-lo)/2;
        if(i<=mid)
        {
            return query(2*ind+1,lo,mid,i);
        }
        return query(2*ind+2,mid+1,hi,i);
    }

};

bool check(ll mid,ll m,ll w,vector<ll> &vec)
{
    ll n=vec.size(),cost=0;
    vector<ll> a;
    for(ll i=0;i<n;++i)
    {
        a.push_back(max(0LL,mid-vec[i]));
    }
    SegmentTree st(n);
    st.build(0,0,n-1,a);
    for(ll i=0;i<n;++i)
    {
        ll x=st.query(0,0,n-1,i);
        if(x>0)
        {
            cost+=x;
            st.update(0,0,n-1,i,min(i+w-1,n-1),-x);
        }
    }
    return (cost<=m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,w,lo=0,hi=2e9,ans=-1;
    cin>>n>>m>>w;
    vector<ll> a(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    while(lo<=hi)
    {
        ll mid=lo+(hi-lo)/2;
        if(check(mid,m,w,a))
        {
            ans=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
