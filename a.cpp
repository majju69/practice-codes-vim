#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif 

int get(string &s)
{
    int n=s.size(),ans=0;
    vector<int> a(n),pre(n),suf(n);
    for(int i=0;i<n;++i)
    {
        a[i]=2*(s[i]=='(')-1;
        pre[i]=a[i];
        if(i>0)
        {
            a[i]+=a[i-1];
            pre[i]=min(a[i],pre[i-1]);
        }
    }
    suf[n-1]=a[n-1];
    for(int i=n-2;i>=0;--i)
    {
        suf[i]=min(suf[i+1],a[i]);
    }
    for(int i=0;i<n;++i)
    {
        int left=((i==0)?0:a[i-1]);
        if(suf[i]>=left)
        {
            int sum=a[n-1]-left;
            ans+=((i==0)||(sum+pre[i-1]>=0));
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;
    cin>>n>>s;
    if((n&1)||(count(s.begin(),s.end(),'(')!=(n>>1)))
    {
        cout<<0<<'\n'<<"1 1\n";
    }
    else
    {
        int _i=0,_j=0,cnt=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                swap(s[i],s[j]);
                int x=get(s);
                if(x>cnt)
                {
                    cnt=x;
                    _i=i;
                    _j=j;
                }
                swap(s[i],s[j]);
            }
        }
        cout<<cnt<<'\n'<<_i+1<<' '<<_j+1<<'\n';
    }
    return 0;
}
