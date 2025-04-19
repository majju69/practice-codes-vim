#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int dp[1001][6];		// 0->phi  1->n  2->na  3->nar  4->nare

int solve(int i,int cur,vector<string> &s)
{
	if(i>=(int)s.size())
	{
		return 5*(cur==5)-4*(cur==4)-3*(cur==3)-2*(cur==2)-(cur==1);
	}
	if(dp[i][cur]!=-1e9)
	{
		return dp[i][cur];
	}
	int skip=solve(i+1,cur,s),init_cur=cur,inc=0,dec=0;
	for(int j=0;j<(int)s[i].size();++j)
	{
		if(s[i][j]=='n')
		{
			if(cur==0)
			{
				cur=1;
			}
			else
			{
				dec++;
			}
		}
		else if(s[i][j]=='a')
		{
			if(cur==1)
			{
				cur=2;
			}
			else
			{
				dec++;
			}
		}
		else if(s[i][j]=='r')
		{
			if(cur==2)
			{
				cur=3;
			}
			else
			{
				dec++;
			}
		}
		else if(s[i][j]=='e')
		{
			if(cur==3)
			{
				cur=4;
			}
			else
			{
				dec++;
			}
		}
		else if(s[i][j]=='k')
		{
			if(cur==4)
			{
				cur=0;
				inc+=5;
			}
			else
			{
				dec++;
			}
		}
		else
		{
			continue;
		}
	}
	return dp[i][init_cur]=max(skip,solve(i+1,cur,s)+inc-dec);
}

int maxScore(vector<string> &s)
{
	int n=s.size();
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<6;++j)
		{
			dp[i][j]=-1e9;
		}
	}
	return solve(0,0,s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		vector<string> s(n);
		for(auto &v:s)
		{
			cin>>v;
		}
		cout<<maxScore(s)<<'\n';
	}
	return 0;
}
