#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=(1<<18)+10;
int a[N],seg[N<<2];

void build(int ind,int lo,int hi)
{
    if(lo==hi)
    {
        seg[ind]=a[lo];
        return;
    }
    int mid=lo+((hi-lo)>>1);
    build(2*ind+1,lo,mid);
    build(2*ind+2,mid+1,hi);
    seg[ind]=(seg[2*ind+1]^seg[2*ind+2]);
}

void update(int ind,int lo,int hi,int i,int val)
{
    if(lo==hi)
    {
        seg[ind]=val;
        return;
    }
    int mid=lo+((hi-lo)>>1);
    if(i<=mid)
    {
        update(2*ind+1,lo,mid,i,val);
    }
    else
    {
        update(2*ind+2,mid+1,hi,i,val);
    }
    seg[ind]=(seg[2*ind+1]^seg[2*ind+2]);
}

int get(int ind,int lo,int hi,int i)
{
    if(lo==hi)
    {
        return 0;
    }
    int mid=lo+((hi-lo)>>1),left=seg[2*ind+1],right=seg[2*ind+2];
    if(i<=mid)
    {
        if(right>left)
        {
            return hi-mid+get(2*ind+1,lo,mid,i);
        }
        return get(2*ind+1,lo,mid,i);
    }
    if(right>left)
    {
        return get(2*ind+2,mid+1,hi,i);
    }
    return mid-lo+1+get(2*ind+2,mid+1,hi,i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,q;
        cin>>n>>q;
        n=(1<<n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        build(0,0,n-1);
        while(q--)
        {
            int i,x;
            cin>>i>>x;
            i--;
            update(0,0,n-1,i,x);
            cout<<get(0,0,n-1,i)<<'\n';
            update(0,0,n-1,i,a[i]);
        }
    }
    return 0;
}
