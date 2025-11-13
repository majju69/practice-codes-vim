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

vector<int> lpf(15000001,0),id(15000001,-1);
vector<int> primes,cnt;

void leastPrimeFactor()
{
    int n=lpf.size();
    for(int i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
            cnt.push_back(0);
            id[i]=(int)primes.size()-1;
        }
        for(int j=0;i*primes[j]<n;++j)
        {
            lpf[i*primes[j]]=primes[j];
            if(primes[j]==lpf[i])
            {
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    leastPrimeFactor();
    int n,g=0,mx=0;
    cin>>n;
    vector<int> a(n);
    for(auto &v:a)
    {
        cin>>v;
        g=gcd(v,g);
    }
    for(auto &v:a)
    {
        v/=g;
        while(v>1)
        {
            int p=lpf[v];
            cnt[id[p]]++;
            while(v%p==0)
            {
                v/=p;
            }
        }
    }
    for(auto &v:primes)
    {
        mx=max(mx,cnt[id[v]]);
    }
    cout<<((mx==0)?-1:n-mx)<<'\n';
    return 0;
}
