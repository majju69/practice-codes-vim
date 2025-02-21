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
		int n,k,q,i=0,j=-1;
		map<int,int> mp;
		multiset<int> st;
		cin>>n>>k>>q;
		vector<int> a(n),ans;
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			a[i]-=i;
		}
		for(int i=0;i<k;++i)
		{
			mp[a[i]]++;
		}
		for(auto &v:mp)
		{
			st.insert(v.second);
		}
		ans.push_back(*st.rbegin());
		j=k;
		while(j<n)
		{
			st.erase(st.find(mp[a[i]]));
			mp[a[i]]--;
			if(mp[a[i]]!=0)
			{
				st.insert(mp[a[i]]);
			}
			else
			{
				mp.erase(a[i]);
			}
			if(mp.count(a[j]))
			{
				st.erase(st.find(mp[a[j]]));
			}
			mp[a[j]]++;
			st.insert(mp[a[j]]);
			ans.push_back(*st.rbegin());
			i++;
			j++;
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<k-ans[l]<<'\n';
		}
	}
	return 0;
}
