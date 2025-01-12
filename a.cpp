#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=998244353;

inline ll mul(ll a,ll b)
{
	return (a%mod*b%mod)%mod;
}

ll gcd(ll a,ll b)
{
	return ((b==0)?a:gcd(b,a%b));
}

ll square_root(ll n)
{
	if(n<=1)
	{
		return n;
	}
	ll lo=1,hi=sqrtl(n),ans=-1;
	while(hi>=lo)
	{
		ll mid=lo+(hi-lo)/2;
		if(mid*mid>n)
		{
			hi=mid-1;
		}
		else
		{
			ans=mid;
			lo=mid+1;
		}
	}
	return ans;
}

ll cube_root(ll n)
{
	if(n<=1)
	{
		return n;
	}
	ll lo=1,hi=pow(n,0.34),ans=-1;
	while(lo<=hi)
	{
		ll mid=lo+(hi-lo)/2;
		if(mid*mid*mid>n)
		{
			hi=mid-1;
		}
		else
		{
			ans=mid;
			lo=mid+1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,ans=1;
	map<ll,ll> mp,freq;
	vector<pair<ll,ll>> a;
	vector<bool> factorized;
	cin>>n;
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		freq[x]++;
	}
	n=freq.size();
	for(auto &v:freq)
	{
		a.push_back(v);
		factorized.push_back(0);
	}
	for(ll i=0;i<n;++i)
	{
		ll s=square_root(a[i].first),c=cube_root(a[i].first);
		if(s*s==a[i].first)
		{
			ll f=square_root(s);
			if(f*f==s)
			{
				mp[f]+=4*a[i].second;
			}
			else
			{
				mp[s]+=2*a[i].second;
			}
			factorized[i]=1;
		}
		if(c*c*c==a[i].first)
		{
			mp[c]+=3*a[i].second;
			factorized[i]=1;
		}
	}
	for(ll i=0;i<n-1;++i)
	{
		for(ll j=i+1;j<n;++j)
		{
			ll g=gcd(a[i].first,a[j].first);
			if(g==1)
			{
				continue;
			}
			if(!factorized[i])
			{
				mp[g]+=a[i].second;
				mp[a[i].first/g]+=a[i].second;
				factorized[i]=1;
			}
			if(!factorized[j])
			{
				mp[g]+=a[j].second;
				mp[a[j].first/g]+=a[j].second;
				factorized[j]=1;
			}
		}
	}
	for(ll i=0;i<n;++i)
	{
		if(!factorized[i])
		{
			ans=mul(ans,mul(1+a[i].second,1+a[i].second));
		}
	}
	for(auto &v:mp)
	{
		ans=mul(ans,1+v.second);
	}
	cout<<ans<<endl;
	return 0;
}	
