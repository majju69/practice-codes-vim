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
		set<int> win_a,win_b;
		cin>>n;
		vector<int> a(n),b(n);
		vector<pair<int,int>> _a(n),_b(n);
		vector<bool> ans(n,0);
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			_a[i]={a[i],i};
		}
		for(int i=0;i<n;++i)
		{
			cin>>b[i];
			_b[i]={b[i],i};
		}
		sort(_a.begin(),_a.end());
		sort(_b.begin(),_b.end());
		ans[_a[n-1].second]=1;
		ans[_b[n-1].second]=1;
		win_b.insert(b[_a[n-1].second]);
		win_a.insert(a[_b[n-1].second]);
		for(int i=n-2;i>=0;--i)
		{
			bool c1=(*win_a.begin()<_a[i].first),c2=(*win_b.begin()<_b[i].first);
			if(c1)
			{
				ans[_a[i].second]=1;
				win_b.insert(b[_a[i].second]);
			}
			if(c2)
			{
				ans[_b[i].second]=1;
				win_a.insert(a[_b[i].second]);
			}
		}
		for(auto v:ans)
		{
			cout<<v;
		}
		cout<<'\n';
	}
	return 0;
}
