#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

vector<int> lpf(10000001,0),primes,pre(10000001,0);

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    leastPrimeFactor();
    int n,q;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        while(x>1)
        {
            int cur=lpf[x];
            pre[cur]++;
            while(x%cur==0)
            {
                x/=cur;
            }
        }
    }
    for(int i=1;i<10000001;++i)
    {
        pre[i]+=pre[i-1];
    }
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(l>primes.back())
        {
            cout<<0<<'\n';
            continue;
        }
        if(r>primes.back())
        {
            r=1e7;
        }
        cout<<pre[r]-pre[l-1]<<'\n';
    }
    return 0;
}
