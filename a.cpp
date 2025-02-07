#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll get(ll a1,ll a2,vector<ll> &d,vector<ll> &f)
{
	ll n=f.size(),x1=(a1+a2)/2,x2=-1,mn=a2-a1;
	if((a1+a2)&1)
	{
		x2=x1+1;
	}
	for(auto &v:d)
	{
		// v+x>=x1 => x>=x1-v
		ll i=lower_bound(f.begin(),f.end(),x1-v)-f.begin();
		if(i>=0&&i<n)
		{
			ll x=v+f[i];
			if(x<=a2&&x>=a1)
			{
				mn=min(mn,max(x-a1,a2-x));
			}
		}
		i--;
		if(i>=0&&i<n)
		{
			ll x=v+f[i];
			if(x<=a2&&x>=a1)
			{
				mn=min(mn,max(x-a1,a2-x));
			}
		}
		if(x2!=-1)
		{
			ll i=lower_bound(f.begin(),f.end(),x2-v)-f.begin();
			if(i>=0&&i<n)
			{
				ll x=v+f[i];
				if(x<=a2&&x>=a1)
				{
					mn=min(mn,max(x-a1,a2-x));
				}
			}
			i--;
			if(i>=0&&i<n)
			{
				ll x=v+f[i];
				if(x<=a2&&x>=a1)
				{
					mn=min(mn,max(x-a1,a2-x));
				}
			}
		}
	}
	return mn;
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
		ll n,m,k;
		cin>>n>>m>>k;
		vector<ll> a(n),d(m),f(k);
		for(auto &v:a)
		{
			cin>>v;
		}
		for(auto &v:d)
		{
			cin>>v;
		}
		for(auto &v:f)
		{
			cin>>v;
		}
		sort(d.begin(),d.end());
		sort(f.begin(),f.end());
		if(n==2)
		{
			cout<<get(a[0],a[1],d,f)<<'\n';
		}
		else
		{
			vector<ll> diff;
			for(ll i=1;i<n;++i)
			{
				diff.push_back(a[i]-a[i-1]);
			}
			sort(diff.rbegin(),diff.rend());
			if(diff[0]==diff[1])
			{
				cout<<diff[0]<<'\n';
			}
			else
			{
				ll idx=-1;
				for(ll i=1;i<n;++i)
				{
					if(a[i]-a[i-1]==diff[0])
					{
						idx=i-1;
						break;
					}
				}
				cout<<max(get(a[idx],a[idx+1],d,f),diff[1])<<'\n';
			}
		}
	}
	return 0;
}
