#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll mult[19];

inline bool bit(int a,int i)
{
	return a>>i&1;
}

inline int get(int x)
{
	return (x>5)*((x-5)>>1);
}

ll dp[20][3][7][9][2][2][16];

ll solve(int i,int rem3,int rem7,int rem9,bool put,bool last,int mask,string &s)
{
	if(i>=(int)s.size())
	{
		bool ok=(put&&(rem3!=0||!bit(mask,0))&&(rem7!=0||!bit(mask,1))&&(rem9!=0||!bit(mask,2)));
		return ok;
	}
	if(dp[i][rem3][rem7][rem9][put][last][mask]!=-1)
	{
		return dp[i][rem3][rem7][rem9][put][last][mask];
	}
	ll ans=0;
	int till=(last?(s[i]-'0'):9);
	if(!put)
	{
		ans+=solve(i+1,rem3,rem7,rem9,0,(last&&(till==0)),mask,s);
	}
	for(int j=3;j<=till;j+=2)
	{
		if(i==(int)s.size()-1&&j==5)
		{
			continue;
		}
		ll m=mult[(int)s.size()-1-i];
		int mod3=((j%3)*(m%3))%3,mod7=((j%7)*(m%7))%7,mod9=((j%9)*(m%9))%9;
		ans+=solve(i+1,(rem3+mod3)%3,(rem7+mod7)%7,(rem9+mod9)%9,1,(last&&(j==till)),((j!=5)?(mask|(1<<get(j))):mask),s);
	}
	return dp[i][rem3][rem7][rem9][put][last][mask]=ans;
}

ll countTotal(ll n)
{
	string s=to_string(n);
	memset(dp,-1,sizeof(dp));
	return solve(0,0,0,0,0,1,0,s);
}

inline ll countRange(ll a,ll b)
{
	return countTotal(b)-countTotal(a-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mult[0]=1;
	for(int i=1;i<=18;++i)
	{
		mult[i]=mult[i-1]*10;
	}
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll a,b,k,lo=-1,hi=-1,ans=-1;
		cin>>a>>b>>k;
		lo=a;
		hi=b;
		while(lo<=hi)
		{
			ll mid=lo+(hi-lo)/2;
			if(countRange(a,mid)>=k)
			{
				ans=mid;
				hi=mid-1;
			}
			else
			{
				lo=mid+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}	
