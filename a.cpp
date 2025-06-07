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
			seg[ind]++;
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
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		bool ok=0;
		cin>>n;
		vector<int> a(n);
		vector<bool> present(n,0);
		for(auto &v:a)
		{
			cin>>v;
			v--;
			if(present[v])
			{
				ok=1;
			}
			else
			{
				present[v]=1;
			}
		}
		if(ok)
		{
			cout<<"YES\n";
		}
		else
		{
			int cnt=0;
			SegmentTree st(n);
			for(auto &v:a)
			{
				st.update(0,0,n-1,v);
				if(v!=n-1)
				{
					cnt+=st.query(0,0,n-1,v+1,n-1);
					cnt&=1;
				}
			}
			cout<<((cnt==0)?"YES":"NO")<<'\n';
		}
	}
	return 0;
}
