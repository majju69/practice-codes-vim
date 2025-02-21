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
	int n,k,ans=0;
	cin>>n>>k;
	vector<string> a(n);
	vector<vector<int>> col_pre(n,vector<int>(n,0)),col_suf(n,vector<int>(n,0)),row_pre(n,vector<int>(n,0)),row_suf(n,vector<int>(n,0)),good_col(n,vector<int>(n,0)),good_row(n,vector<int>(n,0));
	vector<int> already_good_row(n,0),already_good_col(n,0);
	for(auto &s:a)
	{
		cin>>s;
	}
	for(int i=0;i<n;++i)
	{
		int cnt=0;
		for(int j=0;j<n;++j)
		{
			cnt+=(a[i][j]=='W');
			row_pre[i][j]=((a[i][j]=='W')&&((j==0)?1:row_pre[i][j-1]));
			col_pre[i][j]=((a[i][j]=='W')&&((i==0)?1:col_pre[i-1][j]));
		}
		already_good_row[i]=(cnt==n)+((i==0)?0:already_good_row[i-1]);
	}
	for(int j=0;j<n;++j)
	{
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			cnt+=(a[i][j]=='W');
		}
		already_good_col[j]=(cnt==n)+((j==0)?0:already_good_col[j-1]);
	}
	for(int i=n-1;i>=0;--i)
	{
		for(int j=n-1;j>=0;--j)
		{
			row_suf[i][j]=((a[i][j]=='W')&&((j==n-1)?1:row_suf[i][j+1]));
			col_suf[i][j]=((a[i][j]=='W')&&((i==n-1)?1:col_suf[i+1][j]));
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			int up=((i==0)||(col_pre[i-1][j])),down=((i+k>=n)||col_suf[i+k][j]),left=((j==0)||row_pre[i][j-1]),right=((j+k>=n)||row_suf[i][j+k]);
			good_row[i][j]=(left&&right);
			good_col[i][j]=(up&&down);
			if(i>0)
			{
				good_row[i][j]+=good_row[i-1][j];
			}
			if(j>0)
			{
				good_col[i][j]+=good_col[i][j-1];
			}
		}
	}
	for(int i=0;i<n-k+1;++i)
	{
		for(int j=0;j<n-k+1;++j)
		{
			int row=good_row[i+k-1][j]-((i==0)?0:good_row[i-1][j]),col=good_col[i][j+k-1]-((j==0)?0:good_col[i][j-1]);
			ans=max(ans,row+col+(already_good_row[n-1]-already_good_row[i+k-1])+(already_good_col[n-1]-already_good_col[j+k-1])+((i==0)?0:already_good_row[i-1])+((j==0)?0:already_good_col[j-1]));
		}
	}
	cout<<ans<<'\n';
	return 0;
}
