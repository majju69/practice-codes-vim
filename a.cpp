#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll x,y;
		cin>>x>>y;
		if(x<y)
		{
			ll q=y/x,r=y%x;
			cout<<q*x+(r>>1)<<'\n';
		}
		else if(x>y)
		{
			cout<<y*(x+1)<<'\n';
		}
		else
		{
			cout<<x<<'\n';
		}
	}
	return 0;
}
