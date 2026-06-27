#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;


const ll N=5e4+10,M=18,primes[]={0,1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
ll a[N],b[N],c[N],dp[N][M];

ll gcd(const ll &a,const ll &b)
{
    return ((b==0)?a:gcd(b,a%b));
}

ll lcm(const ll &a,const ll &b)
{
    return (a/gcd(a,b))*b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        for(ll i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(ll i=0;i<n;++i)
        {
            cin>>b[i];
        }
        for(ll i=0;i<n;++i)
        {
            ll left=1,right=1,l=-1;
            if(i>0)
            {
                left=gcd(a[i],a[i-1]);
            }
            if(i+1<n)
            {
                right=gcd(a[i],a[i+1]);
            }
            l=lcm(left,right);
            if(l<=b[i])
            {
                c[i]=l;
            }
            else
            {
                c[i]=a[i];
            }
        }
        for(ll j=0;j<M;++j)
        {
            ll cur=((j!=0)?c[0]*primes[j]:a[0]);
            ll score=(cur!=a[0]);
            if(cur<=b[0]||cur==a[0])
            {
                dp[1][j]=score;
            }
        }
        for(ll i=1;i<n;++i)
        {
            dp[i+1][0]=max(dp[i+1][0],dp[i][0]);
            for(ll prev=0;prev<M;++prev)
            {
                for(ll curr=0;curr<M;++curr)
                {
                    ll pvs=((prev!=0)?primes[prev]*c[i-1]:a[i-1]),cur=((curr!=0)?c[i]*primes[curr]:a[i]);
                    ll score=(cur!=a[i]);
                    if(gcd(pvs,cur)==gcd(a[i-1],a[i])&&(pvs<=b[i-1]||pvs==a[i-1])&&(cur<=b[i]||cur==a[i]))
                    {
                        dp[i+1][curr]=max(dp[i+1][curr],dp[i][prev]+score);
                    }
                }
            }
        }
        cout<<(*max_element(dp[n],dp[n]+M))<<'\n';
        for(ll i=0;i<=n;++i)
        {
            a[i]=b[i]=c[i]=0;
            memset(dp[i],0,sizeof(dp[i]));
        }
    }
    return 0;
}

