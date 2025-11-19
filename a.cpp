#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int gcd(int a,int b)
{
	return ((b==0)?a:gcd(b,a%b));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,g=0;
	cin>>n>>k;
	while(n--)
	{
		int x;
		cin>>x;
		x%=k;
		g=gcd(g,x);
	}
	g=gcd(g,k);
	if(g==0)
	{
		cout<<1<<'\n'<<0<<'\n';
	}
	else
	{
		cout<<k/g<<'\n';
		for(int i=0;i<k;i+=g)
		{
			cout<<i<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
