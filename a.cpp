#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

bool cmp(string &s1,string &s2)
{
	string f=s1+s2,s=s2+s1;
	return f<s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<string> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	sort(a.begin(),a.end(),cmp);
	for(auto &v:a)
	{
		cout<<v;
	}
	cout<<'\n';
	return 0;
}
