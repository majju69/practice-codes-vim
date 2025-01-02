#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,ans=2e9;
	cin>>n;
	vector<int> a(n),right_inc(n),left_inc(n),left_idx(n,-1),right_idx(n,-1);
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		left_inc[i]=a[i]-i;
		right_inc[i]=a[i]+i;
	}
	for(int i=n-2;i>=0;--i)
	{
		if(i==n-2)
		{
			right_idx[i]=n-1;
		}
		else
		{
			if(right_inc[i+1]>right_inc[right_idx[i+1]])
			{
				right_idx[i]=i+1;
			}
			else
			{
				right_idx[i]=right_idx[i+1];
			}
		}
	}
	for(int i=1;i<n;++i)
	{
		if(i==1)
		{
			left_idx[i]=0;
		}
		else
		{
			if(left_inc[i-1]>left_inc[left_idx[i-1]])
			{
				left_idx[i]=i-1;
			}
			else
			{
				left_idx[i]=left_idx[i-1];
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		int mx=a[i];
		if(left_idx[i]!=-1)
		{
			mx=max(mx,n-1+a[left_idx[i]]-left_idx[i]);
		}
		if(right_idx[i]!=-1)
		{
			mx=max(mx,a[right_idx[i]]+right_idx[i]);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<'\n';
	return 0;
}
