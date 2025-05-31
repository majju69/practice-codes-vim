#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int ask(int u)
{
	cout<<"? 1 1 "<<u+1<<endl;
	int x;
	cin>>x;
	return x;
}

inline void change(int u)
{
	cout<<"? 2 "<<u+1<<endl;
}

inline void reply(vector<int> &a)
{
	cout<<"! ";
	for(auto &v:a)
	{
		cout<<v<<' ';
	}
	cout<<endl;
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
		int n,s=0;
		cin>>n;
		vector<int> ans(n,0);
		for(int i=1;i<n;++i)
		{
			int x;
			cin>>x>>x;
		}
		s=ask(0);
		if(s==0)
		{
			change(0);
			s=ask(0);
		}
		if(s==-2||s==2)
		{
			int root_s=s/2;
			change(0);
			ans[0]=-root_s;
			for(int i=1;i<n;++i)
			{
				ans[i]=ask(i);
			}
			reply(ans);
			continue;
		}
		if(s==1||s==-1)
		{
			ans[0]=s;
			for(int i=1;i<n;++i)
			{
				ans[i]=ask(i)-s;
			}
			reply(ans);
			continue;
		}
		assert(0);
	}
	return 0;
}
