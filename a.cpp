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
        int n,i=1;
        priority_queue<pair<int,int>> pq;
        cin>>n;
        vector<int> ans(n);
        pq.push({n,0});     // {len,-start_idx}
        while(pq.size())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            int len=p.first,idx=-p.second;
            ans[idx+((len-1)>>1)]=i++;
            if(len>1)
            {
                if(len&1)
                {
                    pq.push({(len>>1),-idx});
                    pq.push({(len>>1),-(idx+((len+1)>>1))});
                }
                else
                {
                    if(len!=2)
                    {
                        pq.push({(len>>1)-1,-idx});
                    }
                    pq.push({(len>>1),-(idx+(len>>1))});
                }
            }
        }
        for(auto &v:ans)
        {
            cout<<v<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
