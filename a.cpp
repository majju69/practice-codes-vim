#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

inline void shift(deque<ll> &a)
{
	a.push_back(a[0]);
	a.pop_front();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,a,b,cnt[]={0,0};
	cin>>n>>a>>b;
	for(ll i=0;i<=n;++i)
	{
		if(i*a>n)
		{
			break;
		}
		if((n-a*i)%b==0)
		{
			cnt[0]=i;
			cnt[1]=(n-a*i)/b;
		}
	}
	if(cnt[0]==0&&cnt[1]==0)
	{
		cout<<-1<<'\n';
	}
	else
	{
		deque<ll> arr(n);
		iota(arr.begin(),arr.end(),1);
		while(cnt[0]--)
		{
			deque<ll> tmp;
			for(ll i=0;i<a;++i)
			{
				tmp.push_back(arr[0]);
				arr.pop_front();
			}
			shift(tmp);
			for(auto &v:tmp)
			{
				cout<<v<<' ';
			}
		}
		while(cnt[1]--)
		{
			deque<ll> tmp;
			for(ll i=0;i<b;++i)
			{
				tmp.push_back(arr[0]);
				arr.pop_front();
			}
			shift(tmp);
			for(auto &v:tmp)
			{
				cout<<v<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}
