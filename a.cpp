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
    long long u,v;
    cin>>u>>v;
    if(u>v)
    {
        cout<<-1<<'\n';
    }
    else
    {
        long long diff=v-u;
        if(diff&1)
        {
            cout<<-1<<'\n';
        }
        else
        {
            vector<long long> ans;
            if(u!=0)
            {
                ans.push_back(u);
            }
            if(diff!=0)
            {
                ans.push_back(diff>>1);
                ans.push_back(diff>>1);
            }
            if((long long)ans.size()>2)
            {
                sort(ans.begin(),ans.end());
                if((ans[0]&ans[2])==0)
                {
                    ans[0]+=ans[2];
                    ans.pop_back();
                }
            }
            cout<<(long long)ans.size()<<'\n';
            for(auto &v:ans)
            {
                cout<<v<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
