#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,ans=1;
		map<long long,vector<pair<int,int>>> mp;
		cin>>n;
		vector<int> a(n);
		for(auto &v:a)
		{
			cin>>v;
		}
		for(int i=0;i<n-1;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				int x=a[j]-a[i];
				for(int d=1;d*d<=x;++d)
				{
					if(x%d==0)
					{
						int d1=x/d,d2=d;
						if((d1&1)==(d2&1))
						{
							long long u=(d1+d2)>>1;
							if(u*u-a[j]>=0)
							{
								mp[u*u-a[j]].push_back({i,j});
							}
						}
					}
				}
			}
		}
		for(auto &v:mp)
		{
			set<int> st;
			for(auto &p:v.second)
			{
				st.insert(p.first);
				st.insert(p.second);
			}
			ans=max(ans,(int)st.size());
		}
		cout<<ans<<'\n';
	}
	return 0;
}
