#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<vector<int>> divisors(100001);

void fillDivisors()
{
	int n=divisors.size();
	divisors[0].push_back(0);
	divisors[1].push_back(1);
	for(int i=2;i<n;i++)
	{
		divisors[i].push_back(1);
	}
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
	int n;
	map<int,vector<int>> mp;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x,y,ans=0;
		cin>>x>>y;
		for(auto &d:divisors[x])
		{
			if(mp.count(d))
			{
				vector<int> &vec=mp[d];
				if(i-y<=i-1)
				{
					int cnt=upper_bound(vec.begin(),vec.end(),i-1)-lower_bound(vec.begin(),vec.end(),i-y);
					if(cnt==0)
					{
						ans++;
					}
				}
				else
				{
					ans++;
				}
			}
			else
			{
				ans++;
			}
			mp[d].push_back(i);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
