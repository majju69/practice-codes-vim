#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int ask(int i,int j,int k)
{
	cout<<"? "<<i+1<<' '<<j+1<<' '<<k+1<<endl;
	int x;
	cin>>x;
	return x-1;
}

inline void reply(int i,int j,int k)
{
	cout<<"! "<<i+1<<' '<<j+1<<' '<<k+1<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,x=0,y=1,z=2;
		cin>>n;
		while(1)
		{
			int new_point=ask(x,y,z);
			if(new_point==-1)
			{
				reply(x,y,z);
				break;
			}
			int new_x=ask(new_point,y,z);
			if(new_x==-1)
			{
				reply(new_point,y,z);
				break;
			}
			int new_y=ask(x,new_point,z);
			if(new_y==-1)
			{
				reply(x,new_point,z);
				break;
			}
			int new_z=ask(x,y,new_point);
			if(new_z==-1)
			{
				reply(x,y,new_point);
				break;
			}
			x=new_x;
			y=new_y;
			z=new_z;
		}
	}
	return 0;
}
