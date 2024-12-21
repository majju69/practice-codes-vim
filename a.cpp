#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<vector<int>> bfs(char src,vector<string> &a)
{
	int n=a.size(),m=a[0].size(),dx[]={-1,1,0,0},dy[]={0,0,-1,1};
	vector<vector<int>> dist(n,vector<int>(m,1e8));
	deque<pair<int,int>> q;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i][j]==src)
			{
				q.push_front({i,j});
				dist[i][j]=0;
			}
		}
	}
	while(q.size())
	{
		int x=q[0].first,y=q[0].second,dis=dist[x][y];
		q.pop_front();
		for(int i=0;i<4;++i)
		{
			int r=x+dx[i],c=y+dy[i];
			if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!='#')
			{
				int w=(a[r][c]=='.');
				if(dist[r][c]>dis+w)
				{
					dist[r][c]=dis+w;
					if(w==1)
					{
						q.push_back({r,c});
					}
					else
					{
						q.push_front({r,c});
					}
				}
			}
		}
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,ans=1e8;
	vector<vector<int>> dist1,dist2,dist3;
	cin>>n>>m;
	vector<string> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	dist1=bfs('1',a);
	dist2=bfs('2',a);
	dist3=bfs('3',a);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			ans=min(ans,dist1[i][j]+dist2[i][j]+dist3[i][j]-2*(a[i][j]=='.'));
		}
	}
	if(ans>=1e8)
	{
		ans=-1;
	}
	cout<<ans<<'\n';
	return 0;
}
