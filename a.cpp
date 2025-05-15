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
		int n,mx=0,l=-1,r=-1;
		vector<int> a,idx[5];
		cin>>n;
		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			a.push_back(x);
			idx[x+2].push_back(i);
		}
		for(int i=0;i<n;++i)
		{
			if(a[i]==0)
			{
				continue;
			}
			int cur_idx=upper_bound(idx[2].begin(),idx[2].end(),i)-idx[2].begin();
			if(cur_idx>=(int)idx[2].size())
			{
				cur_idx=n-1;
			}
			else
			{
				cur_idx=idx[2][cur_idx]-1;
			}
			int cnt_neg2=(upper_bound(idx[0].begin(),idx[0].end(),cur_idx)-lower_bound(idx[0].begin(),idx[0].end(),i)),cnt_neg1=(upper_bound(idx[1].begin(),idx[1].end(),cur_idx)-lower_bound(idx[1].begin(),idx[1].end(),i));
			if((cnt_neg2+cnt_neg1)&1)
			{
				if(cnt_neg2+cnt_neg1==1&&a[i]<0)
				{
					continue;
				}
				int rem1=-1,rem2=-1;
				if(cnt_neg1>0)
				{
					rem1=idx[1][lower_bound(idx[1].begin(),idx[1].end(),cur_idx+1)-idx[1].begin()-1]-1;
				}
				if(cnt_neg2>0)
				{
					rem2=idx[0][lower_bound(idx[0].begin(),idx[0].end(),cur_idx+1)-idx[0].begin()-1]-1;
				}
				if(rem2>rem1)
				{
					cur_idx=rem2;
					cnt_neg2--;
				}
				else
				{
					cur_idx=rem1;
					cnt_neg1--;
				}
			}
			int cnt_2=(upper_bound(idx[4].begin(),idx[4].end(),cur_idx)-lower_bound(idx[4].begin(),idx[4].end(),i));
			if(cnt_neg2+cnt_2>mx)
			{
				mx=cnt_neg2+cnt_2;
				l=i;
				r=cur_idx;
			}
		}
		if(mx==0)
		{
			cout<<0<<' '<<n<<'\n';
		}
		else
		{
			cout<<l<<' '<<n-1-r<<'\n';
		}
	}
	return 0;
}
