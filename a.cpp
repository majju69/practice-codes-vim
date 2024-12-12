#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll solve(ll lo,ll hi,ll a,ll b,vector<ll> &pos)
{
	if(lo==hi)
	{
		ll cnt=upper_bound(pos.begin(),pos.end(),hi)-lower_bound(pos.begin(),pos.end(),lo);
		return ((cnt==0)?a:b*cnt);
	}
	ll len=hi-lo+1; 
	ll cnt=upper_bound(pos.begin(),pos.end(),hi)-lower_bound(pos.begin(),pos.end(),lo);
	if(cnt==0)
	{
		return a;
	}
	ll ans1=solve(lo,lo+(len>>1)-1,a,b,pos)+solve(lo+(len>>1),hi,a,b,pos),ans2=b*cnt*len;
	return min(ans1,ans2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,a,b;
	cin>>n>>k>>a>>b;
	vector<ll> pos(k);
	for(auto &v:pos)
	{
		cin>>v;
		v--;
	}
	sort(pos.begin(),pos.end());
	cout<<solve(0,(1LL<<n)-1,a,b,pos)<<'\n';
	return 0;
}
