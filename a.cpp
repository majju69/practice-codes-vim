#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

inline ll add(ll a,ll b)
{
	return ((a%mod)+(b%mod))%mod;
}

inline ll sub(ll a,ll b)
{
	return ((a%mod)-(b%mod)+mod)%mod;
}

inline ll mul(ll a,ll b)
{
	return ((a%mod)*(b%mod))%mod;
}

vector<bool> isPrime(300001,true);

void sieve()
{
	long long n=isPrime.size();
	isPrime[0]=isPrime[1]=false;
	isPrime[2]=true;
	for(long long p=2;p*p<n;p++)
	{
		if(isPrime[p]==true)
		{
			for(long long i=p*p;i<n;i+=p)
			{
				isPrime[i]=false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	ll n,m,mult=1,ans=0;
	cin>>n>>m;
	vector<ll> dp(n+1,0),tot(n+1,0);
	dp[1]=m;
	tot[1]=m;
	for(ll i=2;i<=n;++i)
	{
		if(isPrime[i]&&mult<=m)
		{
			mult*=i;
		}
		dp[i]=mul(dp[i-1],(m/mult));
		tot[i]=mul(tot[i-1],m);
	}
	for(ll i=1;i<=n;++i)
	{
		ans=add(ans,sub(tot[i],dp[i]));
	}
	cout<<ans<<'\n';
	return 0;
}
