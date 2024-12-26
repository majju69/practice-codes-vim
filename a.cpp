#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll get(ll n)
{
	ll cnt=0;
	while(n)
	{
		n/=10;
		cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,ans=0;
	vector<map<ll,ll>> mp_a(10);
	cin>>n>>k;
	vector<ll> a(n);
	for(auto &v:a)
	{
		cin>>v;
		mp_a[get(v)-1][v%k]++;
	}
	for(auto &v:a)
	{
		ll cur=10;
		mp_a[get(v)-1][v%k]--;
		for(ll i=0;i<10;++i)
		{
			ll r=(cur%k*v%k)%k;
			ll req=(k-r)%k;
			if(mp_a[i].count(req))
			{
				ans+=mp_a[i][req];
			}
			cur*=10;
		}
		mp_a[get(v)-1][v%k]++;
	}
	cout<<ans<<'\n';
	return 0;
}
