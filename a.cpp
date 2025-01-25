#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

bool check(ll mid,ll s,vector<pair<ll,ll>> &a)		// check median >= mid possible
{
	ll n=a.size(),sum=0;
	ll req=((n+1)>>1);
	vector<ll> tmp;
	for(auto &v:a)
	{
		if(v.second<mid)
		{
			sum+=v.first;
		}
		else
		{
			tmp.push_back(v.first);
		}
	}
	if((ll)tmp.size()<req)
	{
		return 0;
	}
	sort(tmp.rbegin(),tmp.rend());
	for(ll i=0;i<req;++i)
	{
		sum+=max(mid,tmp[i]);
	}
	for(ll i=req;i<(ll)tmp.size();++i)
	{
		sum+=tmp[i];
	}
	return (sum<=s);
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
		ll n,s,lo=1e18,hi=-1e18,ans=-1;
		cin>>n>>s;
		vector<pair<ll,ll>> a(n);
		for(auto &v:a)
		{
			cin>>v.first>>v.second;
			lo=min(lo,v.first);
			hi=max(hi,v.second);
		}
		while(lo<=hi)
		{
			ll mid=lo+(hi-lo)/2;
			if(check(mid,s,a))
			{
				ans=mid;
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
