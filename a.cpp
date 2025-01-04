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
	int n,g=0;
	cin>>n;
	vector<int> a(n);
	for(auto &v:a)
	{
		cin>>v;
		g=gcd(v,g);
	}
	cout<<"YES\n";
	if(g!=1)
	{
		cout<<0<<'\n';
	}
	else
	{
		int cnt=0,ans=0;
		for(auto &v:a)
		{
			if(v&1)
			{
				cnt++;
			}
			else
			{
				ans+=(cnt>>1);
				if(cnt&1)
				{
					ans+=2;
				}
				cnt=0;
			}
		}
		ans+=(cnt>>1);
		if(cnt&1)
		{
			ans+=2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
