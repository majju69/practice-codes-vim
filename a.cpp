#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<int> ask(int k)
{
	cout<<"? "<<k<<endl;
	int n;
	vector<int> ans;
	cin>>n;
	if(n==-1)
	{
		exit(1);
	}
	while(n--)
	{
		int x;
		cin>>x;
		if(x==-1)
		{
			exit(1);
		}
		x--;
		ans.push_back(x);
	}
	return ans;
}

void reply(int n,int m,vector<int> adj[])
{
	cout<<"! "<<m<<endl;
	for(int i=0;i<n;++i)
	{
		for(auto &v:adj[i])
		{
			cout<<i+1<<' '<<v+1<<endl;
		}
	}
}

void solve(int node,int l,int r,vector<int> adj[],int &m)
{
	if(l!=r)
	{
		int nbr=-1;
		vector<int> path=ask(l+1);
		adj[node].push_back(path[1]);
		m++;
		nbr=path[1];
		int lo=l+2,hi=r;
		while(1)
		{
			if(lo>r)
			{
				break;
			}
			int ans=-1,cur=-1;
			while(lo<=hi)
			{
				int mid=lo+((hi-lo)>>1);
				path=ask(mid);
				if(path[1]!=nbr)
				{
					cur=path[1];
					ans=mid;
					hi=mid-1;
				}
				else
				{
					lo=mid+1;
				}
			}
			if(ans==-1||cur==-1)
			{
				break;
			}
			adj[node].push_back(cur);
			m++;
			nbr=cur;
			lo=ans+1;
			hi=r;
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
		int n,m=0,pvs=0;
		cin>>n;
		vector<int> cnt(n),adj[n];
		for(int i=0;i<n;++i)
		{
			int lo=pvs+1,hi=(1<<30),ans=-1;
			while(lo<=hi)
			{
				int mid=lo+((hi-lo)>>1);
				vector<int> path=ask(mid);
				if((int)path.size()==0||path[0]!=i)
				{
					hi=mid-1;
				}
				else
				{
					ans=mid;
					lo=mid+1;
				}
			}
			cnt[i]=ans-pvs;
			pvs+=cnt[i];
		}
		pvs=0;
		for(int i=0;i<n;++i)
		{
			solve(i,pvs+1,pvs+cnt[i],adj,m);
			pvs+=cnt[i];
		}
		reply(n,m,adj);
	}
	return 0;
}
