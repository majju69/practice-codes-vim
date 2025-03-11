#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

bool check(int mid,int k,vector<int> &arr)
{
	int n=arr.size(),sum=0;
	vector<int> a,pre,dp(n,0);
	for(auto &v:arr)
	{
		if(v>=mid)
		{
			a.push_back(1);
		}
		else
		{
			a.push_back(-1);
		}
		sum+=a.back();
		pre.push_back(sum);
	}
	for(int i=0;i<n;++i)
	{
		int s1=max(a[i],0),s2=a[i]+((i>0)?dp[i-1]:0);
		dp[i]=max(s1,s2);
	}
	for(int i=k-1;i<n;++i)
	{
		int s1=pre[i]-((i>=k)?pre[i-k]:0);
		int s2=s1+((i>=k)?dp[i-k]:0);
		if(max(s1,s2)>0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,lo=1e9,hi=-1e9,ans=-1;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
		lo=min(lo,v);
		hi=max(hi,v);
	}
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(check(mid,k,a))
		{
			ans=mid;
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
