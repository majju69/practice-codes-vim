#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int gcd(int a,int b)
{
	return ((b==0)?a:gcd(b,a%b));
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
		int a,g=-1,cur=-1,mul=1;
		cin>>a;
		g=gcd(a,180);
		cur=a/g;
		for(int i=1;i<=180;++i)
		{
			if(2*a<=cur*i*(180-a))
			{
				mul=i;
				break;
			}
		}
		cout<<(180*mul)/g<<'\n';
	}
	return 0;
}

