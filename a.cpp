#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

void bfs(int src_i,int src_j,int bad,vector<vector<int>> &dist,vector<string> &a)
{
	int n=a.size(),m=a[0].size();
	deque<pair<int,int>> q;
	dist[src_i][src_j]=0;
	q.push_front({src_i,src_j});
	while(q.size())
	{
		int x=q.front().first,y=q.front().second;
		q.pop_front();
		for(int i=0;i<4;++i)
		{
			int r=x+dx[i],c=y+dy[i],dis=(i==bad);
			if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]=='.'&&dis+dist[x][y]<dist[r][c])
			{
				dist[r][c]=dis+dist[x][y];
				if(dis==0)
				{
					q.push_front({r,c});
				}
				else
				{
					q.push_back({r,c});
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,src_i,src_j,x,y,ans=0;
	cin>>n>>m>>src_i>>src_j>>x>>y;
	vector<string> a(n);
	vector<vector<int>> l_dist(n,vector<int>(m,1e9)),r_dist(n,vector<int>(m,1e9));
	for(auto &v:a)
	{
		cin>>v;
	}
	src_i--;
	src_j--;
	bfs(src_i,src_j,2,l_dist,a);
	bfs(src_i,src_j,3,r_dist,a);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			ans+=(a[i][j]=='.'&&l_dist[i][j]<=x&&r_dist[i][j]<=y);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
