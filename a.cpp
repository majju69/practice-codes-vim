#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll gcd(ll a,ll b)
{
	return ((b==0)?a:gcd(b,a%b));
}

inline ll lcm(ll a,ll b)
{
	return (a/gcd(a,b))*b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,diff=-1,k=0;
	cin>>a>>b;
	diff=abs(a-b);
	for(ll i=1;i*i<=diff;++i)
	{
		if(diff%i==0)
		{
			ll d1=i,d2=diff/i;
			ll k1=(d1-a%d1)%d1,k2=(d2-a%d2)%d2;
			if(lcm(a+k1,b+k1)<lcm(a+k,b+k))
			{
				k=k1;
			}
			if(lcm(a+k2,b+k2)<lcm(a+k,b+k))
			{
				k=k2;
			}
		}
	}
	cout<<k<<'\n';
	return 0;
}
