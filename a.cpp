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
	int n,g=0,mx=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		g=gcd(g,x);
		mx=max(mx,x);
	}
	cout<<(((mx/g-n)&1)?"Alice":"Bob")<<'\n';
	return 0;
}
