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
	if(x==-1)
	{
		exit(1);
	}
	return x;
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
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> candy;
		for(int i=0;i<n-1;i+=2)
		{
			int a1=ask(i,i+1),a2=ask(i+1,i);
			if(a1!=a2)
			{
				candy.push_back(i);
				candy.push_back(i+1);
			}
		}
		if((int)candy.size()==0)
		{
			reply(n-1);
		}
		else
		{
			int idx=-1,ans=-1,a1=-1,a2=-1;
			for(int i=0;i<n;++i)
			{
				if(i!=candy[0]&&i!=candy[1])
				{
					idx=i;
					break;
				}
			}
			a1=ask(idx,candy[0]);
			a2=ask(candy[0],idx);
			ans=((a1==a2)?candy[1]:candy[0]);
			reply(ans);
		}
	}
	return 0;
}
