#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

bool check(int x,int p,vector<int> &a)
{
	int n=a.size(),cur=0;
	// x+i >= a[i]
	for(int i=0;i<n;++i)
	{
		int cnt=upper_bound(a.begin(),a.end(),x+i)-a.begin()-cur++;
		if(cnt%p==0)
		{
			return 0;
		}
	}
	return 1; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,p,mn=1e9,mx=-1e9;
	cin>>n>>p;
	vector<int> a(n),ans;
	for(auto &v:a)
	{
		cin>>v;
	}
	sort(a.begin(),a.end());
	mn=a[0];
	mx=a[n-1];
	for(int x=mn;x<mx;++x)
	{
		if(check(x,p,a))
		{
			ans.push_back(x);
		}
	}
	cout<<(int)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
