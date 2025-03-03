#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

bool check(ll mid,ll t,vector<pair<pair<ll,ll>,ll>> &a)
{
	ll sum=0,cnt=0;
	for(auto &v:a)
	{
		if(v.first.second>=mid&&sum+v.first.first<=t)
		{
			sum+=v.first.first;
			cnt++;
			if(cnt>=mid)
			{
				return 1;
			}
		}
	}
	return 0;
}

void print(ll ans,ll t,vector<pair<pair<ll,ll>,ll>> &a)
{
	ll n=a.size(),sum=0,cnt=0;
	cout<<ans<<'\n'<<ans<<'\n';
	for(ll i=0;i<n;++i)
	{
		if(a[i].first.second>=ans&&sum+a[i].first.first<=t)
		{
			cout<<a[i].second+1<<' ';
			cnt++;
			sum+=a[i].first.first;
			if(cnt>=ans)
			{
				break;
			}
		}
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,t,lo=0,hi=-1,ans=0;
	cin>>n>>t;
	vector<pair<pair<ll,ll>,ll>> a(n);
	for(ll i=0;i<n;++i)
	{
		cin>>a[i].first.second>>a[i].first.first;
		a[i].second=i;
	}
	sort(a.begin(),a.end());
	hi=n;
	while(hi>=lo)
	{
		ll mid=lo+(hi-lo)/2;
		if(check(mid,t,a))
		{
			ans=mid;
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	print(ans,t,a);
	return 0;
}
