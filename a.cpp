#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long double ld;

ld dp[105][105][105];

int get(const int &x)
{
    return ((x*(x-1))>>1);
}

ld get(const int &i,const int &j,const int &k)
{
    if(i<0||j<0||k<0)
    {
        return 0.0l;
    }
    return dp[i][j][k];
}

void init(const int &r,const int &s,const int &p,const char &ch)
{
    for(int i=0;i<=r;++i)
    {
        for(int j=0;j<=s;++j)
        {
            for(int k=0;k<=p;++k)
            {
                dp[i][j][k]=0.0l;
            }
        }
    }
    if(ch=='r')
    {
        for(int i=1;i<=r;++i)
        {
            dp[i][0][0]=1.0l;
        }
        return;
    }
    if(ch=='s')
    {
        for(int j=1;j<=s;++j)
        {
            dp[0][j][0]=1.0l;
        }
        return;
    }
    if(ch=='p')
    {
        for(int k=1;k<=p;++k)
        {
            dp[0][0][k]=1.0l;
        }
        return;
    }
    assert(0);
}

void fill_dp(const int &r,const int &s,const int &p)
{
    for(int i=0;i<=r;++i)
    {
        for(int j=0;j<=s;++j)
        {
            for(int k=0;k<=p;++k)
            {
                int x=(i!=0)+(j!=0)+(k!=0);
                if(x<=1)
                {
                    continue;
                }
                ld num=get(i-1,j,k)*i*k+get(i,j-1,k)*i*j+get(i,j,k-1)*j*k,den=1.0l*(get(i+j+k)-get(i)-get(j)-get(k));
                dp[i][j][k]=num/den;
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,s,p;
    ld a=0,b=0;
    cin>>r>>s>>p;
    init(r,s,p,'r');
    fill_dp(r,s,p);
    a=dp[r][s][p];
    init(r,s,p,'s');
    fill_dp(r,s,p);
    b=dp[r][s][p];
    cout<<fixed<<setprecision(10)<<a<<' '<<b<<' '<<1-a-b<<'\n';
    return 0;
}
