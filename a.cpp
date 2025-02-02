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
		int n,ans=0,cur_num=0;
		vector<int> candy;
		cin>>n;
		vector<vector<int>> a(n,vector<int>(n,0));
		for(auto &vec:a)
		{
			for(auto &v:vec)
			{
				cin>>v;
			}
			reverse(vec.begin(),vec.end());
		}
		for(int i=0;i<n;++i)
		{
			int cur=n;
			for(int j=0;j<n;++j)
			{
				if(a[i][j]!=1)
				{
					cur=j;
					break;
				}
			}
			candy.push_back(cur);
		}
		sort(candy.begin(),candy.end());
		for(auto &v:candy)
		{
			if(v>=cur_num)
			{
				ans++;
				cur_num++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
