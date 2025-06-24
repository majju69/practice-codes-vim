#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline bool bit(int a,int i)
{
	return a>>i&1;
}

ll dp[20][2][8][9][2][7][512],mult[19];

ll solve(int i,bool last,int mod8,int mod9,bool last50,int mod7,int mask,int k,string &s)
{
	if(i>=(int)s.size())
	{
		int cnt=0;
		if(bit(mask,0))
		{
			cnt++;
		}
		if(mod8%2==0)
		{
			cnt+=bit(mask,1);
		}
		if(mod9%3==0)
		{
			cnt+=bit(mask,2);
		}
		if(mod8%4==0)
		{
			cnt+=bit(mask,3);
		}
		if(last50)
		{
			cnt+=bit(mask,4);
		}
		if(mod8%2==0&&mod9%3==0)
		{
			cnt+=bit(mask,5);
		}
		if(mod7==0)
		{
			cnt+=bit(mask,6);
		}
		if(mod8==0)
		{
			cnt+=bit(mask,7);
		}
		if(mod9==0)
		{
			cnt+=bit(mask,8);
		}
		return (cnt>=k);
	}
	if(dp[i][last][mod8][mod9][last50][mod7][mask]!=-1)
	{
		return dp[i][last][mod8][mod9][last50][mod7][mask];
	}
	int till=(last?(s[i]-'0'):9);
	ll ans=0;
	for(int j=0;j<=till;++j)
	{
		if(j==0)
		{
			bool cur=(i==(int)s.size()-1);
			ans+=solve(i+1,(last&&(j==till)),mod8,mod9,cur,mod7,mask,k,s);
		}
		else
		{
			ans+=solve(i+1,(last&&(j==till)),(mod8+(mult[((int)s.size()-1-i)]%8)*j)%8,(mod9+(mult[((int)s.size()-1-i)]%9)*j)%9,((i==(int)s.size()-1)&&(j==5)),(mod7+(mult[((int)s.size()-1-i)]%7)*j)%7,(mask|(1<<(j-1))),k,s);
		}
	}
	return  dp[i][last][mod8][mod9][last50][mod7][mask]=ans;
}

ll getCount(ll n,int k)
{
	string s=to_string(n);
	memset(dp,-1,sizeof(dp));
	return solve(0,1,0,0,0,0,0,k,s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mult[0]=1;
	for(int i=1;i<=18;++i)
	{
		mult[i]=10*mult[i-1];
	}
	int tc;
	cin>>tc;
	while(tc--)
	{
		ll l,r;
		int k;
		cin>>l>>r>>k;
		cout<<getCount(r,k)-getCount(l-1,k)<<'\n';
	}
	return 0;
}
