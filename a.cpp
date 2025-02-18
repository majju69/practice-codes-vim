#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline ll get(ll n)
{
	return ((n*(n+1))>>1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	if(k>=1e6)
	{
		cout<<-1<<'\n';
	}
	else
	{
		vector<ll> div,ans;
		for(ll i=1;i*i<=n;++i)
		{
			if(n%i==0)
			{
				div.push_back(n/i);
				if(i*i!=n)
				{
					div.push_back(i);
				}
			}
		}
		sort(div.rbegin(),div.rend());
		for(auto &d:div)
		{
			if(get(k)<=n/d)
			{
				ll x=n/d-get(k);
				for(ll i=1;i<k;++i)
				{
					ans.push_back(i*d);
				}
				ans.push_back(d*(k+x));
				break;
			}
		}
		if((int)ans.size()==0)
		{
			cout<<-1<<'\n';
		}
		else
		{
			for(auto &v:ans)
			{
				cout<<v<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}
