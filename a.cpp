#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<int> mx(100001,0);

vector<int> lpf(100001,0);
vector<int> primes;

void leastPrimeFactor()
{
    int n=lpf.size();
    for(int i=2;i<n;++i)
    {
        if(lpf[i]==0)
        {
            lpf[i]=i;
            primes.push_back(i);
        }
        for(int j=0;i*primes[j]<n;++j)
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
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x,cur=0;
		set<int> st;
		cin>>x;
		while(x>1)
		{
			st.insert(lpf[x]);
			x/=lpf[x];
		}
		for(auto &v:st)
		{
			cur=max(cur,mx[v]);
		}
		cur++;
		for(auto &v:st)
		{
			mx[v]=cur;
		}
		ans=max(ans,cur);
	}
	cout<<ans<<'\n';
	return 0;
}
