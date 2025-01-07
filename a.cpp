#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[200001][3];

int solve(int i,int pvs,vector<int> &idx)	// pvs 1 --> taken the pvs one
{
	if(i>=(int)idx.size())
	{
		return 0;
	}
	if(dp[i][pvs]!=-1)
	{
		return dp[i][pvs];
	}
	int ans=solve(i+1,0,idx);
	if(pvs!=1||idx[i]-idx[i-1]>1)
	{
		ans=max(ans,solve(i+1,1,idx)+1);
	}
	return dp[i][pvs]=ans;
}

int maxTakenIndices(vector<int> &idx)
{
	int n=idx.size();
	if(n==0)
	{
		return 0;
	}
	for(int i=0;i<=n;++i)
	{
		dp[i][0]=dp[i][1]=dp[i][2]=-1;
	}
	return max(solve(1,0,idx),1+solve(1,1,idx));
}

bool check(int mid,int k,vector<int> &a)		// check whether the given expression can be made <= mid
{
	int n=a.size();
	bool ok=0;
	vector<int> idx;
	for(int i=0;i<n;++i)
	{
		if(a[i]<=mid)
		{
			idx.push_back(i);
		}
	}
	if(k&1)
	{
		vector<int> tmp=idx;
		int req=(k>>1)+1;
		ok=(ok||maxTakenIndices(tmp)>=req);
		req-=1;
		if((int)tmp.size()>0&&tmp[0]==0)
		{
			reverse(tmp.begin(),tmp.end());
			tmp.pop_back();
			reverse(tmp.begin(),tmp.end());
		}
		if((int)tmp.size()>0&&tmp.back()==n-1)
		{
			tmp.pop_back();
		}
		ok=(ok||maxTakenIndices(tmp)>=req);
	}
	else
	{
		vector<int> odd=idx,even=idx;
		int req=(k>>1);
		if((int)even.size()>0&&even[0]==0)
		{
			reverse(even.begin(),even.end());
			even.pop_back();
			reverse(even.begin(),even.end());
		}
		if((int)odd.size()>0&&odd.back()==n-1)
		{
			odd.pop_back();
		}
		ok=(ok||maxTakenIndices(odd)>=req||maxTakenIndices(even)>=req);
	}
	return ok;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,lo=1,hi=1e9,ans=-1;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(check(mid,k,a))
		{
			ans=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
