#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll get(ll n)
{
	ll ans=0,cur=2;
	while(cur<=n)
	{
		ans+=n/cur;
		cur<<=1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,k;
		cin>>n>>k;
		n--;
		for(ll i=0;i<=n;++i)
		{
			ll num=get(n),den=get(i)+get(n-i);
			cout<<((num>den)?0LL:k)<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
