#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int ask(int y)
{
	cout<<y<<endl;
	int x;
	cin>>x;
	if(x==0)
	{
		exit(0);
	}
	if(x==-2)
	{
		exit(1);
	}
	return x;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m,n,t=0,lo=1,hi=0;
	cin>>m>>n;
	vector<bool> a(n);
	for(int i=0;i<n;++i)
	{
		a[i]=(ask(m)==-1);
	}
	hi=m;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		int q=ask(mid);
		if(!a[t])
		{
			q=-q;
		}
		if(q==-1)
		{
			hi=mid-1;
		}
		else
		{
			lo=mid+1;
		}
		t++;
		t%=n;
	}
	return 0;
}
