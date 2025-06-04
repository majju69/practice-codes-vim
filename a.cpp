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
	int n=0,mx=0,cnt=0;
	string s;
	vector<int> a={0};
	map<int,vector<int>> mp;
	cin>>s;
	n=s.size();
	for(auto &v:s)
	{
		a.push_back((v=='(')?1:-1);
	}
	for(int i=1;i<=n;++i)
	{
		a[i]+=a[i-1];
	}
	for(int i=0;i<=n;++i)
	{
		mp[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)
	{
		if(s[i-1]=='(')
		{
			if(mp.count(a[i-1]-1))
			{
				vector<int> &vec=mp[a[i-1]-1];
				int idx=upper_bound(vec.begin(),vec.end(),i)-vec.begin();
				if(idx>=(int)vec.size())
				{
					if(mp.count(a[i-1]))
					{
						int len=mp[a[i-1]].back()-i+1;
						if(len>mx)
						{
							mx=len;
							cnt=1;
						}
						else
						{
							if(len==mx)
							{
								cnt++;
							}
						}
					}
				}
				else
				{
					if(mp.count(a[i-1]))
					{
						vector<int> &vec1=mp[a[i-1]];
						int idx1=lower_bound(vec1.begin(),vec1.end(),vec[idx])-vec1.begin()-1;
						if(idx1>=0&&idx1<(int)vec1.size()&&vec1[idx1]>=i)
						{
							int len=vec1[idx1]-i+1;
							if(len>mx)
							{
								mx=len;
								cnt=1;
							}
							else
							{
								if(len==mx)
								{
									cnt++;
								}
							}
						}
					}
				}
			}
			else
			{
				if(mp.count(a[i-1]))
				{
					int len=mp[a[i-1]].back()-i+1;
					if(len>mx)
					{
						mx=len;
						cnt=1;
					}
					else
					{
						if(len==mx)
						{
							cnt++;
						}
					}
				}
			}
		}
	}
	if(mx==0)
	{
		cout<<"0 1\n";
	}
	else
	{
		cout<<mx<<' '<<cnt<<'\n';
	}
	return 0;
}
