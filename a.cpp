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
        string s;
        cin>>n;
        vector<int> adj[n];
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin>>s;
        if(s[0]!='?')
        {
            int ans=0,cnt=0;
            for(int i=1;i<n;++i)
            {
                if((int)adj[i].size()==1)
                {
                    if(s[i]=='?')
                    {
                        cnt++;
                    }
                    else
                    {
                        ans+=(s[i]!=s[0]);
                    }
                }
            }
            cnt++;
            cnt>>=1;
            cout<<ans+cnt<<'\n';
        }
        else
        {
            int leaf[]={0,0,0},cnt=0;
            for(int i=1;i<n;++i)
            {
                if((int)adj[i].size()==1)
                {
                    if(s[i]=='?')
                    {
                        leaf[2]++;
                    }
                    else
                    {
                        leaf[s[i]-'0']++;
                    }
                }
                else
                {
                    cnt+=(s[i]=='?');
                }
            }
            if(leaf[0]>leaf[1])
            {
                cout<<leaf[0]+(leaf[2]>>1)<<'\n';
            }
            else if(leaf[0]<leaf[1])
            {
                cout<<leaf[1]+(leaf[2]>>1)<<'\n';
            }
            else
            {
                if(cnt&1)
                {
                    cout<<leaf[0]+((leaf[2]+1)>>1)<<'\n';
                }
                else
                {
                    cout<<leaf[0]+(leaf[2]>>1)<<'\n';
                }
            }
        }
    }
    return 0;
}
