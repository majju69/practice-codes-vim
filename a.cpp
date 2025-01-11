#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<vector<int>> divisors(200001);

void fillDivisors()
{
	int n=divisors.size();
	for(int i=2;i<n;i++)
	{
		for(int j=i;j<n;j+=i)
		{
			divisors[j].push_back(i);
		}
	}
}

int dp[200001];

int solve(int i,vector<pair<int,int>> &a,vector<int> &idx)
{
	if(i>=(int)a.size())
	{
		return 0;
	}
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	int ans=a[i].second;
	for(auto &v:divisors[a[i].first])
	{
		if(v==a[i].first||idx[v]==-1)
		{
			continue;
		}
		ans=max(ans,solve(idx[v],a,idx)+a[i].second);
	}
	return dp[i]=ans;
}

int maxTaken(vector<pair<int,int>> &a,vector<int> &idx)
{
	int n=a.size(),ans=0;
	for(int i=0;i<=n;++i)
	{
		dp[i]=-1;
	}
	for(int i=0;i<n;++i)
	{
		ans=max(ans,solve(i,a,idx));
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillDivisors();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,mx=-1;
		map<int,int> mp;
		vector<pair<int,int>> a;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			mp[x]++;
		}
		for(auto &v:mp)
		{
			if(v.first!=1)
			{
				a.push_back(v);
				mx=max(mx,v.first);
			}
		}
		if(mx==-1)
		{
			cout<<0<<'\n';
		}
		else
		{
			int total=0;
			vector<int> idx(mx+1,-1);
			reverse(a.begin(),a.end());
			n=a.size();
			for(int i=0;i<n;++i)
			{
				idx[a[i].first]=i;
				total+=a[i].second;
			}
			cout<<total-maxTaken(a,idx)<<'\n';
		}
	}
	return 0;
}
