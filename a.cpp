#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

class SegmentTree
{

private:

	vector<int> seg;

public:

	SegmentTree(int n)
	{
		seg.resize(4*n+1);
	}

	void update(int ind,int lo,int hi,int i)
	{
		if(lo==hi)
		{
			seg[ind]=1;
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
	int n,ind=0;
	map<int,int> mp;
	cin>>n;
	vector<int> a(2*n),idx(2*n),left(n),right(n),ans(n);
	vector<pair<int,int>> arr(n);
	for(auto &v:arr)
	{
		cin>>v.first>>v.second;
		mp[v.first]=mp[v.second]=0;
	}
	for(auto &v:mp)
	{
		v.second=ind++;
	}
	for(int i=0;i<n;++i)
	{
		arr[i].first=mp[arr[i].first];
		arr[i].second=mp[arr[i].second];
		idx[arr[i].first]=i;
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;++i)
	{
		a[arr[i].first]=a[arr[i].second]=i;
		left[i]=arr[i].first;
		right[i]=arr[i].second;
	}
	n<<=1;
	SegmentTree st(n);
	for(int i=0;i<n;++i)
	{
		if(right[a[i]]==i)
		{
			ans[idx[left[a[i]]]]=st.query(0,0,n-1,left[a[i]],right[a[i]]);
			st.update(0,0,n-1,left[a[i]]);
		}
	}
	for(auto &v:ans)
	{
		cout<<v<<'\n';
	}
	return 0;
}
