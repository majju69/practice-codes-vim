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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,freq[20]={0},ans=0;
	cin>>n;
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		for(ll j=0;j<20;++j)
		{
			if(bit(x,j))
			{
				freq[j]++;
			}
		}
	}
	for(ll i=0;i<n;++i)
	{
		ll x=0;
		for(ll j=0;j<20;++j)
		{
			if(freq[j]>0)
			{
				x+=(1LL<<j);
				freq[j]--;
			}
		}
		ans+=x*x;
	}
	cout<<ans<<'\n';
	return 0;
}
