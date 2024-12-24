#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

bool check(int x,int y,vector<string> &a)
{
	int n=a.size(),m=a[0].size(),cnt=0;
	if(x>=n||x<0||y>=m||y<0||a[x][y]!='.')
	{
		return 0;
	}
	for(int i=0;i<4;++i)
	{
		int r=x+dx[i],c=y+dy[i];
		cnt+=(r>=0&&r<n&&c>=0&&c<m&&a[r][c]=='.');
	}
	return cnt<=1;
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
		int n,m,src_i=-1,src_j=-1;
		queue<pair<int,int>> q;
		cin>>n>>m;
		vector<string> a(n),tmp;
		for(auto &s:a)
		{
			cin>>s;
		}
		for(int i=0;i<n;++i)
		{
			if(src_i!=-1)
			{
				break;
			}
			for(int j=0;j<m;++j)
			{
				if(a[i][j]=='L')
				{
					src_i=i;
					src_j=j;
				}
			}
		}
		tmp=a;
		tmp[src_i][src_j]='#';
		q.push({src_i,src_j});
		while(q.size())
		{
			int x=q.front().first,y=q.front().second;
			q.pop();
			for(int i=0;i<4;++i)
			{
				int r=x+dx[i],c=y+dy[i];
				if(check(r,c,tmp))
				{
					tmp[r][c]='+';
					q.push({r,c});
				}
			}
		}
		tmp[src_i][src_j]='L';
		for(auto &s:tmp)
		{
			cout<<s<<'\n';
		}
	}
	return 0;
}	
