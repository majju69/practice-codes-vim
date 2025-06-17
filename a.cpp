#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

typedef long long ll;
const int N=2e5+10,LOG=19;

int lookup[N][LOG];

void buildSparseTable(vector<int> &a)
{
	int n=a.size();
	for(int i=0;i<n;++i)
	{
		lookup[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;++j)
	{
		for(int i=0;(i+(1<<j)-1)<n;++i)
		{
			if(lookup[i][j-1]>lookup[i+(1<<(j-1))][j-1])
			{
				lookup[i][j]=lookup[i][j-1];
			}
			else
			{
				lookup[i][j]=lookup[i+(1<<(j-1))][j-1];
			}
		}
	}
}

inline int query(int l,int r)
{
	int j=31-__builtin_clz(r-l+1);
	return max(lookup[l][j],lookup[r-(1<<j)+1][j]);
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
		int n,x;
		ll s,sum=0,ans=0;
		map<ll,vector<int>> mp;
		cin>>n>>s>>x;
		vector<int> a(n);
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
			sum+=a[i];
			mp[sum].push_back(i);
		}
		buildSparseTable(a);
		sum=0;
		for(int i=0;i<n;++i)
		{
			ll req=s+sum;
			if(!mp.count(req))
			{
				sum+=a[i];
				continue;
			}
			int lo=i,hi=n-1,first_mx=-1,last_mx=-1;
			vector<int> &vec=mp[req];
			while(lo<=hi)
			{
				int mid=lo+(hi-lo)/2;
				if(query(i,mid)>=x)
				{
					first_mx=mid;
					hi=mid-1;
				}
				else
				{
					lo=mid+1;
				}
			}
			lo=i;
			hi=n-1;
			while(lo<=hi)
			{
				int mid=lo+(hi-lo)/2;
				if(query(i,mid)<=x)
				{
					last_mx=mid;
					lo=mid+1;
				}
				else
				{
					hi=mid-1;
				}
			}
			if(first_mx!=-1&&query(i,first_mx)==x)
			{
				ll cnt=upper_bound(vec.begin(),vec.end(),last_mx)-lower_bound(vec.begin(),vec.end(),first_mx);
				ans+=cnt;
			}
			sum+=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
