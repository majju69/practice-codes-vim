#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

// Monotone-slope / monotone-query CHT. Both slopes (add) and queries (query) must be monotone.
// O(1) amortized add and query. MODE bits: [slope inc/dec = &4][x inc/dec = &2][hull min/max = &1]
// 0:inc,inc,max 1:inc,inc,min 2:inc,dec,max 3:inc,dec,min
// 4:dec,inc,max 5:dec,inc,min 6:dec,dec,max 7:dec,dec,min
//
// For REAL (fractional) slopes/x, switch to long double:
//   1. struct Line { long long k,m; }      -> struct Line { long double k,m; }
//   2. val / add / query: long long x, m, k -> long double  (return type of val/query too)
//   3. bad(): drop the (__int128) casts -> return (b.m-a.m)*(b.k-c.k) >= (c.m-b.m)*(a.k-b.k);
//      (__int128 was only for integer exactness; not needed/usable with floats)
//   4. ptr stays int. The MODE sign-flips (-k,-m,-x,-res) are unchanged.
// Caveats: equality is no longer exact -- H.back().k==k almost never fires (fine), but
//   near-equal slopes make bad() noisy; if slopes can be very close, treat
//   fabs(b.k-c.k)<eps as "equal slope" and keep the larger m. Prefer long double over
//   double for slopes like dp[i]/i. Integer mode is exact; float mode risks epsilon errors.
template<int MODE=0>
struct ConvexHull
{
    static const bool MN        = MODE&1;   // min hull
    static const bool SLOPE_DEC = MODE&4;   // slopes added in decreasing order
    static const bool FLIPX     = MN ^ SLOPE_DEC;          // query internal coord = -x
    static const bool FWD       = (FLIPX == bool(MODE&2)); // pointer moves forward
 
    struct Line
    { 
        long long k,m;
    };
    vector<Line> H;
    int ptr=FWD?0:INT_MAX;
 
    long long val(int i,long long x) const 
    { 
        return H[i].k*x+H[i].m;
    }
 
    // b is redundant: intersection(a,b) >= intersection(b,c), slopes a.k<b.k<c.k
    bool bad(const Line &a,const Line &b,const Line &c) const
    {
        return (__int128)(b.m-a.m)*(b.k-c.k)>=(__int128)(c.m-b.m)*(a.k-b.k);
    }
 
    void add(long long k, long long m)
    {
        if(SLOPE_DEC)
        {
            k=-k;
        }
        if(MN)
        {
            m=-m;
        }
        while(!H.empty()&&H.back().k==k)   // same slope: keep larger intercept
        {
            if(H.back().m>=m)
            {
                return;
            }
            H.pop_back();
        }
        while(H.size()>=2&&bad(H[H.size()-2],H.back(),{k,m}))
        {
            H.pop_back();
        }
        H.push_back({k, m});
    }
 
    long long query(long long x)
    {
        assert(!H.empty());
        long long X=FLIPX?-x:x;
        if(ptr>(int)H.size()-1) 
        {
            ptr=(int)H.size()-1;   // clamp (pops / backward init)
        }
        if(FWD) 
        {
            while(ptr+1<(int)H.size()&&val(ptr+1,X)>=val(ptr,X))
            {
                ++ptr;
            }
        }
        else
        {
            while(ptr>0&&val(ptr-1,X)>=val(ptr,X))
            {
                --ptr;
            }
        }
        long long res=val(ptr,X);
        return MN ? -res : res;
    }
};

typedef long long ll;
 
const ll N=1e5+10,P=105;
ll d[N],a[N],pre[N],dp[N][P];
ConvexHull<5> ch[P];
 
inline ll get(const ll &i,const ll &j)
{
    return a[j]-((i==0)?0:a[i-1]);
}
 
 
inline ll get(const ll &i)
{
    return get(i,i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,p;
    set<ll> st;
    cin>>n>>m>>p;
    for(ll i=0;i<n-1;++i)
    {
        cin>>d[i];
        if(i>=1)
        {
            d[i]+=d[i-1];
        }
    }
    for(ll i=0;i<m;++i)
    {
        ll hi,ti;
        cin>>hi>>ti;
        if(hi==1)
        {
            a[i]=ti;
        }
        else
        {
            ll cur=d[hi-2];
            a[i]=ti-cur;
        }
    }
    sort(a,a+m);
    reverse(a,a+m);
    for(ll i=1;i<m;++i)
    {
        a[i]+=a[i-1];
    }
    for(ll i=m-1;i>=0;--i)
    {
        st.insert(get(i));
        for(ll k=1;k<=p;++k)
        {
            if(k>=(ll)st.size())
            {
                dp[i][k]=0;
            }
            else
            {
                if(k==1)
                {
                    dp[i][k]=(m-i)*get(i)-get(i,m-1);
                }
                else
                {
                    ll x=ch[k-1].query(get(i));
                    dp[i][k]=a[i]-get(i)-i*get(i)+x;
                }
            }
            ch[k].add(i,dp[i][k]-((i==0)?0:a[i-1]));
        }
    }
    cout<<dp[0][p]<<'\n';
    return 0;
}
