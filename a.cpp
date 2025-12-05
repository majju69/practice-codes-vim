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
    int n,ans_idx=-1;
    long long mx=-1;
    stack<int> st;
    cin>>n;
    vector<int> a(n),ans(n),pse(n,-1),nse(n,n);
    vector<long long> dp1(n,0),dp2(n,0);
    for(auto &v:a)
    {
        cin>>v;
    }
    for(int i=0;i<n;++i)
    {
        while(!st.empty()&&a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            pse[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(int i=n-1;i>=0;--i)
    {
        while(!st.empty()&&a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            nse[i]=st.top();
        }
        st.push(i);
    }
    dp1[0]=a[0];
    for(int i=1;i<n;++i)
    {
        int idx=pse[i];
        dp1[i]=1ll*(i-idx)*a[i];
        if(idx>=0)
        {
            dp1[i]+=dp1[idx];
        }
    }
    dp2[n-1]=a[n-1];
    for(int i=n-2;i>=0;--i)
    {
        int idx=nse[i];
        dp2[i]=1ll*(idx-i)*a[i];
        if(idx<n)
        {
            dp2[i]+=dp2[idx];
        }
    }
    for(int i=0;i<n;++i)
    {
        long long cur=dp1[i]+dp2[i]-a[i];
        if(cur>mx)
        {
            mx=cur;
            ans_idx=i;
        }
    }
    ans[ans_idx]=a[ans_idx];
    for(int i=ans_idx+1;i<n;++i)
    {
        ans[i]=min(ans[i-1],a[i]);
    }
    for(int i=ans_idx-1;i>=0;--i)
    {
        ans[i]=min(ans[i+1],a[i]);
    }
    for(auto &v:ans)
    {
        cout<<v<<' ';
    }
    cout<<'\n';
    return 0;
}
