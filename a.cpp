#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;

vector<long long> lpf(100001,0);
vector<long long> primes;

void leastPrimeFactor()
{
    long long n=lpf.size();
    for(long long i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
        }
        for(long long j=0;i*primes[j]<n;++j)
        {
            lpf[i*primes[j]]=primes[j];
            if(primes[j]==lpf[i])
            {
                break;
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	leastPrimeFactor();
	ll tc;
	cin>>tc;
	while(tc--)
	{
		ll n,m;
		bool ok=1;
		cin>>n>>m;
		vector<ll> a(m),ans;
		for(auto &v:a)
		{
			cin>>v;
		}
		sort(a.rbegin(),a.rend());
		for(ll i=1;i<=n;++i)
		{
			ll cnt=0,x=i;
			while(x>1)
			{
				x/=lpf[x];
				cnt++;
			}
			if(cnt>=m)
			{
				ok=0;
				break;
			}
			ans.push_back(a[cnt]);
		}
		if(ok)
		{
			for(auto &v:ans)
			{
				cout<<v<<' ';
			}
			cout<<'\n';
		}
		else
		{
			cout<<-1<<'\n';
		}
	}
	return 0;
}
