#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll gcd(ll a,ll b)
{
	return ((b==0)?a:gcd(b,a%b));
}

inline ll leastCommonMultiple(ll a,ll b)
{
	return (a/gcd(a,b))*b;
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
		ll a,b,q,lcm=1;
		vector<ll> rem;
		cin>>a>>b>>q;
		lcm=leastCommonMultiple(a,b);
		for(ll i=0;i<lcm;++i)
		{
			if((i%a)%b==(i%b)%a)
			{
				rem.push_back(i);
			}
		}
		while(q--)
		{
			ll l,r,ans=0;
			cin>>l>>r;
			for(auto &v:rem)
			{
				ll tmp_l=l,tmp_r=r;
				tmp_l+=(lcm+(v-tmp_l%lcm+lcm)%lcm)%lcm;
				tmp_r-=(lcm+(tmp_r%lcm-v+lcm)%lcm)%lcm;
				if(tmp_l<=tmp_r)
				{
					ans+=(tmp_r-tmp_l+lcm)/lcm;
				}
			}
			cout<<r-l+1-ans<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
