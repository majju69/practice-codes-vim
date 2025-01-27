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
		int n,ans=1e9;
		cin>>n;
		vector<pair<int,int>> a(n);
		vector<int> left(n),right(n);
		for(int i=0;i<n;++i)
		{
			cin>>a[i].first>>a[i].second;
			left[i]=a[i].first;
			right[i]=a[i].second;
		}
		sort(left.begin(),left.end());
		sort(right.begin(),right.end());
		for(auto &v:a)
		{
			int left_cnt=upper_bound(right.begin(),right.end(),v.first-1)-lower_bound(right.begin(),right.end(),0),right_cnt=upper_bound(left.begin(),left.end(),1e9+10)-lower_bound(left.begin(),left.end(),v.second+1);
			ans=min(ans,left_cnt+right_cnt);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
