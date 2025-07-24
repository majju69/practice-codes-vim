#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline ll get(ll n)
{
	if(n<=0)
	{
		return 0;
	}
	return ((n*(n+1))>>1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,lo=0,hi=-1,ans=-1;
	cin>>n>>k;
	// k+(k-2)+(k-3)+....+(x) 
	// k-2-x+1+1=mid
	// x=k-mid
	lo=1;
	hi=k-1;
	while(lo<=hi)
	{
		ll mid=lo+(hi-lo)/2;
		ll sum=k;
		if(mid>=2)
		{
			sum+=(get(k-2)-get(k-mid-1));
		}
		if(sum>=n)
		{
			ans=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	if(n==1)
	{
		ans=0;
	}
	cout<<ans<<'\n';
	return 0;
}

