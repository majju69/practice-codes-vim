#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll dx[]={0,0,-1,1},dy[]={-1,1,0,0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,w,ans=1e18,mn=1e18;
    queue<pair<pair<ll,ll>,ll>> q;
    cin>>n>>m>>w;
    vector<vector<ll>> a(n,vector<ll>(m)),dist(n,vector<ll>(m,1e18));
    for(auto &vec:a)
    {
        for(auto &v:vec)
        {
            cin>>v;
        }
    }
    q.push({{n-1,m-1},0});
    dist[n-1][m-1]=0;
    while(!q.empty())
    {
        ll x=q.front().first.first,y=q.front().first.second,dis=q.front().second;
        q.pop();
        for(ll i=0;i<4;++i)
        {
            ll r=x+dx[i],c=y+dy[i];
            if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!=-1&&dist[r][c]>w+dis)
            {
                dist[r][c]=w+dis;
                q.push({{r,c},w+dis});
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(dist[i][j]<(ll)1e16)
            {
                if(a[i][j]>0)
                {
                    mn=min(mn,a[i][j]+dist[i][j]);
                }
            }
        }
    }
    dist=vector<vector<ll>>(n,vector<ll>(m,1e18));
    q.push({{0,0},0});
    dist[0][0]=0;
    while(!q.empty())
    {
        ll x=q.front().first.first,y=q.front().first.second,dis=q.front().second;
        if(a[x][y]>0)
        {
            ans=min(ans,dis+a[x][y]+mn);
        }
        if(x==n-1&&y==m-1)
        {
            ans=min(ans,dis);
        }
        q.pop();
        for(ll i=0;i<4;++i)
        {
            ll r=x+dx[i],c=y+dy[i];
            if(r>=0&&r<n&&c>=0&&c<m&&a[r][c]!=-1&&dist[r][c]>w+dis)
            {
                dist[r][c]=w+dis;
                q.push({{r,c},w+dis});
            }
        }
    }
    if(ans>(ll)1e16)
    {
        ans=-1;
    }
    cout<<ans<<'\n';
    return 0;
}
