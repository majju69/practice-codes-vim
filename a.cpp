#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

vector<long long> fact(2000001);

void fillFact()
{
	long long n=fact.size();
	fact[0]=1;
	for(long long i=1;i<n;++i)
	{
		fact[i]=(i%mod*fact[i-1]%mod)%mod;
	}
}

vector<long long> lpf(2000001,0);
vector<long long> primes;

void leastPrimeFactor()
{
    long long n=lpf.size();
    for(long long i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
        }
        for(long long j=0;i*primes[j]<n;++j)
        {
            lpf[i*primes[j]]=primes[j];
            if(primes[j]==lpf[i])
            {
                break;
            }
        }
    }
}

long long power(long long a,long long b)        // Use when mod is of order 10^9 or less
{
	long long ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return ans%mod;
}

long long nCr(long long n,long long r)         // Ensure that fillFact() is called before this function is used
{
	if(n<r||n<0||r<0)
	{
		return 0;
	}
	if(r==n||r==0)
	{
		return 1;
	}
	return (fact[n]*power(fact[r],mod-2)%mod*power(fact[n-r],mod-2)%mod)%mod;
}

inline ll get(ll n,ll r)
{
	return nCr(n+r-1,r-1);
}

inline ll mul(ll a,ll b)
{
	return (a%mod*b%mod)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillFact();
	leastPrimeFactor();
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll x,y,ans=1;
		cin>>x>>y;
		while(x>1)
		{
			ll p=lpf[x],cnt=0;
			while(x%p==0)
			{
				cnt++;
				x/=p;
			}
			ans=mul(ans,get(cnt,y));
		}
		ans=mul(ans,power(2,y-1));
		cout<<ans<<'\n';
	}
	return 0;
}
