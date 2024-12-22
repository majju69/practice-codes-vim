#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll getProfit(ll x,ll k,vector<ll> &a,vector<ll> &b)
{
	ll n=a.size(),neg=0;
	ll cnt=upper_bound(b.begin(),b.end(),1e18)-lower_bound(b.begin(),b.end(),x);
	ll profit=cnt*x;
	ll lb1=0,ub1=upper_bound(a.begin(),a.end(),x-1)-a.begin()-1,lb2=lower_bound(b.begin(),b.end(),x)-b.begin(),ub2=n-1;
	if(lb1<=ub1&&lb2<=ub2)
	{
		ll lb=max(lb1,lb2),ub=min(ub1,ub2);
		if(lb<=ub)
		{
			neg=ub-lb+1;
		}
	}
	if(neg>k)
	{
		profit=0;
	}
	return profit;
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
		ll n,k,ans=0;
		cin>>n>>k;
		vector<ll> a(n),b(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		for(auto &v:b)
		{
			cin>>v;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(auto &v:a)
		{
			ans=max(ans,getProfit(v,k,a,b));
		}
		for(auto &v:b)
		{
			ans=max(ans,getProfit(v,k,a,b));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
