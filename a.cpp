#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

deque<pair<ll,ll>> mergeOverlap(deque<pair<ll,ll>> &a)
{
    sort(a.begin(),a.end());
    deque<pair<ll,ll>> res;
    res.push_back(a[0]);
    for(int i=1;i<a.size();++i)
    {
        pair<ll,ll> &last=res.back();
        pair<ll,ll> &curr=a[i];
        if(curr.first<=last.second)
        {
            last.second=max(last.second,curr.second);
        } 
        else 
        {
            res.push_back(curr);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,k,x,lo=0,hi=1e9,cur=0,ans=-1;
        deque<pair<ll,ll>> finalRes;
        cin>>n>>k>>x;
        vector<ll> a(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        while(lo<=hi)
        {
            ll mid=lo+(hi-lo)/2,cnt=0;
            deque<pair<ll,ll>> bad,res;
            for(auto &v:a)
            {
                ll l=v-mid+1,r=v+mid-1;
                if(l<0)
                {
                    l=0;
                }
                if(r>x)
                {
                    r=x;
                }
                if(l<=r)
                {
                    bad.push_back({l,r});
                }
            }
            if((ll)bad.size()>0)
            {
                res=mergeOverlap(bad);
                for(auto &v:res)
                {
                    cnt+=(v.second-v.first+1);
                }
            }
            if(x+1-cnt>=k)
            {
                ans=mid;
                finalRes=res;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        sort(finalRes.begin(),finalRes.end());
        while(k>0)
        {
            if((ll)finalRes.size()>0&&cur==finalRes[0].first)
            {
                cur=finalRes[0].second+1;
                finalRes.pop_front();
            }
            else
            {
                cout<<cur<<' ';
                cur++;
                k--;
            }
        }
        cout<<'\n';
    }
    return 0;
}
