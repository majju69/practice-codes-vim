#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int gcd(int a,int b)
{
	return ((b==0)?a:gcd(b,a%b));
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

	void build(int ind,int lo,int hi,vector<int> &a)
	{
		if(lo==hi)
		{
			seg[ind]=a[lo];
			return;
		}
		int mid=lo+(hi-lo)/2;
		build(2*ind+1,lo,mid,a);
		build(2*ind+2,mid+1,hi,a);
		seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
	}

	void update(int ind,int lo,int hi,int i,int val)
	{
		if(lo==hi)
		{
			seg[ind]=val;
			return;
		}
		int mid=lo+(hi-lo)/2;
		if(i<=mid)
		{
			update(2*ind+1,lo,mid,i,val);
		}
		else
		{
			update(2*ind+2,mid+1,hi,i,val);
		}
		seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
	}

	int findFirst(int ind,int lo,int hi,int l,int r,int x)
	{
		if(l>hi||lo>r||seg[ind]%x==0)
		{
			return -1;
		}
		if(lo==hi)
		{
			return lo;
		}
		int mid=lo+(hi-lo)/2;
		int ans=findFirst(2*ind+1,lo,mid,l,r,x);
		if(ans==-1)
		{
			ans=findFirst(2*ind+2,mid+1,hi,l,r,x);
		}
		return ans;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	SegmentTree st(n);
	st.build(0,0,n-1,a);
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			int idx=st.findFirst(0,0,n-1,l,r,x);
			if(idx==-1)
			{
				cout<<"YES\n";
			}
			else
			{
				int left=-1,right=-1;
				if(l<=idx-1)
				{
					left=st.findFirst(0,0,n-1,l,idx-1,x);
				}
				if(idx+1<=r)
				{
					right=st.findFirst(0,0,n-1,idx+1,r,x);
				}
				if(left!=-1||right!=-1)
				{
					cout<<"NO\n";
				}
				else
				{
					cout<<"YES\n";
				}
			}
		}
		else
		{
			int i,v;
			cin>>i>>v;
			i--;
			st.update(0,0,n-1,i,v);
		}
	}
	return 0;
}
