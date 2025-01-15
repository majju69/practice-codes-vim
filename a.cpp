#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll N=1e7+10;
vector<ll> dist(N,1e18);

void bfs(ll x,ll y)
{
	ll mx=max(x,y);
	deque<ll> q;
	dist[0]=0;
	q.push_front(0);
	while(q.size())
	{
		ll node=q.front();
		q.pop_front();
		if(node+1<N)
		{
			if(dist[node]+x<dist[node+1])
			{
				dist[node+1]=dist[node]+x;
				if(x==mx)
				{
					q.push_back(node+1);
				}
				else
				{
					q.push_front(node+1);
				}
			}
		}
		if(node-1>=0)
		{
			if(dist[node]+x<dist[node-1])
			{
				dist[node-1]=dist[node]+x;
				if(x==mx)
				{
					q.push_back(node-1);
				}
				else
				{
					q.push_front(node-1);
				}
			}
		}
		if((node<<1)<N)
		{
			if(dist[node]+y<dist[(node<<1)])
			{
				dist[(node<<1)]=dist[node]+y;
				if(y==mx)
				{
					q.push_back(node<<1);
				}
				else
				{
					q.push_front(node<<1);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,x,y;
	cin>>n>>x>>y;
	bfs(x,y);
	cout<<dist[n]<<'\n';
	return 0;
}
