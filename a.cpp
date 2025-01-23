#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

long long power(long long a,long long b)        // Use when mod is of order 10^9 or less
{
	long long ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return ans%mod;
}

inline ll mul(ll a,ll b)
{
	return (a%mod*b%mod)%mod;
}

inline ll divide(ll a,ll b)
{
	return mul(a,power(b,mod-2));
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
		ll n,q,ans=1;
		cin>>n>>q;
		vector<pair<ll,ll>> a(n),b(n);
		vector<ll> pos_a(n),pos_b(n),inv_a(n),inv_b(n);
		for(ll i=0;i<n;++i)
		{
			cin>>a[i].first;
			a[i].second=i;
		}
		for(ll i=0;i<n;++i)
		{
			cin>>b[i].first;
			b[i].second=i;
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(ll i=0;i<n;++i)
		{
			ans=mul(ans,min(a[i].first,b[i].first));
			pos_a[a[i].second]=i;
			pos_b[b[i].second]=i;
			inv_a[i]=a[i].second;
			inv_b[i]=b[i].second;
		}
		cout<<ans<<' ';
		while(q--)
		{
			ll type,i;
			cin>>type>>i;
			i--;
			if(type==1)
			{
				ll i1=pos_a[i];
				ll i2=upper_bound(a.begin(),a.end(),make_pair(a[i1].first,n))-a.begin()-1;
				ans=divide(ans,min(a[i1].first,b[i1].first));
				if(i1!=i2)
				{
					ans=divide(ans,min(a[i2].first,b[i2].first));
				}
				a[i1].first++;
				pos_a[i]=i2;
				pos_a[inv_a[i2]]=i1;
				inv_a[i1]=inv_a[i2];
				inv_a[i2]=i;
				swap(a[i1],a[i2]);
				ans=mul(ans,min(a[i1].first,b[i1].first));
				if(i1!=i2)
				{
					ans=mul(ans,min(a[i2].first,b[i2].first));
				}
			}
			else
			{
				ll i1=pos_b[i];
				ll i2=upper_bound(b.begin(),b.end(),make_pair(b[i1].first,n))-b.begin()-1;
				ans=divide(ans,min(a[i1].first,b[i1].first));
				if(i1!=i2)
				{
					ans=divide(ans,min(a[i2].first,b[i2].first));
				}
				b[i1].first++;
				pos_b[i]=i2;
				pos_b[inv_b[i2]]=i1;
				inv_b[i1]=inv_b[i2];
				inv_b[i2]=i;
				swap(b[i1],b[i2]);
				ans=mul(ans,min(a[i1].first,b[i1].first));
				if(i1!=i2)
				{
					ans=mul(ans,min(a[i2].first,b[i2].first));
				}
			}
			cout<<ans<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
