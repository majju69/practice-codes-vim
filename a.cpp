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
		int n,ans=0;
		cin>>n;
		vector<string> a(n);
		vector<vector<int>> pre(n,vector<int>(n,0)),pre_left(n,vector<int>(n,0)),pre_right(n,vector<int>(n,0));
		for(auto &v:a)
		{
			cin>>v;
		}
		for(int i=0;i<n;++i)
		{
			pre[0][i]=(a[0][i]=='1');
			pre_left[0][i]=(a[0][i]=='1');
			pre_right[0][i]=(a[0][i]=='1');
			ans+=(a[0][i]=='1');
		}
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				pre[i][j]=pre[i-1][j];
				if(j>0)
				{
					pre[i][j]+=pre_left[i-1][j-1];
					pre_left[i][j]=pre_left[i-1][j-1];
				}
				if(j+1<n)
				{
					pre[i][j]+=pre_right[i-1][j+1];
					pre_right[i][j]=pre_right[i-1][j+1];
				}
				if((pre[i][j]+(a[i][j]-'0'))&1)
				{
					ans++;
					pre[i][j]++;
					pre_left[i][j]++;
					pre_right[i][j]++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
