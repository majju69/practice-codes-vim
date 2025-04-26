#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int bit(int a,int i)
{
	return a>>i&1;
}

int maxProfit(int n,vector<vector<int>> &edges,vector<int> &score)
{
	vector<int> badMask(n,0),dp((1<<n),0);
	for(auto &edge:edges)
	{
		badMask[edge[0]]|=(1<<edge[1]);
	}
	for(int mask=1;mask<(1<<n);++mask)
	{
		int cnt=__builtin_popcount(mask);
		if(mask==1)
		{
			for(int i=0;i<n;++i)
			{
				if(bit(mask,i))
				{
					dp[mask]=score[i];
					break;
				}
			}
		}
		else
		{
			for(int i=0;i<n;++i)
			{
				if(bit(mask,i))
				{
					int curMask=(mask^(1<<i));
					if((curMask&badMask[i])==0)
					{
						dp[mask]=max(dp[mask],dp[curMask]+cnt*score[i]);
					}
				}
			}
		}
	}
	return dp.back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edges(m,vector<int>(2,0));
	vector<int> score(n);
	for(auto &edge:edges)
	{
		cin>>edge[0]>>edge[1];
	}
	for(auto &v:score)
	{
		cin>>v;
	}
	cout<<maxProfit(n,edges,score)<<'\n';
	return 0;
}
