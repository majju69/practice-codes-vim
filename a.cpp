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
	long long p;
	int k;
	bool sub=1;
	vector<int> ans;
	cin>>p>>k;
	while(p>0)
	{
		if(sub)
		{
			int x=p%k;
			ans.push_back(x);
			p-=x;
			p/=k;
		}
		else
		{
			int x=(k-p%k)%k;
			ans.push_back(x);
			p+=x;
			p/=k;
		}
		sub=!sub;
	}
	cout<<(int)ans.size()<<'\n';
	for(auto &v:ans)
	{
		cout<<v<<' ';
	}
	cout<<'\n';
	return 0;
}
