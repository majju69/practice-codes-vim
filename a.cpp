// same code as easy version
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N=2e5;
int pos[N],heavy[N],head[N],par[N],depth[N],subtree[N],cur_pos;

// {{pre,suf},{max,sum}}
inline pair<pair<int,int>,pair<int,int>> merge_mx(pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b)
{
    pair<pair<int,int>,pair<int,int>> p;
    p.second.second=a.second.second+b.second.second;
    p.first.first=max(a.first.first,a.second.second+b.first.first);
    p.first.second=max(b.first.second,b.second.second+a.first.second);
    p.second.first=max({a.second.first,b.second.first,a.first.second+b.first.first});
    return p;
}

// {{pre,suf},{min,sum}}
inline pair<pair<int,int>,pair<int,int>> merge_mn(pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b)
{
    pair<pair<int,int>,pair<int,int>> p;
    p.second.second=a.second.second+b.second.second;
    p.first.first=min(a.first.first,a.second.second+b.first.first);
    p.first.second=min(b.first.second,b.second.second+a.first.second);
    p.second.first=min({a.second.first,b.second.first,a.first.second+b.first.first});
    return p;
}

void init(int n)
{
    cur_pos=0;
    for(int i=0;i<n;++i)
    {
        pos[i]=heavy[i]=-1;
        head[i]=par[i]=i;
        depth[i]=subtree[i]=0;
    }
}

void dfs(int node,int parent,vector<int> adj[])
{
	subtree[node]=1;
    for(auto &v:adj[node])
    {
        if(v!=parent)
        {
            depth[v]=depth[node]+1;
            par[v]=node;
            dfs(v,node,adj);
            subtree[node]+=subtree[v];
            if(heavy[node]==-1)
            {
                heavy[node]=v;
            }
            else
            {
                if(subtree[heavy[node]]<subtree[v])
                {
                    heavy[node]=v;
                }
            }
        }
    }
}
 
void hld(int node,int chain,vector<int> adj[],vector<int> &a,vector<int> &values)
{
    pos[node]=cur_pos++;
    head[node]=chain;
    a[pos[node]]=values[node];
    if(heavy[node]!=-1)
    {
        hld(heavy[node],chain,adj,a,values);
    }
    for(auto &v:adj[node])
    {
        if(v!=par[node]&&v!=heavy[node])
        {
            hld(v,v,adj,a,values);
        }
    }
}
 
class SegmentTree
{
 
private:
 
    vector<pair<pair<int,int>,pair<int,int>>> seg_mx;  // {{pre,suf},{max,sum}}    
    vector<pair<pair<int,int>,pair<int,int>>> seg_mn;  // {{pre,suf},{min,sum}}    

public:
 
    SegmentTree(int n)
    {
        for(int i=0;i<=4*n;++i)
        {
            seg_mx.push_back({{0,0},{0,0}});
            seg_mn.push_back({{0,0},{0,0}});
        }
    }
    
    void build(int ind,int lo,int hi,vector<int> &a)
    {
        if(lo==hi)
        {
            seg_mx[ind]={{max(0,a[lo]),max(0,a[lo])},{max(0,a[lo]),a[lo]}};
            seg_mn[ind]={{min(0,a[lo]),min(0,a[lo])},{min(0,a[lo]),a[lo]}};
            return;
        }
        int mid=lo+(hi-lo)/2;
        build(2*ind+1,lo,mid,a);
        build(2*ind+2,mid+1,hi,a);
        seg_mx[ind]=merge_mx(seg_mx[2*ind+1],seg_mx[2*ind+2]);
        seg_mn[ind]=merge_mn(seg_mn[2*ind+1],seg_mn[2*ind+2]);
    }
        
    pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>> query(int ind,int lo,int hi,int l,int r)
    {
        if(l>hi||lo>r)
        {
            return {{{1e9,1e9},{1e9,0}},{{-1e9,-1e9},{-1e9,0}}};
        }
        if(l<=lo&&hi<=r)
        {
            return {seg_mn[ind],seg_mx[ind]};
        }
        int mid=lo+(hi-lo)/2;
        pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>> left=query(2*ind+1,lo,mid,l,r),right=query(2*ind+2,mid+1,hi,l,r);
        return {merge_mn(left.first,right.first),merge_mx(left.second,right.second)};
    }
    
};

int lowestCommonAncestor(int u,int v)
{
    while(head[u]!=head[v])
    {
        if(depth[head[u]]<depth[head[v]])
        {
            swap(u,v);
        }
        u=par[head[u]];
    }
    if(depth[u]<depth[v])
    {
        swap(u,v);
    }
    return v;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int q,n=1;
		vector<int> values;
		vector<pair<int,int>> edges;
		vector<pair<pair<int,int>,int>> qry;
		cin>>q;
		values.push_back(1);
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='+')
			{
				int u,x;
				cin>>u>>x;
				u--;
				values.push_back(x);
				edges.push_back({u,n++});
			}
			else
			{
				int u,v,k;
				cin>>u>>v>>k;
				u--;
				v--;
				qry.push_back({{u,v},k});
			}
		}
		vector<int> adj[n],a(n);
		for(auto &edge:edges)
		{
			int u=edge.first,v=edge.second;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		init(n);
		dfs(0,0,adj);
		hld(0,0,adj,a,values);
		SegmentTree st(n);
		st.build(0,0,n-1,a);
		for(auto &qq:qry)
		{
			int node1=qq.first.first,node2=qq.first.second,k=qq.second,lca=-1;
			pair<pair<int,int>,pair<int,int>> p1_mx={{-1e9,-1e9},{-1e9,0}},p2_mx={{-1e9,-1e9},{-1e9,0}},p_mx;
			pair<pair<int,int>,pair<int,int>> p1_mn={{1e9,1e9},{1e9,0}},p2_mn={{1e9,1e9},{1e9,0}},p_mn;
			lca=lowestCommonAncestor(node1,node2);
			int u=node1,v=lca;
			while(head[u]!=head[v])
			{
				if(depth[head[u]]<depth[head[v]])
				{
					swap(u,v);
				}
				pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>> tmp=st.query(0,0,n-1,pos[head[u]],pos[u]);
				pair<pair<int,int>,pair<int,int>> tmp_mn=tmp.first,tmp_mx=tmp.second;
				swap(tmp_mn.first.second,tmp_mn.first.first);
				swap(tmp_mx.first.second,tmp_mx.first.first);
				p1_mn=merge_mn(p1_mn,tmp_mn);
				p1_mx=merge_mx(p1_mx,tmp_mx);
				u=par[head[u]];
			}
			if(depth[u]<depth[v])
			{
				swap(u,v);
			}
			pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>> tmp1=st.query(0,0,n-1,pos[v],pos[u]);
			pair<pair<int,int>,pair<int,int>> tmp1_mn=tmp1.first,tmp1_mx=tmp1.second;
			swap(tmp1_mn.first.second,tmp1_mn.first.first);
			swap(tmp1_mx.first.second,tmp1_mx.first.first);
			p1_mn=merge_mn(p1_mn,tmp1_mn);
			p1_mx=merge_mx(p1_mx,tmp1_mx);
			u=node2;
			v=lca;
			vector<pair<pair<int,int>,pair<int,int>>> tmp2_mn,tmp2_mx;
			while(head[u]!=head[v])
			{
				if(depth[head[u]]<depth[head[v]])
				{
					swap(u,v);
				}
				pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>> p_tmp=st.query(0,0,n-1,pos[head[u]],pos[u]);
				tmp2_mn.push_back(p_tmp.first);
				tmp2_mx.push_back(p_tmp.second);
				u=par[head[u]];
			}
			if(u!=v)
			{
				if(depth[u]<depth[v])
				{
					swap(u,v);
				}
				pair<pair<pair<int,int>,pair<int,int>>,pair<pair<int,int>,pair<int,int>>> p_tmp=st.query(0,0,n-1,pos[v]+1,pos[u]);
				tmp2_mn.push_back(p_tmp.first);
				tmp2_mx.push_back(p_tmp.second);
			}
			reverse(tmp2_mn.begin(),tmp2_mn.end());
			reverse(tmp2_mx.begin(),tmp2_mx.end());
			for(auto &v1:tmp2_mn)
            {
                p2_mn=merge_mn(p2_mn,v1);
            }
			for(auto &v1:tmp2_mx)
            {
                p2_mx=merge_mx(p2_mx,v1);
            }
			p_mn=merge_mn(p1_mn,p2_mn);
			p_mx=merge_mx(p1_mx,p2_mx);
			cout<<((p_mn.second.first<=k&&k<=p_mx.second.first)?"YES":"NO")<<'\n';
		}
	}
	return 0;
}
