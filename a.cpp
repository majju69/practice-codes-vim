#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int mod=1e9+7;

inline int mul(int a,long long b)
{
	return (1ll*(a%mod)*(b%mod))%mod;
}

inline int add(int a,int b)
{
	return ((a%mod)+(b%mod))%mod;
}

inline bool bit(long long a,int i)
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
		int n,freq[60],ans=0;
		memset(freq,0,sizeof(freq));
		cin>>n;
		long long *a=new long long[n];
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			for(int j=0;j<60;++j)
			{
				if(bit(a[i],j))
				{
					freq[j]++;
				}
			}
		}
		for(int i=0;i<n;++i)
		{
			int _or=0,_and=0;
			for(int j=0;j<60;++j)
			{
				if(bit(a[i],j))
				{
					_and=add(_and,mul(freq[j],(1LL<<j)));
					_or=add(_or,mul(n,(1LL<<j)));
				}
				else
				{
					_or=add(_or,mul(freq[j],(1LL<<j)));
				}
			}
			ans=add(ans,mul(_or,_and));
		}
		cout<<ans<<'\n';
		delete []a;
	}
	return 0;
}
