#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll get(ll d,vector<ll> &pre)
{
	ll n=pre.size(),ans=0;
	for(ll i=0;i<n;++i)
	{
		ll req=d+((i==0)?0:pre[i-1]);
		ans+=upper_bound(pre.begin()+i,pre.end(),req)-lower_bound(pre.begin()+i,pre.end(),req);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,n=0,ans=0;
	string s;
	cin>>a>>s;
	n=s.size();
	vector<ll> pre(n,0);
	pre[0]=(s[0]-'0');
	for(ll i=1;i<n;++i)
	{
		pre[i]=pre[i-1]+(s[i]-'0');
	}
	if(a==0)
	{
		ll cnt=get(0,pre);
		ans=n*(n+1)*cnt-cnt*cnt;
	}
	else
	{
		for(ll i=1;i*i<=a;++i)
		{
			if(a%i==0)
			{
				ll d1=i,d2=a/i;
				ll cnt=get(d1,pre)*get(d2,pre);
				ans+=(1+(i*i!=a))*cnt;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
