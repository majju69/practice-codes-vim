#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

inline pair<int,int> merge(pair<int,int> a,pair<int,int> b)
{
    return {min(a.first,b.first),max(a.second,b.second)};
}

class SegmentTree
{

private:

    vector<pair<int,int>> seg;  // {min,max}

public:

    SegmentTree(int n)
    {
        seg.resize(4*n+1);
    }

    void build(int ind,int lo,int hi,vector<int> &a)
    {
        if(lo==hi)
        {
            seg[ind]={a[lo],a[lo]};
            return;
        }
        int mid=lo+(hi-lo)/2;
        build(2*ind+1,lo,mid,a);
        build(2*ind+2,mid+1,hi,a);
        seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
    }

    pair<int,int> query(int ind,int lo,int hi,int l,int r)
    {
        if(l>hi||lo>r)
        {
            return {1e9,-1e9};
        }
        if(l<=lo&&hi<=r)
        {
            return seg[ind];
        }
        int mid=lo+(hi-lo)/2;
        return merge(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
    }

    int firstAbove(int ind,int lo,int hi,int l,int r,int x)
    {
        if(l>hi||lo>r||seg[ind].second<=x)
        {
            return -1;
        }
        if(lo==hi)
        {
            return lo;
        }
        int mid=lo+(hi-lo)/2;
        int ans=firstAbove(2*ind+1,lo,mid,l,r,x);
        if(ans==-1)
        {
            ans=firstAbove(2*ind+2,mid+1,hi,l,r,x);
        }
        return ans;
    }

    int lastAbove(int ind,int lo,int hi,int l,int r,int x)
    {
        if(l>hi||lo>r||seg[ind].second<=x)
        {
            return -1;
        }
        if(lo==hi)
        {
            return lo;
        }
        int mid=lo+(hi-lo)/2;
        int ans=lastAbove(2*ind+2,mid+1,hi,l,r,x);
        if(ans==-1)
        {
            ans=lastAbove(2*ind+1,lo,mid,l,r,x);
        }
        return ans;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,ans=0;
    cin>>n;
    vector<int> a(n),pre(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    pre[0]=a[0];
    for(int i=1;i<n;++i)
    {
        pre[i]=pre[i-1]+a[i];
    }
    SegmentTree st(n),st_pre(n);
    st.build(0,0,n-1,a);
    st_pre.build(0,0,n-1,pre);
    for(int i=0;i<n;++i)
    {
        int left=0,right=0;
        if(i>0)
        {
            // a[i1]+a[i1+1]+...+a[i-1] is maximum
            // pre[i-1]-a[i1-1] is maximum
            // i1>idx
            // i1-1>=idx
            int idx=st.lastAbove(0,0,n-1,0,i-1,a[i]);   
            if(idx!=-1)
            {
                pair<int,int> p=st_pre.query(0,0,n-1,idx,i-1);
                left=max(left,pre[i-1]-p.first);
            }
            else
            {
                pair<int,int> p=st_pre.query(0,0,n-1,0,i-1);
                left=max({left,pre[i-1],pre[i-1]-p.first});
            }
        }
        if(i<n-1)
        {
            // a[i+1]+....+a[i1] is maximum
            // pre[i1]-pre[i] is maximum
            // i1<idx
            int idx=st.firstAbove(0,0,n-1,i+1,n-1,a[i]);
            if(idx!=-1)
            {
                pair<int,int> p=st_pre.query(0,0,n-1,i+1,idx-1);
                right=max(right,p.second-pre[i]);
            }
            else
            {
                pair<int,int> p=st_pre.query(0,0,n-1,i+1,n-1);
                right=max(right,p.second-pre[i]);
            }
        }
        ans=max(ans,left+right);
    }
    cout<<ans<<'\n';
    return 0;
}
