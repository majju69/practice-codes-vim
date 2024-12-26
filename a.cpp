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
		int n;
		string s,t;
		cin>>n>>s>>t;
		if(s==t)
		{
			cout<<"YES\n";
		}
		else
		{
			bool ok=0;
			vector<int> a(26,0),b(26,0);
			for(int i=0;i<n;++i)
			{
				a[s[i]-'a']++;
				b[t[i]-'a']++;
				if(a[s[i]-'a']>=2)
				{
					ok=1;
				}
			}
			ok=(ok&&a==b);
			if(ok)
			{
				cout<<"YES\n";
			}
			else
			{
				for(int i=0;i<n-1;++i)
				{
					for(int j=0;j<n-i-1;++j)
					{
						if(s[j]>s[j+1])
						{
							swap(s[j],s[j+1]);
							swap(t[0],t[1]);
						}
					}
				}
				for(int i=0;i<n-1;++i)
				{
					for(int j=0;j<n-i-1;++j)
					{
						if(t[j]>t[j+1])
						{
							swap(t[j],t[j+1]);
							swap(s[0],s[1]);
						}
					}
				}
				cout<<((s==t)?"YES":"NO")<<'\n';
			}
		}
	}
	return 0;
}
