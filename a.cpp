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
	return (a%mod+b%mod)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,cnt3[4]={0},cnt2[4]={0},cnt1[2]={0},ans=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		x&=1;
		if(x==0)
		{
			cnt3[2]=add(cnt3[2],cnt3[3]);
			cnt3[2]=add(cnt3[2],cnt2[3]);
			cnt3[0]=add(cnt3[0],cnt3[0]);
			cnt3[0]=add(cnt3[0],cnt2[0]);
			cnt2[0]=add(cnt2[0],cnt1[0]);
			cnt2[2]=add(cnt2[2],cnt1[1]);
			cnt1[0]++;
		}
		else
		{
			cnt3[3]=add(cnt3[3],cnt3[1]);
			cnt3[3]=add(cnt3[3],cnt2[1]);
			cnt3[1]=add(cnt3[1],cnt3[2]);
			cnt3[1]=add(cnt3[1],cnt2[2]);
			cnt2[1]=add(cnt2[1],cnt1[0]);
			cnt2[3]=add(cnt2[3],cnt1[1]);
			cnt1[1]++;
		}
	}
	for(int i=0;i<4;++i)
	{
		ans=add(ans,cnt3[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
