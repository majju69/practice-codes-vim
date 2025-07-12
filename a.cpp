#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N=1e5+10,BLK=318;
int a[N];
pair<pair<int,int>,int> pre[N];

inline int get_blk(int i)
{
	return i/BLK;
}

void build(int n)
{
	for(int i=n-1;i>=0;--i)
	{
		if(i+a[i]>=n||get_blk(i+a[i])>get_blk(i))
		{
			pre[i]={{1,min(n,i+a[i])},i};
		}
		else
		{
			pre[i]={{pre[i+a[i]].first.first+1,pre[i+a[i]].first.second},pre[i+a[i]].second};
		}
	}
}

void update(int idx,int val,int n)
{
	a[idx]=val;
	for(int i=idx;i>=get_blk(idx)*BLK;--i)
	{
		if(i+a[i]>=n||get_blk(i+a[i])>get_blk(i))
		{
			pre[i]={{1,min(n,i+a[i])},i};
		}
		else
		{
			pre[i]={{pre[i+a[i]].first.first+1,pre[i+a[i]].first.second},pre[i+a[i]].second};
		}
	}
}

pair<int,int> query(int idx,int n)
{
	int cur=idx,num_jumps=0,last=-1;
	while(cur<n)
	{
		num_jumps+=pre[cur].first.first;
		last=pre[cur].second;
		cur=pre[cur].first.second;
	}
	return {last+1,num_jumps};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	build(n);
	while(q--)
	{
		int type;
		cin>>type;
		if(type==0)
		{
			int idx,val;
			cin>>idx>>val;
			idx--;
			update(idx,val,n);
		}
		else
		{
			int idx;
			cin>>idx;
			idx--;
			pair<int,int> p=query(idx,n);
			cout<<p.first<<' '<<p.second<<'\n';
		}
	}
	return 0;
}
