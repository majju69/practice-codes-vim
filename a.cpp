#include <bits/stdc++.h>
using namespace std;

inline int ask(int l,int r)
{
	cout<<"? "<<l+1<<' '<<r+1<<endl;
	int x;
	cin>>x;
	return x-1;
}

inline void reply(int x)
{
	cout<<"! "<<x+1<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,idx=-1,left=-1;
	map<pair<int,int>,int> mp;
	cin>>n;
	idx=ask(0,n-1);
	mp[{0,n-1}]=idx;
	if(idx!=0)
	{
		left=ask(0,idx);
		mp[{0,idx}]=left;
		if(left!=idx)
		{
			left=-1;
		}
	}
	if(left==-1)
	{
		int lo=idx+1,hi=n-1,ans=-1;
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2;
			int cur=((mp.count({idx,mid}))?mp[{idx,mid}]:ask(idx,mid));
			mp[{idx,mid}]=cur;
			if(cur==idx)
			{
				ans=mid;
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		reply(ans);
	}
	else
	{
		int lo=0,hi=idx-1,ans=-1;
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2;
			int cur=((mp.count({mid,idx}))?mp[{mid,idx}]:ask(mid,idx));
			mp[{mid,idx}]=cur;
			if(cur==idx)
			{
				ans=mid;
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		reply(ans);
	}
	return 0;
}
