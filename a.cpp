#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

inline bool isSetBit(ll a,ll i)
{
    return ((a&(1LL<<i))!=0);
}

vector<ll> merge(vector<ll> &a,vector<ll> &b)
{
    vector<ll> ans(20);
    for(ll i=0;i<20;++i)
    {
        ans[i]=a[i]+b[i];
    }
    return ans;
}

class SegmentTree
{

private:

    vector<vector<ll>> seg;
    vector<ll> lazy;

public:

    SegmentTree(ll n)
    {
        for(ll i=0;i<=4*n;++i)
        {
            vector<ll> tmp(20,0);
            seg.push_back(tmp);
            lazy.push_back(0);
        }
    }

    void build(ll ind,ll lo,ll hi,vector<ll> &a)
    {
        if(lo==hi)
        {
            vector<ll> tmp(20,0);
            for(ll i=0;i<20;++i)
            {
                if(isSetBit(a[lo],i))
                {
                    tmp[i]=1;
                }
            }
            seg[ind]=tmp;
            return;
        }
        ll mid=lo+(hi-lo)/2;
        build(2*ind+1,lo,mid,a);
        build(2*ind+2,mid+1,hi,a);
        seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
    }

    void update(ll ind,ll lo,ll hi,ll l,ll r,ll val)
    {
        if(lazy[ind]!=0)
        {
            for(ll i=0;i<20;++i)
            {
                if(isSetBit(lazy[ind],i))
                {
                    seg[ind][i]=(hi-lo+1)-seg[ind][i];
                }
            }
            if(lo!=hi)
            {
                lazy[2*ind+1]=(lazy[2*ind+1]^lazy[ind]);
                lazy[2*ind+2]=(lazy[2*ind+2]^lazy[ind]);
            }
            lazy[ind]=0;
        }
        if(l>hi||lo>r)
        {
            return;
        }
        if(l<=lo&&hi<=r)
        {
            for(ll i=0;i<20;++i)
            {
                if(isSetBit(val,i))
                {
                    seg[ind][i]=(hi-lo+1)-seg[ind][i];
                }
            }
            if(lo!=hi)
            {
                lazy[2*ind+1]=(lazy[2*ind+1]^val);
                lazy[2*ind+2]=(lazy[2*ind+2]^val);
            }
            return;
        }
        ll mid=lo+(hi-lo)/2;
        update(2*ind+1,lo,mid,l,r,val);
        update(2*ind+2,mid+1,hi,l,r,val);
        seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
    }

    vector<ll> query(ll ind,ll lo,ll hi,ll l,ll r)
    {
        if(lazy[ind]!=0)
        {
            for(ll i=0;i<20;++i)
            {
                if(isSetBit(lazy[ind],i))
                {
                    seg[ind][i]=(hi-lo+1)-seg[ind][i];
                }
            }
            if(lo!=hi)
            {
                lazy[2*ind+1]=(lazy[2*ind+1]^lazy[ind]);
                lazy[2*ind+2]=(lazy[2*ind+2]^lazy[ind]);
            }
            lazy[ind]=0;
        }
        if(l>hi||lo>r)
        {
            vector<ll> tmp(20,0);
            return tmp;
        }
        if(l<=lo&&hi<=r)
        {
            return seg[ind];
        }
        ll mid=lo+(hi-lo)/2;
        vector<ll> left=query(2*ind+1,lo,mid,l,r),right=query(2*ind+2,mid+1,hi,l,r);
        return merge(left,right);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin>>n;
    vector<ll> a(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    SegmentTree st(n);
    st.build(0,0,n-1,a);
    cin>>q;
    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll l,r,ans=0;
            cin>>l>>r;
            l--;
            r--;
            vector<ll> vec=st.query(0,0,n-1,l,r);
            for(ll i=0;i<20;++i)
            {
                ans+=vec[i]*(1LL<<i);
            }
            cout<<ans<<'\n';
        }
        else
        {
            ll l,r,x;
            cin>>l>>r>>x;
            l--;
            r--;
            st.update(0,0,n-1,l,r,x);
        }
    }
    return 0;
}
