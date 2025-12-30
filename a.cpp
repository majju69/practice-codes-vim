#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

typedef long long ll;

const ll base=10;

char get(ll x)
{
    return (char)((x%base)+'0');
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
        ll n,carry=0,sum=0;
        string s,ans;
        vector<ll> cnt(10,0);
        cin>>n>>s;
        reverse(s.begin(),s.end());
        while(s.back()=='0')
        {
            s.pop_back();
            n--;
        }
        reverse(s.begin(),s.end());
        for(auto &v:s)
        {
            cnt[v-'0']++;
        }
        for(ll i=n-1;i>=0;--i)
        {
            sum=carry;
            for(ll j=1;j<10;++j)
            {
                sum+=j*cnt[j];
            }
            if(i>0)
            {
                ans.push_back(get(sum));
                carry=sum/base;
                sum=0;
                cnt[s[i]-'0']--;
            }
            else
            {
                string tmp=to_string(sum);
                reverse(tmp.begin(),tmp.end());
                for(auto &v:tmp)
                {
                    ans.push_back(v);
                }
            }
        }
        while((ll)ans.size()>0&&ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<'\n';
    }
    return 0;
}
