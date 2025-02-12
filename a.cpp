#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
	return a.second<b.second;
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
		ll n,l,ans=0;
		cin>>n>>l;
		vector<pair<ll,ll>> a(n);
		for(auto &v:a)
		{
			cin>>v.first>>v.second;
		}
		sort(a.begin(),a.end(),cmp);
		for(ll i=0;i<n;++i)
		{
			if(a[i].first<=l)
			{
				ans=max(ans,1LL);
				ll cnt=1,a_sum=a[i].first,b_sum=0;
				priority_queue<ll> pq;
				pq.push(a[i].first);
				for(ll j=i+1;j<n;++j)
				{
					b_sum+=(a[j].second-a[j-1].second);
					if(b_sum>l)
					{
						break;
					}
					a_sum+=a[j].first;
					pq.push(a[j].first);
					cnt++;
					while(a_sum+b_sum>l)
					{
						ll x=pq.top();
						pq.pop();
						cnt--;
						a_sum-=x;
					}
					ans=max(ans,cnt);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
