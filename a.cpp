#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline char get(char ch)
{
	return ((ch=='1')?'0':'1');
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
		int n,ptr=0,pvs=0;
		string s,t;
		deque<int> a;
		cin>>n>>s>>t;
		for(int i=n-1;i>=0;--i)
		{
			if(ptr==0)		// difference
			{
				if(s[i+pvs]!=t[i])
				{
					if(t[i]!=s[pvs])
					{
						a.push_back(i);
					}
					else
					{
						a.push_back(0);
						a.push_back(i);
					}
					pvs+=i;
					ptr=1-ptr;
				}
			}
			else	// sum
			{
				if(get(s[pvs-i])!=t[i])
				{
					if(get(s[pvs])!=t[i])
					{
						a.push_back(i);
					}
					else
					{
						a.push_back(0);
						a.push_back(i);
					}
					pvs-=i;
					ptr=1-ptr;
				}
			}
		}
		cout<<(int)a.size()<<' ';
		for(auto &v:a)
		{
			cout<<v+1<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
