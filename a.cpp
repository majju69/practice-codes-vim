#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

long long power(long long a,long long b)        // Use when mod is of order 10^9 or less
{
	long long ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return ans%mod;
}

inline ll mul(ll a,ll b)
{
	return (a%mod*b%mod)%mod;
}

inline ll sub(ll a,ll b)
{
	return (a%mod-b%mod+mod)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,cnt=0,ans=1;
	queue<ll> q;
	cin>>n;
	vector<ll> adj[n],indegree(n,0);
	vector<bool> vis(n,0);
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		x--;
		adj[i].push_back(x);
		indegree[x]++;
	}
	for(ll i=0;i<n;++i)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(q.size())
	{
		ll node=q.front();
		q.pop();
		cnt++;
		vis[node]=1;
		for(auto &v:adj[node])
		{
			indegree[v]--;
			if(indegree[v]==0)
			{
				q.push(v);
			}
		}
	}
	ans=mul(ans,power(2,cnt));
	for(ll i=0;i<n;++i)
	{
		if(!vis[i])
		{
			cnt=0;
			ll cur=i;
			while(!vis[cur])
			{
				vis[cur]=1;
				cnt++;
				cur=adj[cur][0];
			}
			ans=mul(ans,sub(power(2,cnt),2));
		}
	}
	cout<<ans<<'\n';
	return 0;
}
