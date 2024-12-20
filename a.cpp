#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll N=1e5;
ll pos[N],heavy[N],head[N],par[N],depth[N],sub[N],cur_pos;

void init(ll n)
{
	cur_pos=0;
	for(ll i=0;i<n;++i)
	{
		pos[i]=heavy[i]=-1;
		head[i]=par[i]=i;
		depth[i]=sub[i]=0;
	}
}

void dfs(ll node,ll p,vector<ll> adj[])
{
	sub[node]=1;
	for(auto &v:adj[node])
	{
		if(v!=p)
		{
			depth[v]=depth[node]+1;
			par[v]=node;
			dfs(v,node,adj);
			sub[node]+=sub[v];
			if(heavy[node]==-1)
			{
				heavy[node]=v;
			}
			else
			{
				if(sub[heavy[node]]<sub[v])
				{
					heavy[node]=v;
				}
			}
		}
	}
}

void hld(ll node,ll chain,vector<ll> adj[])
{
	head[node]=chain;
	pos[node]=cur_pos++;
	if(heavy[node]!=-1)
	{
		hld(heavy[node],chain,adj);
	}
	for(auto &v:adj[node])
	{
		if(v!=heavy[node]&&v!=par[node])
		{
			hld(v,v,adj);
		}
	}
}

inline pair<ll,ll> merge(pair<ll,ll> a,pair<ll,ll> b)
{
	if(a.first<b.first)
	{
		return a;
	}
	if(a.first>b.first)
	{
		return b;
	}
	return {a.first,a.second+b.second};
}

class SegmentTree
{

private:

	vector<pair<ll,ll>> seg;
	vector<ll> lazy;

public:

	SegmentTree(ll n)
	{
		seg.resize(4*n+1);
		lazy.resize(4*n+1);
	}

	void build(ll ind,ll lo,ll hi)
	{
		if(lo==hi)
		{
			seg[ind]={0,1};
			return;
		}
		ll mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid);
		build(2*ind+2,mid+1,hi);
		seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
	}
	
	void update(ll ind,ll lo,ll hi,ll l,ll r,ll val)
	{
		if(lazy[ind]!=0)
		{
			seg[ind].first+=lazy[ind];
			if(lo!=hi)
			{
				lazy[2*ind+1]+=lazy[ind];
				lazy[2*ind+2]+=lazy[ind];
			}
			lazy[ind]=0;
		}
		if(l>hi||lo>r)
		{
			return;
		}
		if(l<=lo&&hi<=r)
		{
			seg[ind].first+=val;
			if(lo!=hi)
			{
				lazy[2*ind+1]+=val;
				lazy[2*ind+2]+=val;
			}
			return;
		}
		ll mid=lo+(hi-lo)/2;
		update(2*ind+1,lo,mid,l,r,val);
		update(2*ind+2,mid+1,hi,l,r,val);
		seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
	}


	pair<ll,ll> query(ll ind,ll lo,ll hi,ll l,ll r)
	{
		if(lazy[ind]!=0)
		{
			seg[ind].first+=lazy[ind];
			if(lo!=hi)
			{
				lazy[2*ind+1]+=lazy[ind];
				lazy[2*ind+2]+=lazy[ind];
			}
			lazy[ind]=0;
		}
		if(l>hi||lo>r)
		{
			return {1e18,0};
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		ll mid=lo+(hi-lo)/2;
		return merge(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,q,cur=0;
	cin>>n>>q;
	init(n);
	vector<ll> adj[n];
	for(ll i=1;i<n;++i)
	{
		ll u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0,0,adj);
	hld(0,0,adj);
	SegmentTree st(n);
	st.build(0,0,n-1);
	while(q--)
	{
		ll type,u,v,k;
		pair<ll,ll> p={-1,-1};
		cin>>type>>u>>v>>k;
		u--;
		v--;
		if(k==0)
		{
			cout<<cur<<'\n';
			continue;
		}
		if(type==1)
		{
			ll cnt=0;
			while(head[u]!=head[v])
			{
				if(depth[head[u]]<depth[head[v]])
				{
					swap(u,v);
				}
				p=st.query(0,0,n-1,pos[head[u]],pos[u]);
				if(p.first==0)
				{
					cnt+=p.second;
				}
				st.update(0,0,n-1,pos[head[u]],pos[u],k);
				u=par[head[u]];
			}
			if(depth[u]<depth[v])
			{
				swap(u,v);
			}
			p=st.query(0,0,n-1,pos[v],pos[u]);
			if(p.first==0)
			{
				cnt+=p.second;
			}
			st.update(0,0,n-1,pos[v],pos[u],k);
			cur+=cnt;
			cout<<cur<<'\n';
		}
		else
		{
			ll cur_u=u,cur_v=v;
			while(head[cur_u]!=head[cur_v])
			{
				if(depth[head[cur_u]]<depth[head[cur_v]])
				{
					swap(cur_u,cur_v);
				}
				k=min(k,st.query(0,0,n-1,pos[head[cur_u]],pos[cur_u]).first);
				cur_u=par[head[cur_u]];
			}
			if(depth[cur_u]<depth[cur_v])
			{
				swap(cur_u,cur_v);
			}
			k=min(k,st.query(0,0,n-1,pos[cur_v],pos[cur_u]).first);
			if(k==0)
			{
				cout<<cur<<'\n';
			}
			else
			{
				ll cnt=0;
				while(head[u]!=head[v])
				{
					if(depth[head[u]]<depth[head[v]])
					{
						swap(u,v);
					}
					st.update(0,0,n-1,pos[head[u]],pos[u],-k);
					p=st.query(0,0,n-1,pos[head[u]],pos[u]);
					if(p.first==0)
					{
						cnt+=p.second;
					}
					u=par[head[u]];
				}
				if(depth[u]<depth[v])
				{
					swap(u,v);
				}
				st.update(0,0,n-1,pos[v],pos[u],-k);
				p=st.query(0,0,n-1,pos[v],pos[u]);
				if(p.first==0)
				{
					cnt+=p.second;
				}
				cur-=cnt;
				cout<<cur<<'\n';
			}
		}
	}
	return 0;
}
