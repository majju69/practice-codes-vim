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

inline int get(char c)
{
    return (int)(c-'a');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,q;
    string s;
    cin>>n>>k>>s;
    vector<int> dp(n,1e9);
    vector<vector<int>> idx(k);
    for(int i=0;i<n;++i)
    {
        idx[get(s[i])].push_back(i);
    }
    dp[n-1]=1;
    for(int i=n-2;i>=0;--i)
    {
        int cur=1e9;
        for(int j=0;j<k;++j)
        {
            int nxt=upper_bound(idx[j].begin(),idx[j].end(),i)-idx[j].begin();
            if(nxt>=(int)idx[j].size())
            {
                cur=1;
                break;
            }
            nxt=idx[j][nxt];
            cur=min(cur,dp[nxt]+1);
        }
        dp[i]=cur;
    }
    cin>>q;
    while(q--)
    {
        int len=0,cur=-1;
        string t;
        cin>>t;
        len=t.size();
        for(int i=0;i<len;++i)
        {
            int nxt=upper_bound(idx[get(t[i])].begin(),idx[get(t[i])].end(),cur)-idx[get(t[i])].begin();
            if(nxt>=(int)idx[get(t[i])].size())
            {
                cur=-1;
                break;
            }
            cur=idx[get(t[i])][nxt];
        }
        if(cur==-1)
        {
            cout<<0<<'\n';
        }
        else
        {
            cout<<dp[cur]<<'\n';
        }
    }
    return 0;
}
