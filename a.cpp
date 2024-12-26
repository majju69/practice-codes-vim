#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N=1e5;
int pos[N],heavy[N],depth[N],sub[N],head[N],par[N],cur_pos;

void init(int n)
{
	cur_pos=0;
	for(int i=0;i<n;++i)
	{
		pos[i]=heavy[i]=-1;
		depth[i]=sub[i]=0;
		head[i]=par[i]=i;
	}
}

void dfs(int node,int p,vector<int> adj[])
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
			if(heavy[node]==-1||sub[heavy[node]]<sub[v])
			{
				heavy[node]=v;
			}
		}
	}
}

void hld(int node,int chain,vector<int> adj[])
{
	pos[node]=cur_pos++;
	head[node]=chain;
	if(heavy[node]!=-1)
	{
		hld(heavy[node],chain,adj);
	}
	for(auto &v:adj[node])
	{
		if(v!=par[node]&&v!=heavy[node])
		{
			hld(v,v,adj);
		}
	}
}

class SegmentTree
{

private:

	vector<int> seg;

public:

	SegmentTree(int n)
	{
		seg.resize(4*n+1);
	}

	void build(int ind,int lo,int hi)
	{
		if(lo==hi)
		{
			seg[ind]=1;
			return;
		}
		int mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid);
		build(2*ind+2,mid+1,hi);
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}

	void update(int ind,int lo,int hi,int i)
	{
		if(lo==hi)
		{
			seg[ind]=1-seg[ind];
			return;
		}
		int mid=lo+(hi-lo)/2;
		if(i<=mid)
		{
			update(2*ind+1,lo,mid,i);
		}
		else
		{
			update(2*ind+2,mid+1,hi,i);
		}
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}

	int query(int ind,int lo,int hi,int l,int r)
	{
		if(l>hi||lo>r)
		{
			return 0;
		}
		if(l<=lo&&hi<=r)
		{
			return seg[ind];
		}
		int mid=lo+(hi-lo)/2;
		return query(2*ind+1,lo,mid,l,r)+query(2*ind+2,mid+1,hi,l,r);
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	vector<pair<int,int>> edges;
	cin>>n;
	init(n);
	vector<int> adj[n];
	for(int i=1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u,v});
	}
	dfs(0,0,adj);
	hld(0,0,adj);
	SegmentTree st(n);
	st.build(0,0,n-1);
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==3)
		{
			int u,v,d=-1,cnt=0;
			cin>>u>>v;
			u--;
			v--;
			d=depth[u]+depth[v];
			while(head[u]!=head[v])
			{
				if(depth[head[u]]<depth[head[v]])
				{
					swap(u,v);
				}
				cnt+=st.query(0,0,n-1,pos[head[u]],pos[u]);
				u=par[head[u]];
			}
			if(depth[u]<depth[v])
			{
				swap(u,v);
			}
			d-=(depth[v]<<1);
			if(u!=v)
			{
				cnt+=st.query(0,0,n-1,pos[v]+1,pos[u]);
			}
			cout<<((cnt==d)?d:-1)<<'\n';
		}
		else
		{
			int i,p=-1;
			cin>>i;
			i--;
			if(edges[i].first==par[edges[i].second])
			{
				p=edges[i].second;
			}
			else
			{
				p=edges[i].first;
			}
			st.update(0,0,n-1,pos[p]);
		}
	}
	return 0;
}
