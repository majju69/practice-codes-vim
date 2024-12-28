#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

void pre(vector<int> &a)
{
	int n=a.size();
	for(int i=1;i<n;++i)
	{
		a[i]+=a[i-1];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k,mn=2e9+10;
	vector<int> common,alice,bob;
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		int t,a,b;
		cin>>t>>a>>b;
		if(a==1&&b==1)
		{
			common.push_back(t);
		}
		if(a==1&&b==0)
		{
			alice.push_back(t);
		}
		if(a==0&&b==1)
		{
			bob.push_back(t);
		}
	}
	sort(common.begin(),common.end());
	sort(alice.begin(),alice.end());
	sort(bob.begin(),bob.end());
	pre(common);
	pre(alice);
	pre(bob);
	for(int i=0;i<=(int)common.size();++i)
	{
		if(i>k)
		{
			break;
		}
		int c_sum=((i==0)?0:common[i-1]),a_sum=((k-i<=(int)alice.size())?((k==i)?0:alice[k-i-1]):-1),b_sum=((k-i<=(int)bob.size())?((k==i)?0:bob[k-i-1]):-1);
		if(a_sum!=-1&&b_sum!=-1)
		{
			mn=min(mn,c_sum+a_sum+b_sum);
		}
	}
	if(mn>(int)2e9)
	{
		mn=-1;
	}
	cout<<mn<<'\n';
	return 0;
}
