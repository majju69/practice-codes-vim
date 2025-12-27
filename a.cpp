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
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i].first;
            a[i].second=i+1;
        }
        sort(a.begin(),a.end());
        if(m>(n>>1))
        {
            cout<<-1<<'\n';
        }
        else
        {
            if(m==0)
            {
                int s=0,idx=-1;
                for(int i=n-2;i>=0;--i)
                {
                    if(s+a[i].first>=a[n-1].first)
                    {
                        break;
                    }
                    s+=a[i].first;
                    idx=i;
                }
                if(idx==0)
                {
                    if(s<a[n-1].first)
                    {
                        cout<<-1<<'\n';
                    }
                    else
                    {
                        cout<<n-1<<'\n';
                        for(int i=0;i<n-1;++i)
                        {
                            cout<<a[i].second<<' '<<a[n-1].second<<'\n';
                        }
                    }
                    continue;
                }
                vector<pair<int,int>> ans;
                for(int i=idx;i<n-1;++i)
                {
                    ans.push_back({a[i].second,a[n-1].second});
                }
                for(int i=0;i<idx-1;++i)
                {
                    ans.push_back({a[i].second,a[i+1].second});
                }
                ans.push_back({a[n-1].second,a[idx-1].second});
                cout<<(int)ans.size()<<'\n';
                for(auto &v:ans)
                {
                    cout<<v.first<<' '<<v.second<<'\n';
                }
            }
            else if(m==1)
            {
                cout<<n-1<<'\n';
                for(int i=0;i<n-1;++i)
                {
                    cout<<a[i].second<<' '<<a[i+1].second<<'\n';
                }
            }
            else
            {
                int idx=0,rem=n;
                vector<pair<int,int>> ans;
                while(rem>(m<<1))
                {
                    ans.push_back({a[idx].second,a[idx+1].second});
                    idx++;
                    rem--;
                }
                for(int i=idx;i<n;i+=2)
                {
                    ans.push_back({a[i+1].second,a[i].second});
                }
                cout<<(int)ans.size()<<'\n';
                for(auto &v:ans)
                {
                    cout<<v.first<<' '<<v.second<<'\n';
                }
            }
        }
    }
    return 0;
}
