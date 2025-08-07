#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

vector<vector<int>> divisors(100001);

void fillDivisors()
{
    int n=divisors.size();
    divisors[0].push_back(0);
    divisors[1].push_back(1);
    for(int i=2;i<n;i++)
    {
        divisors[i].push_back(1);
    }
    for(int i=2;i<n;i++)
    {
        for(int j=i;j<n;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

bool check(int mid,int m,vector<int> &a)
{
    int n=a.size(),i1=0,i2=-1,total=0;
    vector<int> cnt(m+1,0);
    for(int i=0;i<n;++i)
    {
        if(a[i]-a[i1]<=mid)
        {
            for(auto &d:divisors[a[i]])
            {
                if(d<=m)
                {
                    cnt[d]++;
                    total+=(cnt[d]==1);
                    if(total==m)
                    {
                        return 1;
                    }
                }
            }
            i2=i;
        }
        else
        {
            break;
        }
    }
    while(i2<n)
    {
        for(auto &d:divisors[a[i1]])
        {
            if(d<=m)
            {
                if(mid==0)
                {
                    debug(d);
                }
                total-=(cnt[d]==1);
                cnt[d]--;
            }
        }
        i1++;
        int _i2=i2;
        for(int i=i2+1;i<n;++i)
        {
            if(a[i]-a[i1]<=mid)
            {
                for(auto &d:divisors[a[i]])
                {
                    if(d<=m)
                    {
                        cnt[d]++;
                        total+=(cnt[d]==1);
                        if(total==m)
                        {
                            return 1;
                        }
                    }
                }
                _i2=i;
            }
            else
            {
                break;
            }
        }
        i2=max(i1,_i2);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fillDivisors();
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m,lo=0,hi=-1,ans=-1;
        cin>>n>>m;
        vector<int> a(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        sort(a.begin(),a.end());
        hi=a[n-1]-a[0];
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(check(mid,m,a))
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
