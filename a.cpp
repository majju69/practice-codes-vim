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
		ll n,m,s=0,ans=0;
		multiset<ll> st;
		cin>>n>>m;
		vector<ll> a(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		m--;
		for(ll i=m;i>0;--i)
		{
			s+=a[i];
			st.insert(a[i]);
			if(s>0)
			{
				auto it=st.rbegin();
				ll x=*it;
				ans++;
				s-=2*x;
				st.erase(st.find(x));
			}
		}
		s=0;
		st.clear();
		for(ll i=m+1;i<n;++i)
		{
			s+=a[i];
			st.insert(a[i]);
			if(s<0)
			{
				auto it=st.begin();
				ll x=*it;
				ans++;
				s-=2*x;
				st.erase(st.find(x));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
