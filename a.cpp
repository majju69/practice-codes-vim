#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<string> get(string &s)
{
	int n=s.size();
	vector<string> ans;
	for(int i=0;i<n;++i)
	{
		string cur;
		for(int j=0;j<n;++j)
		{
			if(j!=i)
			{
				cur.push_back(s[j]);
			}
		}
		ans.push_back(cur);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,ans=0,cnt=0;
	string s;
	queue<pair<string,int>> q;
	map<string,bool> vis;
	cin>>n>>k>>s;
	q.push({s,0});
	vis[s]=1;
	while(q.size())
	{
		string cur=q.front().first;
		int cost=q.front().second;
		q.pop();
		cnt++;
		ans+=cost;
		if(cnt>=k)
		{
			break;
		}
		vector<string> nbrs=get(cur);
		for(auto &v:nbrs)
		{
			if(!vis[v])
			{
				q.push({v,cost+1});
				vis[v]=1;
			}
		}
	}
	if(cnt<k)
	{
		ans=-1;
	}
	cout<<ans<<'\n';
	return 0;
}
