#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

bool check(ll mid,deque<ll> pos,deque<ll> neg)
{
	ll n=(ll)pos.size()+(ll)neg.size();
	vector<ll> dp(n,0);
	dp[0]=pos[0];
	pos.pop_front();
	for(ll i=1;i<n;++i)
	{
		if((ll)pos.size()&&max(pos[0]+dp[i-1],pos[0])<=mid)
		{
			dp[i]=max(dp[i-1]+pos[0],pos[0]);
			pos.pop_front();
		}
		else
		{
			if((ll)neg.size())
			{
				dp[i]=max(dp[i-1]+neg[0],neg[0]);
				neg.pop_front();
			}
			else
			{
				dp[i]=max(dp[i-1]+pos[0],pos[0]);
				pos.pop_front();
			}
		}
	}
	return (*max_element(dp.begin(),dp.end())<=mid);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,lo=-1e18,hi=0;
		deque<ll> pos,neg;
		cin>>n;
		for(ll i=0;i<n;++i)
		{
			ll x;
			cin>>x;
			if(x>=0)
			{
				pos.push_back(x);
				hi+=x;
			}
			else
			{
				neg.push_back(x);
			}
			lo=max(lo,x);
		}
		if(lo<=0)
		{
			cout<<0<<'\n';
		}
		else
		{
			ll ans=-1;
			while(lo<=hi)
			{
				ll mid=lo+(hi-lo)/2;
				if(check(mid,pos,neg))
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
	}
	return 0;
}
