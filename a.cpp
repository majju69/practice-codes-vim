#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h

struct Line
{
    mutable long long k,m,p;
    bool operator<(const Line &o) const
    {
        return k<o.k;
    }
    bool operator<(long long x) const
    {
        return p<x;
    }
};

// LineContainer<true> or LineContainer<> : query maximum value at x
// LineContainer<false>                   : query minimum value at x
template<bool MAX=true>
struct LineContainer:multiset<Line,less<>>
{
    // Use doubles when slopes are non-integer (e.g. dp[i]/i in the recurrence).
    // Change: long long -> double, inf = 1/.0, div(a,b) = a/b, p -> double.
    // Integer mode is exact; doubles risk epsilon errors but handle fractional slopes.
    static const long long inf=LLONG_MAX;
    long long div(long long a,long long b) // floored division
    {
        return a/b-((a^b)<0&&a%b);
    }
    bool isect(iterator x,iterator y)
    {
        if(y==end())
        {
            return x->p=inf,0;
        }
        if(x->k==y->k)
        {
            x->p=x->m>y->m?inf:-inf;
        }
        else
        {
            x->p=div(y->m-x->m,x->k-y->k);
        }
        return x->p>=y->p;
    }
    void add(long long k,long long m)
    {
        if(!MAX)
        {
            k=-k;
            m=-m;
        }
        auto z=insert({k,m,0}),y=z++,x=y;
        while(isect(y,z))
        {
            z=erase(z);
        }
        if(x!=begin()&&isect(--x,y))
        {
            isect(x,y=erase(y));
        }
        while((y=x)!=begin()&&(--x)->p>=y->p)
        {
            isect(x,erase(y));
        }
    }
    long long query(long long x)
    {
        assert(!empty());
        auto l=*lower_bound(x);
        return MAX?l.k*x+l.m:-(l.k*x+l.m);
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x,cur=1e18;
    LineContainer<0> lc;
    cin>>n>>x;
    vector<ll> s(n),f(n);
    for(auto &v:s)
    {
        cin>>v;
    }
    for(auto &v:f)
    {
        cin>>v;
    }
    cur=x*s[0];
    lc.add(f[0],cur);
    for(ll i=1;i<n;++i)
    {
        cur=min(x*s[i],lc.query(s[i]));
        lc.add(f[i],cur);
    }
    cout<<cur<<'\n';
    return 0;
}
