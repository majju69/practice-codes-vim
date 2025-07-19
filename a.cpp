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
    vector<int> par(500001);
    deque<int> ans;
    cin>>q;
    vector<int> x(q,-1),y(q,-1);
    for(int i=0;i<q;++i)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            cin>>x[i];
        }
        else
        {
            cin>>x[i]>>y[i];
        }
    }
    for(int i=0;i<=500000;++i)
    {
        par[i]=i;
    }
    for(int i=q-1;i>=0;--i)
    {
        if(y[i]==-1)
        {
            ans.push_front(par[x[i]]);
        }
        else
        {
            par[x[i]]=par[y[i]];
        }
    }
    for(auto &v:ans)
    {
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
