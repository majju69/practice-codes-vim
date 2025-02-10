#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int ask(int i,int j,char ch)
{
	cout<<((ch=='|')?"or ":"and ")<<i+1<<' '<<j+1<<endl;
	int x;
	cin>>x;
	return x;
}

inline void reply(vector<int> &a,int k)
{
	sort(a.begin(),a.end());
	cout<<"finish "<<a[k]<<endl;
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
	int n,k,and12=-1,or12=-1,and23=-1,or23=-1,and13=-1,or13=-1;
	cin>>n>>k;
	k--;
	vector<int> a(n,0),a0(30,-1),a1(30,-1),a2(30,-1);
	and12=ask(0,1,'&');
	or12=ask(0,1,'|');
	and23=ask(1,2,'&');
	or23=ask(1,2,'|');
	and13=ask(0,2,'&');
	or13=ask(0,2,'|');
	for(int i=0;i<30;++i)
	{
		if(bit(or12,i)==0)
		{
			a0[i]=a1[i]=0;
		}
		if(bit(or23,i)==0)
		{
			a1[i]=a2[i]=0;
		}
		if(bit(or13,i)==0)
		{
			a0[i]=a2[i]=0;
		}
		if(bit(and12,i)==1)
		{
			a0[i]=a1[i]=1;
		}
		if(bit(and23,i)==1)
		{
			a1[i]=a2[i]=1;
		}
		if(bit(and13,i)==1)
		{
			a0[i]=a2[i]=1;
		}
	}
	for(int i=0;i<30;++i)
	{
		if(a0[i]==-1)
		{
			a0[i]=1-a1[i];
		}
		if(a1[i]==-1)
		{
			a1[i]=1-a0[i];
		}
		if(a2[i]==-1)
		{
			a2[i]=1-a0[i];
		}
	}
	for(int i=0;i<30;++i)
	{
		if(a0[i])
		{
			a[0]+=(1<<i);
		}
		if(a1[i])
		{
			a[1]+=(1<<i);
		}
		if(a2[i])
		{
			a[2]+=(1<<i);
		}
	}
	for(int i=3;i<n;++i)
	{
		int _or=ask(0,i,'|'),_and=ask(0,i,'&');
		for(int j=0;j<30;++j)
		{
			if(bit(_or,j)==0)
			{
				continue;
			}
			if(bit(_and,j)==1)
			{
				a[i]+=(1<<j);
				continue;
			}
			if(bit(a[0],j)==0)
			{
				a[i]+=(1<<j);
				continue;
			}
		}
	}
	reply(a,k);
	return 0;
}
