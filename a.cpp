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
	ll n,m,k;
	set<pair<ll,ll>> st;
	map<pair<ll,ll>,ll> mp;
	set<ll> ans;
	cin>>n>>m>>k;
	vector<pair<ll,ll>> *adj=new vector<pair<ll,ll>>[n];
	ll *d1=new ll[n],*d2=new ll[n];
	for(int i=0;i<m;++i)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		if(u>v)
		{
			swap(u,v);
		}
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		mp[{u,v}]=i;
	}
	fill(d1,d1+n,(ll)1e18);
	fill(d2,d2+n,(ll)1e18);
	st.insert({0,0});
	d1[0]=0;
	while((ll)st.size())
	{
		auto it=st.begin();
		ll node=it->second,dist=it->first;
		st.erase(*it);
		for(auto &v:adj[node])
		{
			ll curNode=v.first,curDist=v.second;
			if(d1[curNode]>dist+curDist)
			{
				if(d1[curNode]!=(ll)1e18)
				{
					st.erase({d1[curNode],curNode});
				}
				d1[curNode]=curDist+dist;
				st.insert({d1[curNode],curNode});
			}
		}
	}
	st.insert({0,0});
	d2[0]=0;
	while((ll)st.size())
	{
		if(k<=0)
		{
			st.clear();
			break;
		}
		auto it=st.begin();
		ll node=it->second,dist=it->first;
		st.erase(*it);
		for(auto &v:adj[node])
		{
			if(k<=0)
			{
				break;
			}
			ll curNode=v.first,curDist=v.second;
			if(d2[curNode]>dist+curDist)
			{
				if(d1[curNode]!=(ll)1e18)
				{
					st.erase({d2[curNode],curNode});
				}
				d2[curNode]=curDist+dist;
				st.insert({d2[curNode],curNode});
				if(d2[curNode]==d1[curNode])
				{
					ll u=curNode,v=node;
					if(u>v)
					{
						swap(u,v);
					}
					ans.insert(mp[{u,v}]);
					k--;
				}
			}
		}
	}
	cout<<(ll)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v+1<<' ';
	}
	cout<<'\n';
	delete []adj;
	delete []d1;
	delete []d2;
	return 0;
}
