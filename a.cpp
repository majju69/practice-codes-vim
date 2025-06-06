#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
	if(a.first.second==b.first.second)
	{
		return a.first.first<b.first.first;
	}
	return a.first.second<b.first.second;
}

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
		set<int> st;
		cin>>n;
		vector<pair<pair<int,int>,int>> a(n);
		vector<pair<int,int>> orignal;
		vector<int> l(n,-1),r(n,1e9+10);
		for(int i=0;i<n;++i)
		{
			cin>>a[i].first.first>>a[i].first.second;
			a[i].second=i;
			orignal.push_back(a[i].first);
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n;++i)
		{
			int left=1e9+10,right=1e9+10;
			if(i+1<n&&a[i+1].first.first==a[i].first.first)
			{
				right=a[i+1].first.second;
			}
			if((int)st.size()>0)
			{
				auto it=st.lower_bound(a[i].first.second);
				if(it!=st.end())
				{
					left=*it;
				}
			}
			r[a[i].second]=min(left,right);
			st.insert(a[i].first.second);
		}
		st.clear();
		sort(a.begin(),a.end(),cmp);
		for(int i=n-1;i>=0;--i)
		{
			int left=-1,right=-1;
			if(i-1>=0&&a[i-1].first.second==a[i].first.second)
			{
				left=a[i-1].first.first;
			}
			if((int)st.size()>0)
			{
				auto it=st.begin();
				if(*it<=a[i].first.first)
				{
					auto it1=--st.upper_bound(a[i].first.first);
					right=*it1;
					assert(right<=a[i].first.first);
				}
			}
			l[a[i].second]=max(left,right);
			st.insert(a[i].first.first);
		}
		for(int i=0;i<n;++i)
		{
			if(l[i]>=1&&r[i]<=1e9)
			{
				cout<<r[i]-l[i]-orignal[i].second+orignal[i].first<<'\n';
			}
			else
			{
				cout<<0<<'\n';
			}
		}
	}
	return 0;
}
