#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline bool ok(ll a,ll b)
{
	return (a==0||b==0||(a<=(ll)2e18/b&&b<=(ll)2e18/a));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll x,y,l,r,pow_x[61]={1},pow_y[61]={1};
	vector<ll> a;
	cin>>x>>y>>l>>r;
	for(ll i=1;i<=60;++i)
	{
		if(pow_x[i-1]!=-1&&ok(pow_x[i-1],x)&&x*pow_x[i-1]<r)
		{
			pow_x[i]=x*pow_x[i-1];
		}
		else
		{
			pow_x[i]=-1;
		}
		if(pow_y[i-1]!=-1&&ok(pow_y[i-1],y)&&y*pow_y[i-1]<r)
		{
			pow_y[i]=y*pow_y[i-1];
		}
		else
		{
			pow_y[i]=-1;
		}
	}
	for(ll i=0;i<=60;++i)
	{
		for(ll j=0;j<=60;++j)
		{
			if(pow_x[i]!=-1&&pow_y[j]!=-1&&pow_x[i]+pow_y[j]>=l&&pow_x[i]+pow_y[j]<=r)
			{
				a.push_back(pow_x[i]+pow_y[j]);
			}
		}
	}
	if((ll)a.size()==0)
	{
		cout<<r-l+1<<'\n';
	}
	else
	{
		sort(a.begin(),a.end());
		ll ans=max({0LL,a[0]-l,r-a.back()});
		for(ll i=1;i<(ll)a.size();++i)
		{
			ans=max(ans,a[i]-a[i-1]-1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
