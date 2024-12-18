#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

vector<long long> spf(1000001,0);

void smallestPrimeFactor()
{
    long long n=spf.size();
    for(long long i=1;i<n;++i)
    {
        spf[i]=i;
    }
    for(long long i=4;i<n;i+=2)
    {
        spf[i]=2;
    }
    for(long long i=3;i*i<n;++i)
    {
        if(spf[i]==i)
        {
            for(long long j=i*i;j<n;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	smallestPrimeFactor();
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,q;
		map<ll,ll> mp_n,mp_x;
		cin>>n>>q;
		while(n>1)
		{
			mp_n[spf[n]]++;
			n/=spf[n];
		}
		while(q--)
		{
			ll k;
			cin>>k;
			if(k==1)
			{
				ll x;
				bool ok=1;
				cin>>x;
				while(x>1)
				{
					mp_x[spf[x]]++;
					x/=spf[x];
				}
				map<ll,ll> mp_cur=mp_n,mp_prod;
				for(auto &v:mp_x)
				{
					mp_cur[v.first]+=v.second;
				}
				for(auto &v:mp_cur)
				{
					ll num=v.second+1;
					while(num>1)
					{
						mp_prod[spf[num]]++;
						num/=spf[num];
					}
				}
				for(auto &v:mp_prod)
				{
					if(mp_cur.find(v.first)==mp_cur.end()||mp_cur[v.first]<v.second)
					{
						ok=0;
						break;
					}
				}
				cout<<(ok?"YES":"NO")<<'\n';
			}
			else
			{
				mp_x.clear();
			}
		}
	}
	return 0;
}
