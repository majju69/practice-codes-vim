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
	int n;
	vector<int> a(512,512);
	set<int> ans;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		a[x]=min(x,a[x]);
		for(int j=0;j<512;++j)
		{
			int req=(j^x);
			if(a[req]<x)
			{
				a[j]=min(a[j],x);
			}
		}
	}
	for(int i=0;i<512;++i)
	{
		if(a[i]!=512)
		{
			ans.insert(i);
		}
	}
	ans.insert(0);
	cout<<(int)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
