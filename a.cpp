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
	int n,m;
	map<int,int> mp;
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		int x,sum=0,cnt=1;
		cin>>x;
		sum+=x;
		for(auto &v:mp)
		{
			if(sum+v.first*v.second<=m)
			{
				sum+=v.first*v.second;
				cnt+=v.second;
			}
			else
			{
				// sum+x*v.first<=m
				// x<=(m-sum)/v.first
				cnt+=(m-sum)/v.first;
				break;
			}
		}
		cout<<i+1-cnt<<' ';
		mp[x]++;
	}
	return 0;
}
