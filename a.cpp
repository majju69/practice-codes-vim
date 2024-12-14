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
		int n,zero=0;
		deque<int> pos,neg;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			if(x<0)
			{
				neg.push_back(x);
			}
			else if(x>0)
			{
				pos.push_back(x);
			}
			else
			{
				zero++;
			}
		}
		if(zero==n)
		{
			cout<<"No\n";
		}
		else
		{
			cout<<"Yes\n";
			for(int i=0;i<zero;++i)
			{
				cout<<0<<' ';
			}
			int ptr=0,sum=0;
			while((int)pos.size()>0||(int)neg.size()>0)
			{
				if(ptr==0)
				{
					if((int)pos.size()>0)
					{
						cout<<pos[0]<<' ';
						sum+=pos[0];
						pos.pop_front();
					}
					else
					{
						cout<<neg[0]<<' ';
						sum+=neg[0];
						neg.pop_front();
					}
					if(sum>0)
					{
						ptr=1;
					}
				}
				else
				{
					if((int)neg.size()>0)
					{
						cout<<neg[0]<<' ';
						sum+=neg[0];
						neg.pop_front();
					}
					else
					{
						cout<<pos[0]<<' ';
						sum+=pos[0];
						pos.pop_front();
					}
					if(sum<=0)
					{
						ptr=0;
					}
				}
			}
			cout<<'\n';
		}
	}
	return 0;
}
