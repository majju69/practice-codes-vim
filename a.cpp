#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

ll solve(vector<ll> &a)
{
	ll n=a.size();
	if(n==0)
	{
		return 0;
	}
	ll mn=*min_element(a.begin(),a.end());
	if(n<=mn)
	{
		return n;
	}
	ll sum=mn;
	vector<ll> tmp;
	for(auto &v:a)
	{
		if(v>mn)
		{
			tmp.push_back(v-mn);
		}
		else
		{
			sum+=solve(tmp);
			if(sum>n)
			{
				break;
			}
			tmp.clear();
		}
	}
	if(sum<n)
	{
		sum+=solve(tmp);
	}
	return min(n,sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(auto &v:a)
	{
		cin>>v;
	}
	cout<<solve(a)<<'\n';
	return 0;
}
