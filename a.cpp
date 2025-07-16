#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"debug.h"
#else
	#define debug(x)
#endif

inline int get(int l,int r,vector<int> &a)
{
	return upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q,_x=0,_y=0;
	map<pair<int,int>,vector<int>> mp_pre,mp_suf;
	vector<int> pre_x,pre_y,suf_x,suf_y;
	string s;
	cin>>n>>q>>s;
	for(int i=0;i<n;++i)
	{
		if(s[i]=='U')
		{
			_y++;
		}
		else if(s[i]=='D')
		{
			_y--;
		}
		else if(s[i]=='R')
		{
			_x++;
		}
		else
		{
			_x--;
		}
		mp_pre[{_x,_y}].push_back(i);
		pre_x.push_back(_x);
		pre_y.push_back(_y);
	}
	_x=0;
	_y=0;
	for(int i=n-1;i>=0;--i)
	{
		if(s[i]=='U')
		{
			_y++;
		}
		else if(s[i]=='D')
		{
			_y--;
		}
		else if(s[i]=='R')
		{
			_x++;
		}
		else
		{
			_x--;
		}
		mp_suf[{_x,_y}].push_back(i);
		suf_x.push_back(_x);
		suf_y.push_back(_y);
	}
	reverse(suf_x.begin(),suf_x.end());
	reverse(suf_y.begin(),suf_y.end());
	for(auto &v:mp_suf)
	{
		reverse(v.second.begin(),v.second.end());
	}
	while(q--)
	{
		int x,y,l,r;
		cin>>x>>y>>l>>r;
		l--;
		r--;
		if(x==0&&y==0)
		{
			cout<<"YES\n";
			continue;
		}
		if((l>0&&mp_pre.count({x,y})&&get(0,l-1,mp_pre[{x,y}])>0)||(r+1<n&&mp_pre.count({x,y})&&get(r+1,n-1,mp_pre[{x,y}])>0))
		{
			cout<<"YES\n";
			continue;
		}
		int res_x=x-((l>=1)?pre_x[l-1]:0)+((r+1<n)?suf_x[r+1]:0),res_y=y-((l>=1)?pre_y[l-1]:0)+((r+1<n)?suf_y[r+1]:0);
		if(mp_suf.count({res_x,res_y})&&get(l,r,mp_suf[{res_x,res_y}])>0)
		{
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
	return 0;
}
