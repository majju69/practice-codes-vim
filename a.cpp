#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int get(int x,int m)
{
	if(x<0)
	{
		return ((x%m)+m)%m;
	}
	return x%m;
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
		int n;
		bool ok=0;
		map<int,int> mp;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			mp[x]++;
			if(mp[x]>=n/2)
			{
				ok=1;
			}
		}
		if(ok)
		{
			cout<<-1<<'\n';
		}
		else
		{
			int ans=1;
			vector<int> a;
			map<int,vector<pair<int,int>>> mp1;
			for(auto &v:mp)
			{
				a.push_back(v.first);
			}
			for(int i=0;i<(int)a.size()-1;++i)
			{
				for(int j=i+1;j<(int)a.size();++j)
				{
					int x=a[j]-a[i];
					for(int d=1;d*d<=x;++d)
					{
						if(x%d==0)
						{
							mp1[x/d].push_back({i,j});
							if(d*d!=x)
							{
								mp1[d].push_back({i,j});
							}
						}
					}
				}
			}
			for(auto &v:mp1)
			{
				set<int> idx;
				map<int,vector<int>> mod_class;
				for(auto &p:v.second)
				{
					idx.insert(p.first);
					idx.insert(p.second);
				}
				for(auto &i:idx)
				{
					mod_class[get(a[i],v.first)].push_back(a[i]);
				}
				for(auto &c:mod_class)
				{
					int cnt=0;
					for(auto &v1:c.second)
					{
						cnt+=mp[v1];
					}
					if(cnt>=n/2)
					{
						ans=max(ans,v.first);
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
