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
		int n,tmp;
		cin>>n;
		cout<<"mul "<<9<<endl;
		cin>>tmp;
		cout<<"digit"<<endl;
		cin>>tmp;
		cout<<"digit"<<endl;
		cin>>tmp;
		if(n!=9)
		{
			cout<<"add "<<n-9<<endl;
			cin>>tmp;
		}
		cout<<"!"<<endl;
		cin>>tmp;
	}
	return 0;
}
