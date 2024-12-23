#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

pair<int,int> check(int mid,vector<vector<int>> &a)
{
	int n=a.size(),m=a[0].size();
	vector<int> mask_idx((1<<m),-1);
	for(int i=0;i<n;++i)
	{
		int mask=0;
		for(int j=0;j<m;++j)
		{
			if(a[i][j]>=mid)
			{
				mask+=(1<<j);
			}
		}
		mask_idx[mask]=i;
	}
	for(int i=0;i<(1<<m);++i)
	{
		for(int j=i;j<(1<<m);++j)
		{
			if(mask_idx[i]!=-1&&mask_idx[j]!=-1&&((i|j)==(1<<m)-1))
			{
				return {mask_idx[i],mask_idx[j]};
			}
		}
	}
	return {-1,-1};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,lo=1e9,hi=-1e9;
	pair<int,int> ans={-1,-1};
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m,0));
	for(auto &vec:a)
	{
		for(auto &v:vec)
		{
			cin>>v;
			lo=min(lo,v);
			hi=max(hi,v);
		}
	}
	while(hi>=lo)
	{
		int mid=lo+(hi-lo)/2;
		pair<int,int> p=check(mid,a);
		if(p.first!=-1)
		{
			ans=p;
			lo=mid+1;
		}
		else
		{
			hi=mid-1;
		}
	}
	cout<<ans.first+1<<' '<<ans.second+1<<'\n';
	return 0;
}
