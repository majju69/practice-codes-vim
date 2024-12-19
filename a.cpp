#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

vector<vector<int>> divisors(30001);

void fillDivisors()
{
	int n=divisors.size();
	divisors[0].push_back(0);
	divisors[1].push_back(1);
	for(int i=2;i<n;i++)
	{
		divisors[i].push_back(1);
	}
	for(int i=2;i<n;i++)
	{
		for(int j=i;j<n;j+=i)
		{
			divisors[j].push_back(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fillDivisors();
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a,b,c,ans_a=-1,ans_b=-1,ans_c=-1,ans=1e9;
		cin>>a>>b>>c;
		for(int i=1;i<=30000;++i)
		{
			int cur_c=i,cur1=abs(c-i);
			for(auto &d1:divisors[i])
			{
				int cur_b=d1,cur2=abs(b-d1);
				for(auto d2:divisors[d1])
				{
					int cur_a=d2,cur3=abs(a-d2);
					if(cur1+cur2+cur3<ans)
					{
						ans=cur1+cur2+cur3;
						ans_a=cur_a;
						ans_b=cur_b;
						ans_c=cur_c;
					}
				}
			}
		}
		cout<<ans<<'\n';
		cout<<ans_a<<' '<<ans_b<<' '<<ans_c<<'\n';
	}
	return 0;
}
