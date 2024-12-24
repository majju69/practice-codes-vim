#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

const ll add(ll a,ll b)
{
	return (a%mod+b%mod)%mod;
}

vector<long long> fact(500001);

void fillFact()
{
	long long n=fact.size();
	fact[0]=1;
	for(long long i=1;i<n;++i)
	{
		fact[i]=(i%mod*fact[i-1]%mod)%mod;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	if(k>n)
	{
		cout<<0<<'\n';
	}
	else
	{
		fillFact();
		ll ans=0;
		for(ll i=1;i<=n;++i)
		{
			ll candidates=n/i-1;
			ans=add(ans,nCr(candidates,k-1));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
