#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N=2e5+10,P=2e5+3;
int a[N],seg[4*N],ans[N];

int gcd(int a,int b)
{
	return ((b==0)?a:gcd(b,a%b));
}

void build(int ind,int lo,int hi)
{
	if(lo==hi)
	{
		seg[ind]=a[lo];
		return;
	}
	int mid=lo+(hi-lo)/2;
	build(2*ind+1,lo,mid);
	build(2*ind+2,mid+1,hi);
	seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
}

void update(int ind,int lo,int hi,int i)
{
	if(lo==hi)
	{
		seg[ind]=P;
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
	seg[ind]=gcd(seg[2*ind+1],seg[2*ind+2]);
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
	return gcd(query(2*ind+1,lo,mid,l,r),query(2*ind+2,mid+1,hi,l,r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	build(0,0,n-1);
	if(a[0]==1)
	{
		update(0,0,n-1,0);
		ans[0]=1;
		a[0]=P;
	}
	for(int i=1;i<n;++i)
	{
		// len-gcd is inc
		int lo=0,hi=i;
		bool bad=0;
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2;
			int len=i-mid+1,g=query(0,0,n-1,mid,i);
			if(len-g==0)
			{
				bad=1;
				break;
			}
			else if(len-g>0)
			{
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		if(bad)
		{
			ans[i]=ans[i-1]+1;
			update(0,0,n-1,i);
			a[i]=P;
		}
		else
		{
			ans[i]=ans[i-1];
		}
	}
	for(int i=0;i<n;++i)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}	
