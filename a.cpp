#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

const ll mod=1e9+7;

inline ll add(ll a,ll b)
{
	return ((a%mod)+(b%mod))%mod;
}

inline ll mul(ll a,ll b)
{
	return ((a%mod)*(b%mod))%mod;
}

ll gcd(ll a,ll b)
{
	return ((b==0)?a:gcd(b,a%b));
}

inline ll lcm(ll a,ll b)
{
	return (a/gcd(a,b))*b;
}

inline ll get(ll b,ll q,ll y,ll c,ll r,ll z,ll d)
{
	if(c-r<b||c+z*r>b+(y-1)*q)
	{
		return -1;
	}
	ll cn=c+(z-1)*r;
	// c-d*x>c-r  =>  x<r/d 
	// cn+d*x<cn+r  =>  x<r/d
	ll a1=c-d*(r/d-1),a2=cn+d*(r/d-1);	
	return mul((c-a1+d)/d,(a2-cn+d)/d);
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
		ll b,q,y,c,r,z;
		cin>>b>>q>>y>>c>>r>>z;
		if(r%q||c<b||c+(z-1)*r>b+(y-1)*q||(c-b)%q)		// b+(x-1)*q=c
		{
			cout<<0<<'\n';
		}
		else
		{
			ll ans=0;
			for(ll i=1;i*i<=r;++i)
			{
				if(r%i==0)
				{
					ll d1=i,d2=r/i;
					if(lcm(d1,q)==r)
					{
						ll cur=get(b,q,y,c,r,z,d1);
						if(cur<0)
						{
							ans=-1;
							break;
						}
						ans=add(ans,cur);
					}
					if(d2!=d1&&lcm(d2,q)==r)
					{
						ll cur=get(b,q,y,c,r,z,d2);
						if(cur<0)
						{
							ans=-1;
							break;
						}
						ans=add(ans,cur);
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
