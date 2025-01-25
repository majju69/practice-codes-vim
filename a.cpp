#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		deque<char> odd,even;
		cin>>s;
		for(auto &v:s)
		{
			if((v-'0')&1)
			{
				odd.push_back(v);
			}
			else
			{
				even.push_back(v);
			}
		}
		while((int)odd.size()&&(int)even.size())
		{
			if(odd[0]<even[0])
			{
				cout<<odd[0];
				odd.pop_front();
			}
			else
			{
				cout<<even[0];
				even.pop_front();
			}
		}
		while((int)odd.size())
		{
			cout<<odd[0];
			odd.pop_front();
		}
		while((int)even.size())
		{
			cout<<even[0];
			even.pop_front();
		}
		cout<<'\n';
	}
	return 0;
}
