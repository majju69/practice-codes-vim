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
    int n,m,dx[]={0,0,-1,1},dy[]={-1,1,0,0},sx=-1,sy=-1,tx=-1,ty=-1,ans=1e9;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    cin>>n>>m;
    vector<string> a(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    vector<vector<vector<vector<int>>>> dist(n,vector<vector<vector<int>>>(m,vector<vector<int>>(5,vector<int>(4,1e9))));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
            if(a[i][j]=='T')
            {
                tx=i;
                ty=j;
            }
        }
    }
    q.push({{sx,sy},{0,0}});
    dist[sx][sy][0][0]=0;
    while(q.size())
    {
        int x=q.front().first.first,y=q.front().first.second,dir=q.front().second.first,steps=q.front().second.second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int r=x+dx[i],c=y+dy[i];
            if(i+1==dir)
            {
                if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!='#'&&steps<3&&dist[r][c][i+1][1+steps]>1+dist[x][y][dir][steps])
                {
                    dist[r][c][i+1][1+steps]=1+dist[x][y][dir][steps];
                    q.push({{r,c},{i+1,1+steps}});
                }
            }
            else
            {
                if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!='#'&&dist[r][c][i+1][1]>1+dist[x][y][dir][steps])
                {
                    dist[r][c][i+1][1]=1+dist[x][y][dir][steps];
                    q.push({{r,c},{i+1,1}});
                }
            }
        }
    }
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<4;++j)
        {
            ans=min(ans,dist[tx][ty][i][j]);
        }
    }
    if(ans==(int)1e9)
    {
        ans=-1;
    }
    cout<<ans<<'\n';
    return 0;
}
