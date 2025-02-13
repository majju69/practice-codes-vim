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
	ll n,q;
	cin>>n;
	vector<vector<ll>> a(n,vector<ll>(n,0));
	for(auto &vec:a)
	{
		for(auto &v:vec)
		{
			cin>>v;
		}
	}
	cin>>q;
	while(q--)
	{
		ll x,y,c,sum=0;
		cin>>x>>y>>c;
		x--;
		y--;
		a[x][y]=min(a[x][y],c);
		a[y][x]=min(a[y][x],c);
		for(ll i=0;i<n;++i)
		{
			for(ll j=0;j<n;++j)
			{
				ll new_dist=min(a[i][x]+a[x][y]+a[y][j],a[i][y]+a[y][x]+a[x][j]);
				a[i][j]=min(a[i][j],new_dist);
				sum+=a[i][j];
			}
		}
		sum>>=1;
		cout<<sum<<' ';
	}
	cout<<'\n';
	return 0;
}
