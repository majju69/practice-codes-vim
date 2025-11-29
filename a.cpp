#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

bool bit(int a,int i)
{
    return a>>i&1;
}

int get(vector<int> &a,int i)
{
    if(i==0)
    {
        int cnt[]={0,0};
        for(auto &v:a)
        {
            cnt[bit(v,i)]++;
            if(cnt[0]!=0&&cnt[1]!=0)
            {
                return 1;
            }
        }
        return 0;
    }
    vector<int> cur[2];
    for(auto &v:a)
    {
        cur[bit(v,i)].push_back(v);
    }
    if(cur[0].size()==0||cur[1].size()==0)
    {
        return get(a,i-1);
    }
    return min(get(cur[0],i-1),get(cur[1],i-1))+(1<<i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    cout<<get(a,29)<<'\n';
    return 0;
}
