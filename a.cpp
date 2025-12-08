#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int ask(int a,int b)
{
	cout<<"? "<<a<<' '<<b<<endl;
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
	cout<<"! "<<x<<endl;
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
		int lo=2,hi=999;
		while(1)
		{
			if(lo==hi)
			{
				reply(lo);
				break;
			}
			int mid1=lo+(hi-lo)/3;
			int mid2=lo+2*(hi-lo)/3;
			int cur=ask(mid1,mid2);
			if(cur==mid1*mid2)
			{
				lo=mid2+1;
			}
			else if(cur==mid1*(mid2+1))
			{
				lo=mid1+1;
				hi=mid2;
			}
			else
			{
				hi=mid1;
			}
		}
	}
	return 0;
}
