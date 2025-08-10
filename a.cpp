#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=1e5+10;
int a[N],_or[N<<2],lazy[N<<2],_and[N<<2];

void build(int ind,int lo,int hi)
{
    if(lo==hi)
    {
        _and[ind]=a[lo];
        return;
    }
    int mid=lo+(hi-lo)/2;
    build(2*ind+1,lo,mid);
    build(2*ind+2,mid+1,hi);
    _and[ind]=(_and[2*ind+1]&_and[2*ind+2]);
}

void update(int ind,int lo,int hi,int l,int r,int val)
{
    if(lazy[ind]!=0)
    {
        _or[ind]|=lazy[ind];
        if(lo!=hi)
        {
            lazy[2*ind+1]|=lazy[ind];
            lazy[2*ind+2]|=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(l>hi||lo>r)
    {
        return;
    }
    if(l<=lo&&hi<=r)
    {
        _or[ind]|=val;
        if(lo!=hi)
        {
            lazy[2*ind+1]|=val;
            lazy[2*ind+2]|=val;
        }
        return;
    }
    int mid=lo+(hi-lo)/2;
    update(2*ind+1,lo,mid,l,r,val);
    update(2*ind+2,mid+1,hi,l,r,val);
    _or[ind]=(_or[2*ind+1]|_or[2*ind+2]);
}

int query(int ind,int lo,int hi,int i)
{
    if(lazy[ind]!=0)
    {
        _or[ind]|=lazy[ind];
        if(lo!=hi)
        {
            lazy[2*ind+1]|=lazy[ind];
            lazy[2*ind+2]|=lazy[ind];
        }
        lazy[ind]=0;
    }
    if(lo==hi)
    {
        return _or[ind];
    }
    int mid=lo+(hi-lo)/2;
    if(i<=mid)
    {
        return query(2*ind+1,lo,mid,i);
    }
    return query(2*ind+2,mid+1,hi,i);
}

int query(int ind,int lo,int hi,int l,int r)
{
    if(l>hi||lo>r)
    {
        return (1<<30)-1;
    }
    if(l<=lo&&hi<=r)
    {
        return _and[ind];
    }
    int mid=lo+(hi-lo)/2;
    return (query(2*ind+1,lo,mid,l,r)&query(2*ind+2,mid+1,hi,l,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    bool ok=1;
    cin>>n>>q;
    vector<pair<pair<int,int>,int>> queries(q);
    for(auto &q:queries)
    {
        int l,r,val;
        cin>>l>>r>>val;
        l--;
        r--;
        q={{l,r},val};
        update(0,0,n-1,l,r,val);
    }
    for(int i=0;i<n;++i)
    {
        a[i]=query(0,0,n-1,i);
    }
    build(0,0,n-1);
    for(auto &q:queries)
    {
        if(query(0,0,n-1,q.first.first,q.first.second)!=q.second)
        {
            ok=0;
            break;
        }
    }
    if(ok)
    {
        cout<<"YES\n";
        for(int i=0;i<n;++i)
        {
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}
