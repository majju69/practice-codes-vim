#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll N=55,D=105;
ll dp[N][N][D];     // ith taken which is the jth one and a[i]+k hw given
array<ll,3> par[N][N][D];      
array<ll,4> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,k,idx=-1,cnt=-1,diff=-1,mx=-1e18;
    cin>>n>>m>>k;
    for(ll i=0;i<m;++i)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][0];
        a[i][3]=i;
    }
    sort(a,a+m);
    memset(dp,0xc0,sizeof(dp));
    for(ll i=0;i<m;++i)
    {
        for(ll j=1;j<=n;++j)
        {
            for(ll d=0;d<=a[i][2]-a[i][1];++d)
            {
                if(j==1)
                {
                    dp[i][j][d]=a[i][1]+d;
                    par[i][j][d]={-1,-1,-1};
                }
                else
                {
                    for(ll pvs=0;pvs<i;++pvs)
                    {
                        if(a[pvs][0]<a[i][0])
                        {
                            const ll cur_hw=a[i][1]+d;
                            if(cur_hw%k==0&&a[pvs][1]<=cur_hw/k&&cur_hw/k<=a[pvs][2]&&dp[pvs][j-1][cur_hw/k-a[pvs][1]]>0)
                            {
                                if(dp[pvs][j-1][cur_hw/k-a[pvs][1]]+cur_hw>dp[i][j][d])
                                {
                                    dp[i][j][d]=dp[pvs][j-1][cur_hw/k-a[pvs][1]]+cur_hw;
                                    par[i][j][d]={pvs,j-1,cur_hw/k-a[pvs][1]};
                                }
                            }
                            if(a[pvs][1]<=cur_hw-k&&cur_hw-k<=a[pvs][2]&&dp[pvs][j-1][cur_hw-k-a[pvs][1]]>0)
                            {
                                if(dp[pvs][j-1][cur_hw-k-a[pvs][1]]+cur_hw>dp[i][j][d])
                                {
                                    dp[i][j][d]=dp[pvs][j-1][cur_hw-k-a[pvs][1]]+cur_hw;
                                    par[i][j][d]={pvs,j-1,cur_hw-k-a[pvs][1]};
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(ll i=0;i<m;++i)
    {
        for(ll d=0;d<=a[i][2]-a[i][1];++d)
        {
            if(dp[i][n][d]>0&&dp[i][n][d]>mx)
            {
                mx=dp[i][n][d];
                idx=i;
                cnt=n;
                diff=d;
            }
        }
    }
    if(idx==-1)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
        ll cur_idx=idx,cur_cnt=cnt,cur_diff=diff;
        vector<pair<ll,ll>> ans;
        while(cur_idx>=0)
        {
            ans.push_back({a[cur_idx][3]+1,a[cur_idx][1]+cur_diff});
            const array<ll,3> p=par[cur_idx][cur_cnt][cur_diff];
            cur_idx=p[0];
            cur_cnt=p[1];
            cur_diff=p[2];
        }
        reverse(ans.begin(),ans.end());
        for(auto &v:ans)
        {
            cout<<v.first<<' '<<v.second<<'\n';
        }
    }
    return 0;
}
