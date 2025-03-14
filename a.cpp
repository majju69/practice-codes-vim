#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int kadane(vector<int> &a)
{
	int n=a.size(),mx=0;
	if(n==0)
	{
		return 0;
	}
	vector<int> dp(n,0);
	dp[0]=a[0];
	for(int i=1;i<n;++i)
	{
		dp[i]=max(dp[i-1]+a[i],a[i]);
	}
	for(int i=0;i<n;++i)
	{
		if(dp[i]>mx)
		{
			mx=dp[i];
		}
	}
	return mx;
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
		int n,num=-1,sum=0,s=0,l=0,r=-1;
		map<int,vector<int>> mp,mp_pre;
		cin>>n;
		vector<int> a(n),pre;
		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			mp[x].push_back(i);
			a[i]=x;
		}
		for(auto &v:mp)
		{
			int cur=1,cur_sum=-1;
			vector<int> tmp;
			for(int i=1;i<v.second.size();++i)
			{
				if(v.second[i]==v.second[i-1]+1)
				{
					cur++;
				}
				else
				{
					tmp.push_back(cur);
					tmp.push_back(v.second[i-1]-v.second[i]+1);
					cur=1;
				}
			}
			tmp.push_back(cur);
			cur_sum=kadane(tmp);
			if(cur_sum>sum)
			{
				sum=cur_sum;
				num=v.first;
			}
		}
		cout<<num<<' ';
		for(auto &v:a)
		{
			s+=(v==num);
			s-=(v!=num);
			pre.push_back(s);
		}
		for(int i=0;i<n;++i)
		{
			mp_pre[pre[i]].push_back(i);
		}
		for(int i=0;i<n;++i)
		{
			// a[i]+...+a[j]=sum => pre[j]-pre[i-1]=sum => pre[j]=sum+pre[i-1]
			int req=sum+((i==0)?0:pre[i-1]);
			if(mp_pre.count(req))
			{
				auto &vec=mp_pre[req];
				int idx=lower_bound(vec.begin(),vec.end(),i)-vec.begin();
				if(idx<(int)vec.size())
				{
					l=i+1;
					r=vec[idx]+1;
					break;
				}
			}
		}
		cout<<l<<' '<<r<<'\n';
	}
	return 0;
}
