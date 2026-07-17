#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

vector<int> lpf(500001,0);
vector<int> primes;

void leastPrimeFactor()
{
    int n=lpf.size();
    for(int i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
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

const int mod=1e9+7;

int mul(const int &a,const int &b)
{
    return (1ll*(a%mod)*(b%mod))%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    leastPrimeFactor();
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,x,ans=1;
        map<int,int> mp;
        cin>>n>>x;
        assert(x==1);
        while(n--)
        {
            int cur;
            cin>>cur;
            while(cur>1)
            {
                const int p=lpf[cur];
                if(!mp.count(p))
                {
                    mp[p]=1;
                }
                while(cur%p==0)
                {
                    mp[p]++;
                    cur/=p;
                }
            }
        }
        for(auto &v:mp)
        {
            ans=mul(ans,v.second);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
