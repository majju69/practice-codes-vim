#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline char get(int i)
{
	return (char)(i+'a');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,idx=0,perm[]={0,1,2};
	string str;
	cin>>n>>q>>str;
	vector<int> cost[6];
	do
	{
		int s=0,cur=0;
		for(auto &v:str)
		{
			s+=(v!=get(perm[cur]));
			cur++;
			if(cur==3)
			{
				cur=0;
			}
			cost[idx].push_back(s);
		}
		idx++;
	}while(next_permutation(perm,perm+3));
	while(q--)
	{
		int l,r,ans=1e9;
		cin>>l>>r;
		l--;
		r--;
		for(int i=0;i<6;++i)
		{
			ans=min(ans,cost[i][r]-((l==0)?0:cost[i][l-1]));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
