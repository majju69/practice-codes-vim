#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,mx=0,ind=1e9;
    cin>>n>>k;
    vector<int> a(n),pre(n,0);
    for(auto &v:a)
    {
        cin>>v;
    }
    pre[0]=(a[0]==0);
    for(int i=1;i<n;++i)
    {
        pre[i]=pre[i-1]+(a[i]==0);
    }
    for(int i=0;i<n;++i)
    {
        // zero[i..idx]>k <==> pre[idx]-pre[i-1]>k <==> pre[idx]>pre[i-1]+k
        int req=k+((i==0)?0:pre[i-1]);
        int idx=upper_bound(pre.begin(),pre.end(),req)-pre.begin()-1;
        if(idx-i+1>mx)
        {
            mx=idx-i+1;
            ind=i;
        }
    }
    for(int i=ind;i<n;++i)
    {
        if(k<=0)
        {
            break;
        }
        if(a[i]==0)
        {
            a[i]=1;
            k--;
        }
    }
    cout<<mx<<'\n';
    for(auto &v:a)
    {
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
