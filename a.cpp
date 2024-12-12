#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

map<string,int> mp={{"DR",0},{"DL",1},{"UR",2},{"UL",3}};

inline pair<pair<int,int>,int> get(int i,int j,int n,int m,int d)
{
	if(d==0)
	{
		int x=i+1,y=j+1;
		if(x<n&&y<m)
		{
			return {{x,y},0};
		}
		if(x>=n&&y>=m)
		{
			return {{i-1,j-1},3};
		}
		if(x<n&&y>=m)
		{
			return {{x,j-1},1};
		}
		return {{i-1,y},2};
	}
	if(d==1)
	{
		int x=i+1,y=j-1;
		if(x<n&&y>=0)
		{
			return {{x,y},1};
		}
		if(x>=n&&y<0)
		{
			return {{i-1,j+1},2};
		}
		if(x<n&&y<0)
		{
			return {{x,j+1},0};
		}
		return {{i-1,y},3};
	}
	if(d==2)
	{
		int x=i-1,y=j+1;
		if(x>=0&&y<m)
		{
			return {{x,y},2};
		}
		if(x<0&&y>=m)
		{
			return {{i+1,j-1},1};
		}
		if(x>=0&&y>=m)
		{
			return {{x,j-1},3};
		}
		return {{i+1,y},0};
	}
	// d==3
	int x=i-1,y=j-1;
	if(x>=0&&y>=0)
	{
		return {{x,y},3};
	}
	if(x<0&&y<0)
	{
		return {{i+1,j+1},0};
	}
	if(x>=0&&y<0)
	{
		return {{x,j+1},2};
	}
	return {{i+1,y},1};
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
		int n,m,i1,j1,i2,j2,ans=-1;
		string d;
		queue<pair<pair<int,int>,pair<int,int>>> q;
		cin>>n>>m>>i1>>j1>>i2>>j2>>d;
		i1--;
		j1--;
		i2--;
		j2--;
		vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(4,0)));
		q.push({{i1,j1},{mp[d],0}});
		vis[i1][j1][mp[d]]=1;
		while(q.size())
		{
			int i=q.front().first.first,j=q.front().first.second,dir=q.front().second.first,dist=q.front().second.second;
			q.pop();
			if(i==i2&&j==j2)
			{
				ans=dist;
				break;
			}
			pair<pair<int,int>,int> p=get(i,j,n,m,dir);
			if(!vis[p.first.first][p.first.second][p.second])
			{
				vis[p.first.first][p.first.second][p.second]=1;
				q.push({{p.first.first,p.first.second},{p.second,dist+(dir!=p.second)}});
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
