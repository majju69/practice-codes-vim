#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N=1e5+10,BLK=317;
int a[N],freq[1<<20];
long long ans[N];

struct Query
{
	int lt,rt,blk,idx;
}qry[N];

bool cmp(Query a,Query b)
{
	if(a.blk==b.blk)
	{
		if(a.blk&1)
		{
			return a.rt<b.rt;
		}
		else
		{
			return a.rt>b.rt;
		}
	}
	return a.blk<b.blk;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,k,i1=0,i2=-1;
	long long cur_ans=0;
	cin>>n>>q>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=0;i<q;++i)
	{
		int l,r;
		cin>>l>>r;
		l--;
		qry[i].lt=l;
		qry[i].rt=r;
		qry[i].blk=l/BLK;
		qry[i].idx=i;
	}
	sort(qry,qry+q,cmp);
	for(int i=0;i<q;++i)
	{
		while(qry[i].lt<i1)
		{
			i1--;
			cur_ans+=freq[a[i1]^k];
			freq[a[i1]]++;
		}
		while(qry[i].rt>i2)
		{
			i2++;
			cur_ans+=freq[a[i2]^k];
			freq[a[i2]]++;
		}
		while(qry[i].lt>i1)
		{
			freq[a[i1]]--;
			cur_ans-=freq[a[i1]^k];
			i1++;
		}
		while(qry[i].rt<i2)
		{
			freq[a[i2]]--;
			cur_ans-=freq[a[i2]^k];
			i2--;
		}
		ans[qry[i].idx]=cur_ans;
	}
	for(int i=0;i<q;++i)
	{
		cout<<ans[i]<<'\n';
	}
	return 0;
}
