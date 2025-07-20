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
    int r,g,b,ans=0;
    string ord="rgbm";
    cin>>r>>g>>b;
    sort(ord.begin(),ord.end());
    do
    {
        int tmp_r=r,tmp_g=g,tmp_b=b,cur_ans=0;
        for(auto &v:ord)
        {
            if(v=='r')
            {
                cur_ans+=(tmp_r/3);
                tmp_r%=3;
            }
            else if(v=='g')
            {
                cur_ans+=(tmp_g/3);
                tmp_g%=3;
            }
            else if(v=='b')
            {
                cur_ans+=(tmp_b/3);
                tmp_b%=3;
            }
            else
            {
                int minn=min({tmp_b,tmp_g,tmp_r});
                cur_ans+=minn;
                tmp_r-=minn;
                tmp_g-=minn;
                tmp_b-=minn;
            }
        }
        ans=max(cur_ans,ans);
    }while(next_permutation(ord.begin(),ord.end()));
    cout<<ans<<'\n';
    return 0;
}
