#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

vector<long long> lpf(10000001,0);
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

inline ll mul(ll a,ll b)
{
	return (a%mod*b%mod)%mod;
}

inline ll divide(ll a,ll b)
{
	return mul(a,power(b,mod-2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	leastPrimeFactor();
	ll n,m,pro=1;
	map<ll,ll> mp_m;
	cin>>n>>m;
	for(auto &p:primes)
	{
		if(m/p==0)
		{
			break;
		}
		ll cur=p,cnt=0;
		while(m/cur!=0)
		{
			cnt+=(m/cur);
			cur*=p;
		}
		mp_m[p]=cnt;
		pro=mul(pro,1+cnt);
	}
	for(ll i=0;i<n;++i)
	{
		ll x,ans=pro;
		cin>>x;
		while(x>1)
		{
			ll p=lpf[x],cnt=0,pvs=0;
			while(x%p==0)
			{
				cnt++;
				x/=p;
			}
			if(mp_m.count(p))
			{
				pvs=mp_m[p];
			}
			ans=divide(ans,pvs+1);
			ans=mul(ans,pvs+cnt+1);
		}
		cout<<ans<<' ';
	}
	cout<<'\n';
	return 0;
}
