#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<vector<int>> divisors(200001);

void fillDivisors()
{
	int n=divisors.size();
	for(int i=2;i<n;i++)
	{
		for(int j=i;j<n;j+=i)
		{
			divisors[j].push_back(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillDivisors();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,x,ans=1;
		map<int,int> mp;
		cin>>n>>x;
		vector<int> div=divisors[x];
		for(int i=0;i<n;++i)
		{
			int tmp;
			set<int> st;
			cin>>tmp;
			if(tmp==1||x%tmp)
			{
				continue;
			}
			for(auto &d:div)
			{
				if(d%tmp)
				{
					continue;
				}
				if(mp.count(d/tmp))
				{
					st.insert(d);
				}
			}
			for(auto &v:st)
			{
				mp[v]++;
			}
			mp[tmp]++;
			if(mp.count(x))
			{
				ans++;
				mp.clear();
				mp[tmp]=1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
