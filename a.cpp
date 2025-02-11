#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const vector<ll> nbrs={9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999};

bool check(ll n)
{
	while(n)
	{
		if(n%10==7)
		{
			return 1;
		}
		n/=10;
	}
	return 0;
}

ll solve(ll n,ll x)
{
	ll ans=0;
	while(!check(n))
	{
		ans++;
		n+=x;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,ans=1e18;
		cin>>n;
		for(auto &v:nbrs)
		{
			ans=min(ans,solve(n,v));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
