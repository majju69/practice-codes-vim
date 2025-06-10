#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int get(vector<int> &left,vector<int> &right)
{
	int n=left.size(),cnt=1,ans=1,i=1,j=0;
	if(n==0)
	{
		return 0;
	}
	sort(left.begin(),left.end());
	sort(right.begin(),right.end());
	while(i<n&&j<n)
	{
		if(left[i]<=right[j])
		{
			cnt++;
			ans=max(ans,cnt);
			i++;
		}
		else
		{
			cnt--;
			j++;
		}
	}
	return ans;
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
		int n,m,mx=0;
		vector<int> left,right;
		cin>>n>>m;
		vector<pair<int,int>> a(n);
		for(auto &v:a)
		{
			cin>>v.first>>v.second;
		}
		for(auto &v:a)
		{
			if(v.first!=1)
			{
				left.push_back(v.first);
				right.push_back(v.second);
			}
		}
		mx=max(mx,get(left,right));
		left.clear();
		right.clear();
		for(auto &v:a)
		{
			if(v.second!=m)
			{
				left.push_back(v.first);
				right.push_back(v.second);
			}
		}
		mx=max(mx,get(left,right));
		cout<<mx<<'\n';
	}
	return 0;
}
