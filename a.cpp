#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef unsigned long long ll;

inline ll bit(ll a,ll i)
{
	return a>>i&1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll sum,_xor;
	cin>>sum>>_xor;
	if(sum<_xor||(sum-_xor)%2!=0)
	{
		cout<<-1<<'\n';
	}
	else
	{
		ll _and=(sum-_xor)/2,x=0,y=0;
		for(ll i=0;i<64;++i)
		{
			if(bit(_and,i))
			{
				if(bit(_xor,i))
				{
					x=-1;
					y=-1;
					break;
				}
				else
				{
					x+=(1LL<<i);
					y+=(1LL<<i);
				}
			}
			else
			{
				if(bit(_xor,i))
				{
					y+=(1LL<<i);
				}
			}
		}
		if(x==-1)
		{
			cout<<-1<<'\n';
		}
		else
		{
			cout<<x<<' '<<y<<'\n';
		}
	}
	return 0;
}

/*

a=x+y
b=x^y

x+y=x^y+2(x&y)

a=b+2(x&y)

(a-b)/2=x&y
b=x^y

*/
