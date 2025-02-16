#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll a,b,c,d,x=-1,y=-1;
		vector<ll> div_a,div_b;
		cin>>a>>b>>c>>d;
		for(ll i=1;i*i<=a;++i)
		{
			if(a%i==0)
			{
				div_a.push_back(a/i);
				if(i*i!=a)
				{
					div_a.push_back(i);
				}
			}
		}
		for(ll i=1;i*i<=b;++i)
		{
			if(b%i==0)
			{
				div_b.push_back(b/i);
				if(i*i!=b)
				{
					div_b.push_back(i);
				}
			}
		}
		for(auto &d_a:div_a)
		{
			if(x!=-1)
			{
				break;
			}
			for(auto &d_b:div_b)
			{
				ll tmp_x=d_a*d_b;
				ll tmp_y=(a*b)/tmp_x;
				if((c/tmp_x)*tmp_x>a&&(d/tmp_y)*tmp_y>b)
				{
					x=(c/tmp_x)*tmp_x;
					y=(d/tmp_y)*tmp_y;
					break;
				}
				tmp_y=d_a*d_b;
				tmp_x=(a*b)/tmp_y;
				if((c/tmp_x)*tmp_x>a&&(d/tmp_y)*tmp_y>b)
				{
					x=(c/tmp_x)*tmp_x;
					y=(d/tmp_y)*tmp_y;
					break;
				}
			}
		}
		cout<<x<<' '<<y<<'\n';
	}
	return 0;
}
