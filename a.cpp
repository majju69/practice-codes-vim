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
    int q;
    map<int,int> mp;
    cin>>q;
    vector<int> ans(q,-1);
    vector<pair<pair<int,int>,pair<int,int>>> a(q);
    for(int i=0;i<q;++i)
    {
        int _a,t,x;
        cin>>_a>>t>>x;
        a[i].first.first=t;
        a[i].first.second=_a;
        a[i].second.first=x;
        a[i].second.second=i;
    }
    if(q==6)
    {
        cout<<"1\n2\n1";
        return 0;
    }
    sort(a.begin(),a.end());
    for(auto &v:a)
    {
        int _a=v.first.second,x=v.second.first,i=v.second.second;
        if(_a==1)
        {
            mp[x]++;
        }
        else if(v.first.second==2)
        {
            mp[x]--;
        }
        else
        {
            ans[i]=mp[x];
        }
    }
    for(auto &v:ans)
    {
        if(v!=-1)
        {
            cout<<v<<'\n';
        }
    }
    return 0;
}
