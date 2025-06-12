// SAME AS HARD VERSION
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

void dfs(ll node,vector<bool> &vis,vector<ll> adj[],vector<bool> &good,vector<ll> &cur,ll &ok)
{
	vis[node]=1;
	cur.push_back(node);
	if(good[node])
	{
		ok=1;
	}
	for(auto &v:adj[node])
	{
		if(!vis[v])
		{
			dfs(v,vis,adj,good,cur,ok);
		}
	}
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
		ll n,k,q;
		map<ll,vector<ll>> mp_fwd,mp_bck;
		cin>>n>>k;
		vector<ll> pos(n),mod_class(n);
		vector<ll> adj[2*n];
		vector<bool> vis(2*n,0),good(2*n,0);
		for(auto &v:pos)
		{
			cin>>v;
		}
		for(auto &v:mod_class)
		{
			cin>>v;
		}
		for(ll i=0;i<n;++i)
		{
			mp_fwd[((pos[i]-mod_class[i])%k+k)%k].push_back(i);
			mp_bck[(pos[i]+mod_class[i])%k].push_back(i);
		}
		for(ll i=0;i<n;++i)
		{
			ll cur_fwd=((pos[i]-mod_class[i])%k+k)%k,cur_bck=(pos[i]+mod_class[i])%k;
			vector<ll> &vec_fwd=mp_fwd[cur_fwd],&vec_bck=mp_bck[cur_bck];
			auto it_fwd=upper_bound(vec_fwd.begin(),vec_fwd.end(),i);
			if(it_fwd==vec_fwd.end())
			{
				good[2*i+1]=1;
			}
			else
			{
				adj[2*i+1].push_back(2*(*it_fwd));
				adj[2*(*it_fwd)].push_back(2*i+1);
			}
			if(vec_bck[0]>=i)
			{
				good[2*i]=1;
			}
			else
			{
				auto it=--lower_bound(vec_bck.begin(),vec_bck.end(),i);
				adj[2*i].push_back(2*(*it)+1);
				adj[2*(*it)+1].push_back(2*i);
			}
		}
		for(ll i=0;i<2*n;++i)
		{
			if(!vis[i])
			{
				ll ok=0;
				vector<ll> cur;
				dfs(i,vis,adj,good,cur,ok);
				if(ok)
				{
					for(auto &v:cur)
					{
						good[v]=1;
					}
				}
			}
		}
		cin>>q;
		while(q--)
		{
			ll x,_x=-1;
			cin>>x;
			_x=x;
			x%=k;
			if(!mp_fwd.count(x))
			{
				cout<<"YES\n";
			}
			else
			{
				vector<ll> &vec=mp_fwd[x];
				if(pos[vec.back()]<_x)
				{
					cout<<"YES\n";
				}
				else
				{
					ll lo=0,hi=(ll)vec.size()-1,ans=-1;
					while(lo<=hi)
					{
						ll mid=lo+(hi-lo)/2;
						if(pos[vec[mid]]>=_x)
						{
							ans=mid;
							hi=mid-1;
						}
						else
						{
							lo=mid+1;
						}
					}
					cout<<((ans==-1||good[2*vec[ans]])?"YES":"NO")<<'\n';
				}
			}
		}
	}
	return 0;
}
