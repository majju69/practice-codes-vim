#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline long long get(int n)
{
	if(n<=1)
	{
		return 0;
	}
	return 1ll*n*(n-1)/2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a,b,c,d;
	long long ans=0;
	cin>>a>>b>>c>>d;
	for(int z=c;z<=d;++z)
	{
		ans+=get(z-a-b+2)-get(z-2*b+1)-get(z-a-c+1)+get(z-b-c);
	}
	cout<<1ll*(b-a+1)*(c-b+1)*(d-c+1)-ans<<'\n';
	return 0;
}
