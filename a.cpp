#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int ask(vector<int> &a)
{
	cout<<"? ";
	for(auto &v:a)
	{
		cout<<v<<' ';
	}
	cout<<endl;
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

inline int bit(int a,int i)
{
	return a>>i&1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int small_num=-1,big_num=-1,ans=0;
	vector<int> big,small;
	for(int i=1;i<=100;++i)
	{
		big.push_back(i<<7);
		small.push_back(i);
	}
	small_num=ask(small);
	big_num=ask(big);
	for(int i=0;i<14;++i)
	{
		int b=-1;
		if(i<7)
		{
			b=bit(big_num,i);
		}
		else
		{
			b=bit(small_num,i);
		}
		if(b==1)
		{
			ans+=(1<<i);
		}
	}
	reply(ans);
	return 0;
}
