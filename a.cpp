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
		int n,q,sum=0;
		string s;
		cin>>n>>q>>s;
		vector<int> a(n),pre(n),pre_mx(n),suf_mx(n),pre_mn(n),suf_mn(n);
		for(int i=0;i<n;++i)
		{
			a[i]=((s[i]=='+')?1:-1);
			sum+=a[i];
			pre[i]=sum;
			pre_mn[i]=((i==0)?pre[i]:min(pre_mn[i-1],pre[i]));
			pre_mx[i]=((i==0)?pre[i]:max(pre_mx[i-1],pre[i]));
		}
		suf_mn[n-1]=suf_mx[n-1]=pre[n-1];
		for(int i=n-2;i>=0;--i)
		{
			suf_mn[i]=min(suf_mn[i+1],pre[i]);
			suf_mx[i]=max(suf_mx[i+1],pre[i]);
		}
		while(q--)
		{
			int l,r,mn=0,mx=0;
			cin>>l>>r;
			l--;
			r--;
			if(l!=0)
			{
				mn=min(mn,pre_mn[l-1]);
				mx=max(mx,pre_mx[l-1]);
			}
			if(r!=n-1)
			{
				mn=min(mn,suf_mn[r+1]-(pre[r]-((l==0)?0:pre[l-1])));
				mx=max(mx,suf_mx[r+1]-(pre[r]-((l==0)?0:pre[l-1])));
			}
			cout<<mx-mn+1<<'\n';
		}
	}
	return 0;
}
