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
	ll n,m,sum=0;
	map<ll,bool> vis;
	vector<ll> a;
	queue<pair<ll,ll>> q;
	cin>>n>>m;
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		vis[x]=1;
		q.push({x,0});
	}
	while(1)
	{
		ll node=q.front().first,level=q.front().second;
		q.pop();
		if(level!=0)
		{
			sum+=level;
			a.push_back(node);
			if((ll)a.size()>=m)
			{
				break;
			}
		}
		if(!vis.count(node-1))
		{
			vis[node-1]=1;
			q.push({node-1,level+1});
		}
		if(!vis.count(node+1))
		{
			vis[node+1]=1;
			q.push({node+1,level+1});
		}
	}
	cout<<sum<<'\n';
	for(auto &v:a)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
