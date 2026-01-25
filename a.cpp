#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2e5+10;
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
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int lo,int hi,int l,int r)
{
    if(l>hi||lo>r)
    {
        return 1e9;
    }
    if(l<=lo&&hi<=r)
    {
        return seg[ind];
    }
    int mid=lo+((hi-lo)>>1);
    return min(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,q;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>a[i];
        a[i]=n-a[i];
    }
    build(0,0,m-1);
    cin>>q;
    while(q--)
    {
        int xs,ys,xf,yf,k;
        cin>>xs>>ys>>xf>>yf>>k;
        ys--;
        yf--;
        xs=n-xs+1;
        xf=n-xf+1;
        if(abs(xs-xf)%k||abs(ys-yf)%k)
        {
            cout<<"NO\n";
        }
        else
        {
            xs%=k;
            if(xs==0)
            {
                xs=k;
            }
            int mn=query(0,0,m-1,min(ys,yf),max(ys,yf));
            cout<<((mn>=xs)?"YES":"NO")<<'\n';
        }
    }
    return 0;
}
