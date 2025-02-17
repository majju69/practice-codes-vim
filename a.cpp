#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,q,sum=0,cur=0,mx=0;
		vector<pair<ll,ll>> req;
		cin>>n>>q;
		vector<ll> a(n);
		for(auto &v:a)
		{
			cin>>v;
			sum+=v;
		}
		for(ll i=1;i<n;++i)
		{
			a[i]+=a[i-1];
		}
		for(ll i=0;i<n;++i)
		{
			if(a[i]>cur)
			{
				req.push_back({a[i],i});
				mx=max(mx,a[i]);
				cur=a[i];
			}
		}
		while(q--)
		{
			ll x;
			cin>>x;
			if(sum<=0)
			{
				if(mx<x)
				{
					cout<<-1<<' ';
				}
				else
				{
					ll idx=lower_bound(req.begin(),req.end(),make_pair(x,-1LL))-req.begin();
					cout<<req[idx].second<<' ';
				}
			}
			else
			{
				// cnt*sum+mx>=x => cnt>=(x-mx)/sum
				if(x<=mx)
				{
					ll idx=lower_bound(req.begin(),req.end(),make_pair(x,-1LL))-req.begin();
					cout<<req[idx].second<<' ';
				}
				else
				{
					ll cnt=(x-mx)/sum+((x-mx)%sum!=0);
					x-=cnt*sum;
					ll idx=lower_bound(req.begin(),req.end(),make_pair(x,-1ll))-req.begin();
					cout<<cnt*n+req[idx].second<<' ';
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}
