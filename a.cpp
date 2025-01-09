#include <bits/stdc++.h>
using namespace std;

inline int ask(int i,int j)
{
	cout<<"? "<<i+1<<' '<<j+1<<endl;
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

int main()
{
	int n;
	cin>>n;
	vector<int> a(n,-1),unknown(n,-1);
	iota(unknown.begin(),unknown.end(),0);
	while((int)unknown.size()>1)
	{
		vector<int> tmp;
		int len=unknown.size();
		for(int i=0;i<len-1;i+=2)
		{
			int a1=ask(unknown[i],unknown[i+1]),a2=ask(unknown[i+1],unknown[i]);
			if(a1>a2)
			{
				a[unknown[i]]=a1;
				tmp.push_back(unknown[i+1]);
			}
			else
			{
				a[unknown[i+1]]=a2;
				tmp.push_back(unknown[i]);
			}
		}
		if(len&1)
		{
			tmp.push_back(unknown[len-1]);
		}
		unknown=tmp;
	}
	a[unknown[0]]=n;
	reply(a);
	return 0;
}
