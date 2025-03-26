#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll get(deque<ll> &a)
{
	ll total_cnt=a.size(),cur_cnt=0,total_sum=0,cur_sum=0,lb=a[0],ub=a.back(),ans=1e18;
	for(auto &v:a)
	{
		total_sum+=v;
	}
	for(ll i=lb;i<=ub;++i)
	{
		if(i==a[0])
		{
			cur_cnt++;
			cur_sum+=i;
			a.pop_front();
		}
		ll left_cnt=cur_cnt,left_sum=cur_sum,right_cnt=total_cnt-left_cnt,right_sum=total_sum-cur_sum;
		ll left=left_cnt*i-left_sum,right=right_sum-i*right_cnt;
		ans=min(ans,left+right);
	}
	return ans;
}

ll get(deque<ll> a,ll d)
{
	if(d==1)
	{
		return 1e18;
	}
	ll ans=0;
	while((ll)a.size())
	{
		deque<ll> tmp;
		for(ll i=0;i<d;++i)
		{
			tmp.push_back(a[0]);
			a.pop_front();
		}
		ans+=get(tmp);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,sum=0;
	deque<ll> a;
	cin>>n;
	for(ll i=0;i<n;++i)
	{
		ll x;
		cin>>x;
		sum+=x;
		if(x==1)
		{
			a.push_back(i);
		}
	}
	if(sum==1)
	{
		cout<<-1<<'\n';
	}
	else
	{
		ll ans=1e18;
		for(ll i=1;i*i<=sum;++i)
		{
			if(sum%i==0)
			{
				ans=min(ans,get(a,i));
				ans=min(ans,get(a,sum/i));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
