#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

deque<int> add(deque<int> &a,deque<int> &b)
{
	while((int)a.size()<(int)b.size())
	{
		a.push_back(0);
	}
	while((int)b.size()<(int)a.size())
	{
		b.push_back(0);
	}
	int n=a.size(),carry=0;
	deque<int> ans(n);
	for(int i=0;i<n;++i)
	{
		int x=a[i]+b[i]+carry;
		ans[i]=x%26;
		carry=x/26;
	}
	if(carry!=0)
	{
		ans.push_back(carry);
	}
	return ans;
}

inline char get(int i)
{
	return (char)(i+'a');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,cnt=0;
	string s,t;
	deque<int> a,b,sum,rem,sum2,sum4,sum8,ans;
	cin>>n>>s>>t;
	for(int i=n-1;i>=0;--i)
	{
		a.push_back(s[i]-'a');
		b.push_back(t[i]-'a');
	}
	while((int)a.size()&&a.back()==b.back()&&a.back()==0)
	{
		a.pop_back();
		b.pop_back();
		cnt++;
	}
	sum=add(a,b);
	rem.push_back(sum[0]/2);
	sum.pop_front();
	sum2=add(sum,sum);
	sum4=add(sum2,sum2);
	sum8=add(sum4,sum4);
	ans=add(sum,sum4);
	ans=add(ans,sum8);
	ans=add(ans,rem);
	while(cnt--)
	{
		ans.push_back(0);
	}
	reverse(ans.begin(),ans.end());
	for(auto &v:ans)
	{
		cout<<get(v);
	}
	cout<<'\n';
	return 0;
}
