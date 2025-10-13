#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

int ask(vector<int> &a)
{
	int n=a.size();
	cout<<"? "<<n<<' ';
	for(auto &v:a)
	{
		cout<<v+1<<' ';
	}
	cout<<endl;
	int x;
	cin>>x;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,cur=1;
		cin>>n;
		vector<int> ans(2*n,-1),idx={0};
		while(cur<2*n)
		{
			idx.push_back(cur);
			int x=ask(idx);
			if(x==0)
			{
				cur++;
			}
			else
			{
				ans[cur]=x;
				idx.pop_back();
				cur++;
			}
		}
		idx.clear();
		for(int i=0;i<2*n;++i)
		{
			if(ans[i]!=-1)
			{
				idx.push_back(i);
			}
		}
		for(int i=0;i<2*n;++i)
		{
			if(ans[i]==-1)
			{
				idx.push_back(i);
				ans[i]=ask(idx);
				idx.pop_back();
			}
		}
		reply(ans);
	}
	return 0;
}
