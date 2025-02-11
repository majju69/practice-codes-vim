#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int ask(int i,int j)
{
	cout<<"? "<<i+1<<' '<<j+1<<endl;
	int x;
	cin>>x;
	return x;
}

inline void reply(char c)
{
	cout<<"! "<<c<<endl;
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
		int n,absent=-1;
		cin>>n;
		vector<int> a(n);
		vector<bool> present(n,0);
		for(auto &v:a)
		{
			cin>>v;
			v--;
			present[v]=1;
		}
		for(int i=0;i<n;++i)
		{
			if(!present[i])
			{
				absent=i;
				break;
			}
		}
		if(absent!=-1)
		{
			if(ask(absent,(absent+1)%n)==0)
			{
				reply('A');
			}
			else
			{
				reply('B');
			}
		}
		else
		{
			int idx0=-1,idx1=-1,d=-1;
			for(int i=0;i<n;++i)
			{
				if(a[i]==0)
				{
					idx0=i;
				}
				if(a[i]==n-1)
				{
					idx1=i;
				}
			}
			d=ask(idx0,idx1);
			if(d>=n)
			{
				reply('B');
			}
			else if(d<n-1)
			{
				reply('A');
			}
			else
			{
				if(d==ask(idx1,idx0))
				{
					reply('B');
				}
				else
				{
					reply('A');
				}
			}
		}
	}
	return 0;
}
