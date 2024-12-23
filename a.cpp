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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,p,w,d,g=0;
	cin>>n>>p>>w>>d;
	g=gcd(d,w);
	if(p%g)
	{
		cout<<-1<<'\n';
	}
	else
	{
		d/=g;
		p/=g;
		w/=g;
		ll x=-1,y=-1;
		for(ll i=0;i<d;++i)
		{
			ll num=p-w*i;
			if(num%d==0)
			{
				x=i;
				y=num/d;
				break;
			}
		}
		if(y<0||x+y>n)
		{
			ll lb=(x+y-n)/(w-d)+(((x+y-n)%(w-d))!=0),ub=y/w;
			if(lb<=ub)
			{
				x+=lb*d;
				y-=lb*w;
			}
			else
			{
				x=y=-1;
			}
		}
		if(x<0)
		{
			cout<<-1<<'\n';
		}
		else
		{
			cout<<x<<' '<<y<<' '<<n-x-y<<'\n';
		}
	}
	return 0;
}
