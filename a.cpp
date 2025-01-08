#include <bits/stdc++.h>
using namespace std;

inline int ask(int i,int j,char c)
{
	if(c=='|')
	{
		cout<<"OR ";
	}
	else if(c=='&')
	{
		cout<<"AND ";
	}
	else if(c=='^')
	{
		cout<<"XOR ";
	}
	else
	{
		assert(0);
	}
	cout<<i+1<<' '<<j+1<<endl;
	int x;
	cin>>x;
	if(x==-1)
	{
		exit(1);
	}
	return x;
}

void reply(vector<int> &a)
{
	cout<<"! ";
	for(auto &v:a)
	{
		cout<<v<<' ';
	}
	cout<<endl;
}

inline int bit(int a,int i)
{
	return (a>>i&1);
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n,0),a0(17,-1),a1(17,-1),a2(17,-1);
	int _and=ask(0,1,'&'),_xor=ask(0,1,'^'),_and1=ask(1,2,'&'),_and0=ask(0,2,'&'),_xor1=ask(1,2,'^');
	for(int i=0;i<17;++i)
	{
		if(bit(_xor,i)==0)
		{
			a0[i]=bit(_and,i);
			a1[i]=a0[i];
			if(a0[i])
			{
				a[0]+=(1<<i);
				a[1]+=(1<<i);
			}
		}
	}
	for(int i=0;i<17;++i)
	{
		if(a1[i]!=-1)
		{
			a2[i]=(a1[i]^bit(_xor1,i));
			if(a2[i])
			{
				a[2]+=(1<<i);
			}
		}
		else
		{
			if(bit(_xor1,i))		// bit1[i]!=bit2[i] => bit2[i]=bit0[i]
			{
				a2[i]=bit(_and0,i);
				a0[i]=a2[i];
				a1[i]=1-a0[i];
				if(a2[i])
				{
					a[2]+=(1<<i);
					a[0]+=(1<<i);
				}
				else
				{
					a[1]+=(1<<i);
				}
			}
			else		// bit1[i]=bit2[i]
			{
				a2[i]=bit(_and1,i);
				a1[i]=a2[i];
				a0[i]=1-a1[i];
				if(a2[i])
				{
					a[2]+=(1<<i);
					a[1]+=(1<<i);
				}
				else
				{
					a[0]+=(1<<i);
				}
			}
		}
	}
	for(int i=3;i<n;++i)
	{
		// a0^ai^a0=ai
		int x=ask(0,i,'^');
		a[i]=(x^a[0]);
	}
	reply(a);
	return 0;
}
