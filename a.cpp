#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2e3+10;
int a[N],pre[N],lis[N][N][2],lds[N][N][2];

inline int get_lis0(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    return lis[l][r][0];
}

inline int get_lis1(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    return lis[l][r][1];
}

inline int get_lds0(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    return lds[l][r][0];
}

inline int get_lds1(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    return lds[l][r][1];
}

inline int get(int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    return pre[r]-((l==0)?0:pre[l-1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s=0,ans=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]--;
        s+=a[i];
        pre[i]=s;
    }
    for(int i=0;i<n;++i)
    {
        int cnt[]={0,0};
        for(int j=i;j<n;++j)
        {
            if(a[j]==0)
            {
                cnt[0]++;
            }
            else
            {
                cnt[1]=max(cnt[0],cnt[1])+1;
            }
            lis[i][j][0]=cnt[0];
            lis[i][j][1]=cnt[1];
        }
    }
    for(int i=0;i<n;++i)
    {
        int cnt[2][2]={{0,0},{0,0}};
        for(int j=i;j<n;++j)
        {
            if(a[j]==0)
            {
                cnt[0][0]++;
                cnt[1][0]=max(cnt[1][1],cnt[1][0])+1;
            }
            else
            {
                cnt[1][1]++;   
            }
            lds[i][j][0]=cnt[0][0];
            lds[i][j][1]=max(cnt[1][0],cnt[1][1]);
        }
    }
    for(int i=0;i<n;++i)    // 000 001 011 111
    {
        for(int j=i;j<n;++j)
        {
            ans=max(ans,get_lis0(0,i-1)+get_lds0(i,j)+get_lis0(j+1,n-1));
            ans=max(ans,get_lis0(0,i-1)+get_lds0(i,j)+get_lis1(j+1,n-1));
            ans=max(ans,get_lis0(0,i-1)+get_lds1(i,j)+get(j+1,n-1));
            ans=max(ans,get_lis1(0,i-1)+get(i,j)+get(j+1,n-1));
        }
    }
    cout<<ans<<'\n';
    return 0;
}
