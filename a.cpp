#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

bool is_prime(int n)
{
	for(int i=2;i*i<=n;++i)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	if(is_prime(n))
	{
		cout<<1<<'\n';
	}
	else
	{
		if(n&1)
		{
			cout<<((is_prime(n-2))?2:3)<<'\n';
		}
		else
		{
			cout<<2<<'\n';
		}
	}
	return 0;
}
