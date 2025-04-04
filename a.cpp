#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

vector<long long> fact(1000011);

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

inline ll mul(ll a,ll b)
{
	return (a%mod*b%mod)%mod;
}

ll dp[27][500001];

ll solve(ll i,ll tar,vector<ll> &a)
{
	if(tar==0)
	{
		return 1;
	}
	if(i>=(ll)a.size())
	{
		return 0;
	}
	if(dp[i][tar]!=-1)
	{
		return dp[i][tar];
	}
	ll skip=solve(i+1,tar,a),take=0;
	if(a[i]<=tar)
	{
		take=solve(i+1,tar-a[i],a);
	}
	return dp[i][tar]=take+skip;
}

ll knapsack(ll tar,vector<ll> &a)
{
	ll n=a.size();
	for(ll i=0;i<=n;++i)
	{
		for(ll j=0;j<=tar;++j)
		{
			dp[i][j]=-1;
		}
	}
	return solve(0,tar,a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillFact();
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll sum=0,tar=-1,ans=-1;
		vector<ll> a;
		for(ll i=0;i<26;++i)
		{
			ll x;
			cin>>x;
			sum+=x;
			if(x>0)
			{
				a.push_back(x);
			}
		}
		tar=sum/2;
		ans=knapsack(tar,a);
		ans=mul(ans,fact[tar]);
		ans=mul(ans,fact[sum-tar]);
		for(auto &v:a)
		{
			ans=mul(ans,power(fact[v],mod-2));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
