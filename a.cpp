#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    if(a.first.second==b.first.second)
    {
        return a.first.first<b.first.first;
    }
    return a.first.second>b.first.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,totalMoney=0;
    set<pair<int,int>> st;  //{tableSize,tableIndex}
    vector<pair<int,int>> acceptedRequests; //{groupIndex,tableIndex}
    cin>>n;
    vector<pair<pair<int,int>,int>> requests(n);   //{{groupSize,groupPay},groupIndex}
    for(int i=0;i<n;++i)
    {
        int groupSize,groupPay;
        cin>>groupSize>>groupPay;
        requests[i].first.first=groupSize;
        requests[i].first.second=groupPay;
        requests[i].second=i+1;
    }
    cin>>k;
    for(int i=1;i<=k;++i)
    {
        int tableSize;
        cin>>tableSize;
        st.insert({tableSize,i});
    }
    sort(requests.begin(),requests.end(),cmp);
    for(auto &v:requests)
    {
        if(st.size()==0)
        {
            break;
        }
        int groupSize=v.first.first,groupPay=v.first.second,groupIndex=v.second;
        pair<int,int> dummy={groupSize,0};
        auto it=st.lower_bound(dummy);
        if(it!=st.end())
        {
            pair<int,int> accepted=*it;
            acceptedRequests.push_back({groupIndex,accepted.second});
            totalMoney+=groupPay;
            st.erase(it);
        }
    }
    cout<<acceptedRequests.size()<<' '<<totalMoney<<'\n';
    for(auto &v:acceptedRequests)
    {
        cout<<v.first<<' '<<v.second<<'\n';
    }
    return 0;
}
