#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

inline ll add(ll a,ll b)
{
	return (a%mod+b%mod)%mod;
}

vector<vector<long long>> divisors(1000001);

void fillDivisors()
{
	long long n=divisors.size();
	divisors[0].push_back(0);
	divisors[1].push_back(1);
	for(long long i=2;i<n;i++)
	{
		divisors[i].push_back(1);
	}
	for(long long i=2;i<n;i++)
	{
		for(long long j=i;j<n;j+=i)
		{
			divisors[j].push_back(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillDivisors();
	for(auto &vec:divisors)
	{
		sort(vec.rbegin(),vec.rend());
	}
	ll n,ans=0,dp[1000001]={0};
	cin>>n;
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		for(auto &d:divisors[x])
		{
			if(d==1)
			{
				dp[d]++;
			}
			else
			{
				dp[d]=add(dp[d],dp[d-1]);
			}
		}
	}
	for(ll i=1;i<=1000000;++i)
	{
		ans=add(ans,dp[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
