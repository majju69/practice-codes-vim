#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int N1=2e3+10,N2=5e3+10;
int a[N1],suf_freq[N2];

inline long long get(int n)
{
	return 1ll*n*n*n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long cnt=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			suf_freq[abs(a[i]-a[j])]++;
		}
	}
	for(int i=N2-2;i>=0;--i)
	{
		suf_freq[i]+=suf_freq[i+1];
	}
	for(int d1=1;d1<N2;++d1)
	{
		for(int d2=1;d2<N2-d1;++d2)
		{
			if(d1+d2+1>=N2)
			{
				continue;
			}
			int c1=suf_freq[d1]-((d1+1<N2)?suf_freq[d1+1]:0),c2=suf_freq[d2]-((d2+1<N2)?suf_freq[d2+1]:0);
			cnt+=1ll*c1*c2*suf_freq[d1+d2+1];
		}
	}
	cout<<fixed<<setprecision(10)<<(long double)cnt/get(n*(n-1)/2)<<'\n';
	return 0;
}

/*

|d1|+|d2|<|d3|


*/
