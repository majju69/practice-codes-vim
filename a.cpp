#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

vector<vector<int>> divisors(100001);
vector<vector<int>> idx(100001);

void fillDivisors()
{
    int n=divisors.size();
    for(int i=2;i<n;i++)
    {
        for(int j=i;j<n;j+=i)
        {
            divisors[j].push_back(i);
        }
    }
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
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            idx[a[i]].push_back(i);
        }
        while(q--)
        {
            int k,l,r;
            cin>>k>>l>>r;
            if(k==1)
            {
                cout<<r-l+1<<'\n';
            }
            else
            {
                l--;
                r--;
                int cur=l;
                long long ans=0;
                while(cur<=r)
                {
                    if(k%a[cur]==0)
                    {
                        while(k%a[cur]==0)
                        {
                            k/=a[cur];
                        }
                        ans+=1ll*k;
                        cur++;
                        continue;
                    }
                    int nxt=r+1;
                    for(auto &v:divisors[k])
                    {
                        int _idx=lower_bound(idx[v].begin(),idx[v].end(),cur)-idx[v].begin();
                        if(_idx<(int)idx[v].size())
                        {
                            if(idx[v][_idx]<=r)
                            {
                                nxt=min(nxt,idx[v][_idx]);
                            }
                        }
                    }
                    ans+=1ll*(nxt-cur)*k;
                    cur=nxt;
                }
                cout<<ans<<'\n';
            }
        }
        for(auto &v:a)
        {
            idx[v].clear();
        }
    }
    return 0;
}
