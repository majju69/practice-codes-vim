#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

struct Query
{
	int lt,rt,blk,idx;
};

bool cmp(Query a,Query b)
{
	if(a.blk==b.blk)
	{
		if(a.blk&1)
		{
			return a.rt<b.rt;
		}
		return a.rt>b.rt;
	}
	return a.blk<b.blk;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,mn=1e9,mx=-1e9,sz=1;
	cin>>n;
	vector<Query> qry(n);
	for(int i=0;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		mn=min(mn,min(x,y));
		mx=max(mx,max(x,y));
		qry[i].lt=x;
		qry[i].rt=y;
		qry[i].idx=i+1;
	}
	if(mn!=mx)
	{
		sz=floor(sqrtl(mx-mn));
	}
	for(auto &q:qry)
	{
		q.blk=q.lt/sz;
	}
	sort(qry.begin(),qry.end(),cmp);
	for(auto &q:qry)
	{
		cout<<q.idx<<' ';
	}
	cout<<'\n';
	return 0;
}
