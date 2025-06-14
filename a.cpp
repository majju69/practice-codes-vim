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
	ll n,ans=1;
	vector<ll> a;
	set<ll> st;
	cin>>n;
	while(n--)
	{
		ll x;
		cin>>x;
		st.insert(x);
	}
	for(auto &v:st)
	{
		if(ans==3)
		{
			break;
		}
		for(ll cur=1;cur<=(1LL<<31);cur<<=1)
		{
			if(ans==3)
			{
				break;
			}
			if(st.count(v+cur))
			{
				if(st.count(v+2*cur))
				{
					ans=3;
					a={v,v+cur,v+2*cur};
					break;
				}
				else
				{
					if(ans==1)
					{
						ans=2;
						a={v,v+cur};
					}
				}
			}
		}
	}
	if(ans==1)
	{
		cout<<1<<'\n'<<*st.begin()<<'\n';
	}
	else
	{
		cout<<ans<<'\n';
		for(auto &v:a)
		{
			cout<<v<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
