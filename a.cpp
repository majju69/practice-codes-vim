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
    int n,m,maxx=-1;
    pair<int,int> ans={-1,-1};
    cin>>n;
    vector<int> a(n);
    for(auto &v:a)
    {
        cin>>v;
    }
    cin>>m;
    vector<int> b(m);
    for(auto &v:b)
    {
        cin>>v;
    }
    maxx=2*(n-m);
    ans={2*n,2*m};
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;++i)    // a scores 3 points from i to n-1
    {
        int score_a=2*i+3*(n-i),score_b=-1;
        int d=a[i]-1;
        int idx=upper_bound(b.begin(),b.end(),d)-b.begin(); // idx....m-1 3 points 0....idx-1 2 points
        score_b=2*idx+3*(m-idx);
        if(score_a-score_b>maxx)
        {
            maxx=score_a-score_b;
            ans={score_a,score_b};
        }
        else if(score_a-score_b==maxx)
        {
            if(score_a>ans.first)
            {
                ans={score_a,score_b};
            }
        }
        else
        {
            continue;
        }
    }
    cout<<ans.first<<':'<<ans.second<<'\n';
    return 0;
}
