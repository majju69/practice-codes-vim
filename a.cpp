#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll gcd(ll a,ll b,ll *x,ll *y)
{
	if(a==0)
	{
		*x=0;
		*y=1;
		return b;
	}
	ll x1,y1;
	ll g=gcd(b%a,a,&x1,&y1);
	*x=y1-(b/a)*x1;
	*y=x1;
	return g;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b,c,x,y,g=-1;
	cin>>a>>b>>c;
	g=gcd(a,b,&x,&y);
	if(c%g)
	{
		cout<<-1<<'\n';
	}
	else
	{
		c/=g;
		cout<<-c*x<<' '<<-c*y<<'\n';
	}
	return 0;
}
