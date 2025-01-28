#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int ask(int n)
{
	cout<<"- "<<n<<endl;
	int x;
	cin>>x;
	if(x==-1)
	{
		exit(1);
	}
	return x;
}

inline void reply(int x)
{
	cout<<"! "<<x<<endl;
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
		int cnt,real_cnt=-1,i=0,ans=0;
		cin>>cnt;
		real_cnt=cnt;
		while(real_cnt>0&&i<30)
		{
			int pvs=cnt;
			cnt=ask(1<<i);
			if(pvs>cnt)
			{
				ans+=(1<<i);
				i++;
			}
			else
			{
				ans+=(1<<(i+cnt-pvs+1));
				i+=cnt-pvs+2;
			}
			real_cnt--;
		}
		reply(ans);
	}
	return 0;
}


/*

10100

*/
