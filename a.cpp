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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(auto &v:a)
        {
            cin>>v;
        }
        if(k<=2)
        {
            cout<<"YES\n";
        }
        else
        {
            vector<int> _a=a,tmp;
            sort(_a.begin(),_a.end());
            for(auto &v:a)
            {
                if(v<=_a[k-2])
                {
                    tmp.push_back(v);
                }
            }
            int rem=(int)tmp.size()-k+1,i=0,j=(int)tmp.size()-1;
            bool ok=1;
            while(i<j)
            {
                if(tmp[i]==tmp[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    if(rem<=0)
                    {
                        ok=0;
                        break;
                    }
                    if(tmp[i]==_a[k-2])
                    {
                        i++;
                        rem--;
                        continue;
                    }
                    if(tmp[j]==_a[k-2])
                    {
                        j--;
                        rem--;
                        continue;
                    }
                    ok=0;
                    break;
                }
            }
            cout<<(ok?"YES":"NO")<<'\n';
        }
    }
    return 0;
}
