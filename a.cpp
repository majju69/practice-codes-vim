#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        bool ok=1;
        queue<pair<int,int>> q;
        cin>>n>>m;
        vector<string> a(n);
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(auto &v:a)
        {
            cin>>v;
        }
        for(int x=0;x<n;++x)
        {
            for(int y=0;y<m;++y)
            {
                if(a[x][y]=='.')
                {
                    bool mark=0;
                    for(int i=0;i<4;++i)
                    {
                        int r=x+dx[i],c=y+dy[i];
                        if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]=='B')
                        {
                            mark=1;
                            break;
                        }
                    }
                    if(mark)
                    {
                        a[x][y]='#';
                    }
                }
            }
        }
        if(a[n-1][m-1]!='#')
        {
            q.push({n-1,m-1});
            vis[n-1][m-1]=1;
            while(!q.empty())
            {
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(int i=0;i<4;++i)
                {
                    int r=x+dx[i],c=y+dy[i];
                    if(r>=0&&r<n&&c>=0&&c<m&&!vis[r][c]&&a[r][c]!='#')
                    {
                        q.push({r,c});
                        vis[r][c]=1;
                    }
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            if(!ok)
            {
                break;
            }
            for(int j=0;j<m;++j)
            {
                if((a[i][j]=='G'&&!vis[i][j])||(a[i][j]=='B'&&vis[i][j]))
                {
                    ok=0;
                    break;
                }
            }
        }
        cout<<(ok?"Yes":"No")<<'\n';
    }
    return 0;
}
