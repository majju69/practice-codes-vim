#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int bit(int a,int i)
{
	return a>>i&1;
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
		int n,m,ans=0;
		cin>>n>>m;
		if(n>m)
		{
			cout<<0<<'\n';
			continue;
		}
		if(n==0)
		{
			cout<<m+1<<'\n';
			continue;
		}
		for(int i=30;i>=0;--i)
		{
			int _n=bit(n,i),_m=bit(m,i);
			if(_n==0&&_m==1)
			{
				ans+=(1<<i);
				continue;
			}
			if(_n==1&&_m==1)
			{
				continue;
			}
			if(_n==0&&_m==0)
			{
				bool canSkip=0;
				for(int j=i-1;j>=0;--j)
				{
					if((bit(n,j)==0&&bit(m,j)==0)||(bit(n,j)==1&&bit(m,j)==0))
					{
						canSkip=1;
						break;
					}
				}
				if(canSkip)
				{
					continue;
				}
				else
				{
					ans+=(1<<i);
					break;
				}
			}
			break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
