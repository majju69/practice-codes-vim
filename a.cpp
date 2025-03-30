#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline ll bit(ll a,ll i)
{
	return a>>i&1;
}

ll gcd(ll a,ll b)
{
	return ((b==0)?a:gcd(b,a%b));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a(n),g((1LL<<n),0),dp((1LL<<n),0);
	for(auto &v:a)
	{
		cin>>v;
	}
	for(ll mask=1;mask<(1LL<<n);++mask)
	{
		ll lsb=__builtin_ctzll(mask);
		g[mask]=gcd(g[mask^(1LL<<lsb)],a[lsb]);
	}
	for(ll mask=1;mask<(1LL<<n);++mask)
	{
		for(ll i=0;i<n;++i)
		{
			if(bit(mask,i))
			{
				dp[mask]=max(dp[mask],g[mask]+dp[mask^(1LL<<i)]);
			}
		}
	}
	cout<<dp[(1LL<<n)-1]<<'\n';
	return 0;
}
