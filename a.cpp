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
		int n;
		map<int,int> mp_init;
		cin>>n;
		n<<=1;
		vector<int> a(n);
		for(auto &v:a)
		{
			cin>>v;
			mp_init[v]++;
		}
		if(n==1)
		{
			cout<<"NO\n";
		}
		else
		{
			sort(a.begin(),a.end());
			int ans_x=-1;
			vector<pair<int,int>> ans_nums={{-1,-1}};
			for(int i=0;i<n-1;++i)
			{
				map<int,int> mp=mp_init;
				int x1=a[n-1],x2=a[i],x=a[n-1];
				vector<pair<int,int>> nums={{x1,x2}};
				bool ok=1;
				mp[a[i]]--;
				mp[a[n-1]]--;
				for(int j=n-2;j>=0;--j)
				{
					if(mp[a[j]]==0)
					{
						continue;
					}
					mp[a[j]]--;
					if(mp.count(x-a[j])&&mp[x-a[j]]>0)
					{
						x1=a[j];
						x2=x-a[j];
						mp[x2]--;
						x=a[j];
						nums.push_back({x1,x2});
					}
					else
					{
						ok=0;
						break;
					}
				}
				if(ok)
				{
					ans_x=a[n-1]+a[i];
					ans_nums=nums;
					break;
				}
			}
			if(ans_x==-1)
			{
				cout<<"NO\n";
			}
			else
			{
				cout<<"YES\n";
				cout<<ans_x<<'\n';
				for(auto &v:ans_nums)
				{
					cout<<v.first<<' '<<v.second<<'\n';
				}
			}
		}
	}
	return 0;
}
