#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int solve(deque<char> &a)
{
	int n=a.size();
	int lo=1,hi=n,ans=n;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2,l=0,r=n-1;
		vector<int> freq(26,0);
		bool ok=1;
		for(int i=0;i<mid;++i)
		{
			freq[a[i]-'a']++;
		}
		while(l<=r)
		{
			if(r==mid)
			{
				break;
			}
			if(l<mid)
			{
				if(freq[a[r]-'a']>0)
				{
					freq[a[r]-'a']--;
					l++;
					r--;
				}
				else
				{
					ok=0;
					break;
				}
			}
			else
			{
				if(a[l++]!=a[r--])
				{
					ok=0;
					break;
				}
			}
		}
		if(ok)
		{
			ans=mid;
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
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
		int ans=1e9;
		deque<char> a;
		string s;
		cin>>s;
		for(auto &v:s)
		{
			a.push_back(v);
		}
		while((int)a.size()&&a[0]==a.back())
		{
			a.pop_back();
			a.pop_front();
		}
		ans=solve(a);
		reverse(a.begin(),a.end());
		ans=min(ans,solve(a));
		cout<<ans<<'\n';
	}
	return 0;
}
