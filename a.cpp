#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

pair<int,int> getRange(int l,int r,vector<int> &a)
{
	int mn=0,mx=0,mxEnd=0,mnEnd=0;
	for(int i=l;i<=r;++i)
	{
		mxEnd=max(mxEnd+a[i],a[i]);
		mnEnd=min(mnEnd+a[i],a[i]);
		mn=min(mn,mnEnd);
		mx=max(mx,mxEnd);
	}
	return {mn,mx};
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
		int n,idx=-1;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			if(abs(a[i])!=1)
			{
				idx=i;
			}
		}
		if(idx==-1)
		{
			pair<int,int> range=getRange(0,n-1,a);
			cout<<range.second-range.first+1<<'\n';
			for(int i=range.first;i<=range.second;++i)
			{
				cout<<i<<' ';
			}
			cout<<'\n';
		}
		else
		{
			int s=0,x=a[idx];
			pair<int,int> l_exc_range=getRange(0,idx-1,a),r_exc_range=getRange(idx+1,n-1,a);
			pair<int,int> exc_range={min(l_exc_range.first,r_exc_range.first),max(l_exc_range.second,r_exc_range.second)};
			pair<int,int> l_inc_range={0,0},r_inc_range={0,0};
			pair<int,int> inc_range={2e9,-2e9};
			for(int i=idx-1;i>=0;--i)
			{
				s+=a[i];
				l_inc_range.first=min(l_inc_range.first,s);
				l_inc_range.second=max(l_inc_range.second,s);
			}
			s=0;
			for(int i=idx+1;i<n;++i)
			{
				s+=a[i];
				r_inc_range.first=min(r_inc_range.first,s);
				r_inc_range.second=max(r_inc_range.second,s);
			}
			inc_range={min({x+l_inc_range.first,x+r_inc_range.first,x+l_inc_range.first+r_inc_range.first}),max({x+l_inc_range.second,x+r_inc_range.second,x+l_inc_range.second+r_inc_range.second})};
			if(inc_range.first>exc_range.second||exc_range.first>inc_range.second)
			{
				if(inc_range>exc_range)
				{
					swap(inc_range,exc_range);
				}
				cout<<inc_range.second+exc_range.second-inc_range.first-exc_range.first+2<<'\n';
				for(int i=inc_range.first;i<=inc_range.second;++i)
				{
					cout<<i<<' ';
				}
				for(int i=exc_range.first;i<=exc_range.second;++i)
				{
					cout<<i<<' ';
				}
				cout<<'\n';
			}
			else
			{
				pair<int,int> range={min(inc_range.first,exc_range.first),max(inc_range.second,exc_range.second)};
				cout<<range.second-range.first+1<<'\n';
				for(int i=range.first;i<=range.second;++i)
				{
					cout<<i<<' ';
				}
				cout<<'\n';
			}
		}
	}
	return 0;
}
