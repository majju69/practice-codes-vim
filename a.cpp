#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

/*

0->2
1->3
.
.
.
7->9


*/

const ll mult[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};

ll dp[20][2][2][7][8][9][256];

bool bit(const int &a,const int &i)
{
    return a>>i&1;
}

int mul(const ll &a,const ll &b,const int mod)
{
    return (1ll*(a%mod)*(b%mod))%mod;
}

int add(const ll &a,const ll &b,const int mod)
{
    return ((a%mod)+(b%mod))%mod;
}


ll solve(int i,bool last,bool l50,int r7,int r8,int r9,int mask,const string &s)
{
    if(i>=(int)s.size())
    {
        if(bit(mask,0)&&(r8&1))
        {
            return 0;
        }
        if(bit(mask,1)&&(r9%3!=0))
        {
            return 0;
        }
        if(bit(mask,2)&&(r8&3))
        {
            return 0;
        }
        if(bit(mask,3)&&!l50)
        {
            return 0;
        }
        if(bit(mask,4)&&((r8&1)||(r9%3)))
        {
            return 0;
        }
        if(bit(mask,5)&&r7)
        {
            return 0;
        }
        if(bit(mask,6)&&r8)
        {
            return 0;
        }
        if(bit(mask,7)&&r9)
        {
            return 0;
        }
        return 1;
    }
    if(dp[i][last][l50][r7][r8][r9][mask]!=-1)
    {
        return dp[i][last][l50][r7][r8][r9][mask];
    }
    ll ans=0;
    int till=(last?(s[i]-'0'):9);
    for(int j=0;j<=till;++j)
    {
        const ll cur_mult=mult[(int)s.size()-1-i];
        if(j==0)
		{
			ans+=solve(i+1,(last&&(j==till)),(i==(int)s.size()-1),r7,r8,r9,mask,s);
		}
        else
		{
            if(j==1)
            {
                ans+=solve(i+1,(last&&(j==till)),0,add(r7,mul(cur_mult,1,7),7),add(r8,mul(cur_mult,1,8),8),add(r9,1,9),mask,s);
            }
            else
            {
                ans+=solve(i+1,(last&&(j==till)),(j==5&&i==(int)s.size()-1),add(r7,mul(cur_mult,j,7),7),add(r8,mul(cur_mult,j,8),8),add(r9,j,9),(mask|(1<<(j-2))),s);
            }
		}
    }
    return dp[i][last][l50][r7][r8][r9][mask]=ans;
}

ll get(const string &s)
{
    memset(dp,-1,sizeof(dp));
    return solve(0,1,0,0,0,0,0,s);
}

ll get(ll l,ll r)
{
    l--;
    return get(to_string(r))-get(to_string(l));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<get(l,r)<<'\n';
    }
    return 0;
}

