#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

bool check(int mid,int m,int k,vector<int> &a)		// discarded mid boxes
{
	int n=a.size(),cnt=1,sum=0;
	for(int i=mid;i<n;++i)
	{
		sum+=a[i];
		if(sum>k)
		{
			sum=a[i];
			cnt++;
		}
	}
	return (cnt<=m);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k,lo=0,hi=-1,mn=1e9;
	cin>>n>>m>>k;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	hi=n;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(check(mid,m,k,a))
		{
			mn=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<n-mn<<'\n';
	return 0;
}
