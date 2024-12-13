#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

vector<long long> getPrefix(vector<long long> &a)
{
	long long n=a.size();
	vector<long long> prefix;
	prefix.push_back(a[0]);
	for(long long i=1;i<n;++i)
	{
		prefix.push_back(a[i]+prefix.back());
	}
	return prefix;
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
		ll n,q,mx_h=0,mx_w=0;
		cin>>n>>q;
		vector<pair<ll,ll>> rect(n);
		for(auto &v:rect)
		{
			cin>>v.first>>v.second;
			mx_h=max(mx_h,v.first);
			mx_w=max(mx_w,v.second);
		}
		vector<vector<ll>> a(mx_h+1,vector<ll>(mx_w+1,0)),pre(mx_h+1,vector<ll>(mx_w+1,0));
		for(auto &v:rect)
		{
			a[v.first][v.second]+=v.first*v.second;
		}
		pre[0]=getPrefix(a[0]);
		for(ll i=1;i<=mx_h;++i)
		{
			pre[i]=getPrefix(a[i]);
			for(ll j=0;j<=mx_w;++j)
			{
				pre[i][j]+=pre[i-1][j];
			}
		}
		while(q--)
		{
			ll hs,ws,hb,wb;
			cin>>hs>>ws>>hb>>wb;
			hs++;
			ws++;
			hb--;
			wb--;
			wb=min(wb,mx_w);
			hb=min(hb,mx_h);
			if(hs>hb||ws>wb)
			{
				cout<<0<<'\n';
			}
			else
			{
				cout<<pre[hb][wb]-pre[hb][ws-1]-pre[hs-1][wb]+pre[hs-1][ws-1]<<'\n';
			}
		}
	}
	return 0;
}
