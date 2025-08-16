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
        int n;
        map<int,int> plus_x,plus_y;
        cin>>n;
        vector<int> x(n),y(n),xo,yo,pp,pm,mp,mm;
        for(int i=0;i<n;++i)
        {
            cin>>x[i]>>y[i];
        }
        xo=x;
        yo=y;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        for(int i=n/2;i<n;++i)
        {
            plus_x[x[i]]++;
            plus_y[y[i]]++;
        }
        for(int i=0;i<n;++i)
        {
            bool _x=0,_y=0;
            if(plus_x.count(xo[i]))
            {
                _x=1;
                plus_x[xo[i]]--;
                if(plus_x[xo[i]]==0)
                {
                    plus_x.erase(xo[i]);
                }
            }
            if(plus_y.count(yo[i]))
            {
                _y=1;
                plus_y[yo[i]]--;
                if(plus_y[yo[i]]==0)
                {
                    plus_y.erase(yo[i]);
                }
            }
            if(_x&&_y)
            {
                pp.push_back(i);
            }
            else if(_x&&!_y)
            {
                pm.push_back(i);
            }
            else if(!_x&&_y)
            {
                mp.push_back(i);
            }
            else
            {
                mm.push_back(i);
            }
        }
        while((int)pp.size()>0)
        {
            assert((int)mm.size()>0);
            cout<<pp.back()+1<<' '<<mm.back()+1<<'\n';
            pp.pop_back();
            mm.pop_back();
        }
        while((int)pm.size()>0)
        {
            assert((int)mp.size()>0);
            cout<<pm.back()+1<<' '<<mp.back()+1<<'\n';
            pm.pop_back();
            mp.pop_back();
        }
    }
    return 0;
}
