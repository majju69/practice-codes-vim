#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline void print(set<int> &st)
{
	if((int)st.size()==0)
	{
		cout<<"Nothing\n";
	}
	else
	{
		auto it=st.rbegin();
		cout<<*it<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,idx=-1;
	map<int,int> mp;
	set<int> st;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	for(int i=0;i<k;++i)
	{
		mp[a[i]]++;
		if(mp[a[i]]==1)
		{
			st.insert(a[i]);
		}
		else
		{
			st.erase(a[i]);
		}
	}
	print(st);
	idx=k;
	while(idx<n)
	{
		mp[a[idx]]++;
		if(mp[a[idx]]==1)
		{
			st.insert(a[idx]);
		}
		else
		{
			st.erase(a[idx]);
		}
		mp[a[idx-k]]--;
		if(mp[a[idx-k]]==1)
		{
			st.insert(a[idx-k]);
		}
		else
		{
			st.erase(a[idx-k]);
		}
		print(st);
		idx++;
	}
	return 0;
}
