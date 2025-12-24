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
    int n,x,cur_mul=0;
    bool ok=1;
    cin>>n>>x;
    vector<int> freq(x+1,0);
    for(int i=0;i<n;++i)
    {
        int num;
        cin>>num;
        freq[num]++;
    }
    for(int i=1;i<=x;++i)
    {
        if(cur_mul%i!=0)
        {
            ok=0;
            break;
        }
        cur_mul=freq[i]+(cur_mul/i);
    }
    cout<<(ok?"Yes":"No")<<'\n';
    return 0;
}
