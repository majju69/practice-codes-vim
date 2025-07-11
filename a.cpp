#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

const int mod=998244353;

inline int mul(int a,int b)
{
	return (1ll*(a%mod)*(b%mod))%mod;
}

inline int add(int a,int b)
{
	return ((a%mod)+(b%mod))%mod;
}

inline int sub(int a,int b)
{
	return ((a%mod)-(b%mod)+mod)%mod;
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
		int n,m,pvs,ans=1;
		cin>>n>>m>>pvs;
		for(int i=1;i<n;++i)
		{
			int x;
			cin>>x;
			if(ans==0)
			{
				continue;
			}
			if(x==pvs)
			{
				ans=mul(ans,m/pvs);
			}
			else if(pvs%x==0)
			{
				int num=pvs/x,total=0;
				vector<int> divisors;
				if(num%2==0)
				{
					divisors.push_back(2);
					while(num%2==0)
					{
						num/=2;
					}
				}
				for(int i=3;i*i<=num;i+=2)
				{
					if(num%i==0)
					{
						divisors.push_back(i);
						while(num%i==0)
						{
							num/=i;
						}
					}
				}
				if(num>2)
				{
					divisors.push_back(num);
				}
				int len=divisors.size();
				for(int mask=1;mask<(1<<len);++mask)
				{
					int cnt=0,cur=x;
					for(int j=0;j<len;++j)
					{
						if(mask>>j&1)
						{
							cnt++;
							cur*=divisors[j];
						}
					}
					if(cnt&1)
					{
						total=add(total,m/cur);
					}
					else
					{
						total=sub(total,m/cur);
					}
				}
				ans=mul(ans,sub(m/x,total));
			}
			else
			{
				ans=0;
			}
			pvs=x;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
