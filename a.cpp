#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline ll bit(ll a,ll i)
{
	return a>>i&1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q;
	vector<ll> cnt(31,0);
	cin>>n>>q;
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		cnt[__builtin_ctzll(x)]++;
	}
	while(q--)
	{
		ll x,ans=0;
		vector<ll> tmp=cnt;
		cin>>x;
		for(ll i=30;i>=0;--i)
		{
			if(bit(x,i))
			{
				ll req=1;
				for(ll j=i;j>=0;--j)
				{
					if(tmp[j]>=req)
					{
						ans+=req;
						tmp[j]-=req;
						req=0;
						break;
					}
					req-=tmp[j];
					ans+=tmp[j];
					tmp[j]=0;
					req<<=1;
				}
				if(req!=0)
				{
					ans=-1;
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

