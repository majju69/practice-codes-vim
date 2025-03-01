#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int get(vector<int> &a,vector<int> &pre_b)
{
	int ans=0,i=0,j=(int)a.size()-1;
	while(i<j)
	{
		ans=max(ans,2*(i+1)+pre_b[a[j]-1]-pre_b[a[i]]);
		i++;
		j--;
	}
	return ans;
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
		int n,ans=0;
		vector<vector<int>> idx(26);
		vector<int> freq(26);
		cin>>n;
		vector<vector<int>> pre(26,vector<int>(n,0));
		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			x--;
			idx[x].push_back(i);
			freq[x]++;
			ans=max(ans,freq[x]);
			for(int j=0;j<26;++j)
			{
				pre[j][i]=freq[j];
			}
		}
		for(int i=0;i<25;++i)
		{
			for(int j=i+1;j<26;++j)
			{
				if((int)idx[i].size()&&(int)idx[j].size())
				{
					ans=max(ans,get(idx[i],pre[j]));
					ans=max(ans,get(idx[j],pre[i]));
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
