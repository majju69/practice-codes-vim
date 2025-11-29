#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

int gcd(int a,int b)
{
    return ((b==0)?a:gcd(b,a%b));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,g=0,mx=-1,ans=0;
    cin>>n;
    vector<int> a(n);
    for(auto &v:a)
    {
        cin>>v;
        g=gcd(g,v);
    }
    for(auto &v:a)
    {
        v/=g;
        mx=max(mx,v);
    }
    vector<bool> present(mx+1,0);
    for(auto &v:a)
    {
        present[v]=1;
    }
    for(int i=mx;i>=1;--i)
    {
        if(present[i])
        {
            continue;
        }
        int cnt=1,g=0;
        for(int j=(i<<1);j<=mx;j+=i)
        {
            cnt++;
            if(present[j])
            {
                g=gcd(cnt,g);
            }
        }
        if(g==1)
        {
            ans++;
            present[i]=i;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
