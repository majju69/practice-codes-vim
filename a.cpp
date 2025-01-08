#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

pair<int,pair<int,int>> get(vector<string> &adjMat,char ch)
{
	int n=adjMat.size();
	vector<vector<bool>> same_ch(n,vector<bool>(n,0));
	vector<pair<int,int>> edges;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(adjMat[i][j]==ch)
			{
				same_ch[i][j]=1;
				edges.push_back({i,j});
			}
		}
	}
	for(auto &edge:edges)
	{
		int u=edge.first,v=edge.second;
		for(int i=0;i<n;++i)
		{
			if(same_ch[v][i])
			{
				return {u,{v,i}};
			}
		}
	}
	return {-1,{-1,-1}};
}

void print(int u,int v,int m)
{
	int cur=u;
	m++;
	while(m--)
	{
		cout<<cur+1<<' ';
		cur=u+v-cur;
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
		int n,m;
		cin>>n>>m;
		vector<string> adjMat(n);
		for(auto &v:adjMat)
		{
			cin>>v;
		}
		if(m&1)
		{
			cout<<"YES\n";
			print(0,1,m);
			cout<<'\n';
		}
		else
		{
			int i1=-1,i2=-1;
			for(int i=0;i<n-1;++i)
			{
				if(i1!=-1)
				{
					break;
				}
				for(int j=i+1;j<n;++j)
				{
					if(adjMat[i][j]==adjMat[j][i])
					{
						i1=i;
						i2=j;
						break;
					}
				}
			}
			if(i1!=-1)
			{
				cout<<"YES\n";
				print(i1,i2,m);
				cout<<'\n';
			}
			else
			{
				pair<int,pair<int,int>> p=get(adjMat,'a');
				if(p.first==-1)
				{
					p=get(adjMat,'b');
				}
				if(p.first==-1)
				{
					cout<<"NO\n";
				}
				else
				{
					cout<<"YES\n";
					int x=(m>>1);
					if(x&1)
					{
						print(p.first,p.second.first,x);
					}
					else
					{
						print(p.second.first,p.first,x);
					}
					print(p.second.second,p.second.first,x-1);
					cout<<'\n';
				}
			}
		}
	}
	return 0;
}
