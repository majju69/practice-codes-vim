#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

int dp[20][2][2][1000];

int solve(int i,bool first,bool last,int mask,string &s,string &t)
{
	if(i>=(int)s.size())
	{
		if(mask==0)
		{
			return 10;
		}
		int mn=10,mx=-1;
		for(int j=0;j<=9;++j)
		{
			if(mask>>j&1)
			{
				mx=max(mx,j);
				mn=min(mn,j);
			}
		}
		return mx-mn;
	}
	if(dp[i][first][last][mask]!=-1)
	{
		return dp[i][first][last][mask];
	}
	int ans=10,from=(first?(s[i]-'0'):0),till=(last?(t[i]-'0'):9);
	for(int j=from;j<=till;++j)
	{
		if(j==0)
		{
			if(mask==0)
			{
				ans=min(ans,solve(i+1,(first&&(j==from)),(last&&(j==till)),mask,s,t));
			}
			else
			{
				ans=min(ans,solve(i+1,(first&&(j==from)),(last&&(j==till)),(mask|1),s,t));
			}
		}
		else
		{
			ans=min(ans,solve(i+1,(first&&(j==from)),(last&&(j==till)),(mask|(1<<j)),s,t));
		}
	}
	return dp[i][first][last][mask]=ans;
}

int get_min(string &s,string &t)
{
	memset(dp,-1,sizeof(dp));
	return solve(0,1,1,0,s,t);
}

void print(int i,bool first,bool last,int mask,string &s,string &t)
{
	if(i>=(int)s.size())
	{
		return;
	}
	int from=(first?(s[i]-'0'):0),till=(last?(t[i]-'0'):9);
	for(int j=from;j<=till;++j)
	{
		if(j==0)
		{
			if(mask==0)
			{
				if(solve(i+1,(first&&(j==from)),(last&&(j==till)),mask,s,t)==dp[i][first][last][mask])
				{
					print(i+1,(first&&(j==from)),(last&&(j==till)),mask,s,t);
					return;
				}
			}
			else
			{
				if(solve(i+1,(first&&(j==from)),(last&&(j==till)),(mask|1),s,t)==dp[i][first][last][mask])
				{
					cout<<j;
					print(i+1,(first&&(j==from)),(last&&(j==till)),(mask|1),s,t);
					return;
				}
			}
		}
		else
		{
			if(solve(i+1,(first&&(j==from)),(last&&(j==till)),(mask|(1<<j)),s,t)==dp[i][first][last][mask])
			{
				cout<<j;
				print(i+1,(first&&(j==from)),(last&&(j==till)),(mask|(1<<j)),s,t);
				return;
			}
		}
	}
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
		ll a,b;
		cin>>a>>b;
		string s=to_string(a),t=to_string(b);
		reverse(s.begin(),s.end());
		while((int)s.size()<(int)t.size())
		{
			 s.push_back('0');
		}
		reverse(s.begin(),s.end());
		get_min(s,t);
		print(0,1,1,0,s,t);
		cout<<'\n';
	}
	return 0;
}
