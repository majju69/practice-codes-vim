#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

pair<int,int> check(vector<string> &a,vector<vector<pair<int,int>>> &par)
{
	int n=a.size(),m=a[0].size(),dx[]={-1,1,0,0},dy[]={0,0,-1,1};
	queue<pair<pair<int,int>,int>> q;
	vector<vector<int>> mon_dist(n,vector<int>(m,1e9));
	vector<vector<bool>> vis(n,vector<bool>(m,0));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i][j]=='M')
			{
				q.push({{i,j},0});
				mon_dist[i][j]=0;
			}
		}
	}
	while(q.size())
	{
		int x=q.front().first.first,y=q.front().first.second,level=q.front().second;
		q.pop();
		for(int i=0;i<4;++i)
		{
			int r=x+dx[i],c=y+dy[i];
			if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!='#'&&mon_dist[r][c]>1+level)
			{
				q.push({{r,c},1+level});
				mon_dist[r][c]=1+level;
			}
		}
	}
	for(int i=0;i<n;++i)
	{
		if((int)q.size()>0)
		{
			break;
		}
		for(int j=0;j<m;++j)
		{
			if(a[i][j]=='A')
			{
				q.push({{i,j},0});
				par[i][j]={-1,-1};
				vis[i][j]=1;
			}
		}
	}
	while(q.size())
	{
		int x=q.front().first.first,y=q.front().first.second,level=q.front().second;
		q.pop();
		if(x==0||y==0||x==n-1||y==m-1)
		{
			return {x,y};
		}
		for(int i=0;i<4;++i)
		{
			int r=x+dx[i],c=y+dy[i];
			if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!='#'&&!vis[r][c]&&1+level<mon_dist[r][c])
			{
				q.push({{r,c},1+level});
				par[r][c]={x,y};
				vis[r][c]=1;
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
	int n,m;
	pair<int,int> p;
	cin>>n>>m;
	vector<string> a(n);
	vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m));
	for(auto &v:a)
	{
		cin>>v;
	}
	p=check(a,par);
	if(p.first==-1)
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
		vector<pair<int,int>> path;
		while(p.first!=-1)
		{
			path.push_back(p);
			p=par[p.first][p.second];
		}
		reverse(path.begin(),path.end());
		cout<<(int)path.size()-1<<'\n';
		for(int i=1;i<(int)path.size();++i)
		{
			pair<int,int> pvs=path[i-1],cur=path[i];
			if(pvs.first>cur.first)
			{
				cout<<'U';
			}
			if(pvs.first<cur.first)
			{
				cout<<'D';
			}
			if(pvs.second>cur.second)
			{
				cout<<'L';
			}
			if(pvs.second<cur.second)
			{
				cout<<'R';
			}
		}
		cout<<'\n';
	}
	return 0;
}
