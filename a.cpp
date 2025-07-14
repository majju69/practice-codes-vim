#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int mod=998244353;

inline int add(int a,int b)
{
	return ((a%mod)+(b%mod))%mod;
}

inline int mul(int a,int b)
{
	return (1ll*(a%mod)*(b%mod))%mod;
}

vector<int> fact(1001);

void fillFact()
{
	int n=fact.size();
	fact[0]=1;
	for(int i=1;i<n;++i)
	{
		fact[i]=(1ll*(i%mod)*(fact[i-1]%mod))%mod;
	}
}

int power(int a,int b)        // Use when mod is of order 10^9 or less
{
	int ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1)
		{
			ans=(1ll*(ans%mod)*(a%mod))%mod;
		}
		a=(1ll*(a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans%mod;
}

int nCr(int n,int r)         // Ensure that fillFact() is called before this function is used
{
	if(n<r||n<0||r<0)
	{
		return 0;
	}
	if(r==n||r==0)
	{
		return 1;
	}
	int ans=fact[n];
	ans=(1ll*ans*power(fact[r],mod-2))%mod;
	ans=(1ll*ans*power(fact[n-r],mod-2))%mod;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillFact();
	int n,ans=0;
	cin>>n;
	int *a=new int[n],*dp=new int[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		dp[i]=0;
	}
	for(int i=n-1;i>=0;--i)
	{
		if(a[i]>0&&i+a[i]<n)
		{
			for(int j=i+a[i]+1;j<n;++j)
			{
				// i+1.....j-1 choose a[i]-1
				dp[i]=add(dp[i],mul(nCr(j-i-1,a[i]),dp[j]));
			}
			dp[i]=add(dp[i],nCr(n-i-1,a[i]));
		}
		ans=add(ans,dp[i]);
	}
	cout<<ans<<'\n';
	delete []a;
	delete []dp;
	return 0;
}
