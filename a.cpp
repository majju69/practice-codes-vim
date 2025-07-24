#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=1e9+7;

inline int add(int a,int b)
{
    return ((a%mod)+(b%mod))%mod;
}

inline int get(int n)
{
    if(n==0)
    {
        return 0;
    }
    return 32-__builtin_clz(n);
}

bool cmp(int a,int b)
{
    return get(a)<get(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,p,ans=0;
    set<int> st;
    cin>>n>>p;
    vector<int> a(n),fib(p),pre(p);
    for(auto &v:a)
    {
        cin>>v;
    }
    sort(a.begin(),a.end(),cmp);
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<p;++i)
    {
        fib[i]=add(fib[i-1],fib[i-2]);
    }
    pre[0]=fib[0];
    for(int i=1;i<p;++i)
    {
        pre[i]=add(fib[i],pre[i-1]);
    }
    for(auto &v:a)
    {
        int x=v;
        bool ok=1;
        while(x)
        {
            if(st.count(x))
            {
                ok=0;
                break;
            }
            if(x&1)
            {
                x>>=1;
            }
            else
            {
                if((x&3)==0)
                {
                    x>>=2;
                }
                else
                {
                    break;
                }
            }
        }
        if(ok)
        {
            st.insert(v);
            if(p<=30&&v>=(1<<p))
            {
                continue;
            }
            ans=add(ans,pre[p-get(v)]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
