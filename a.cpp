#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=5e4+10;

struct cmp_table
{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b) const
    {
        int sa=a.first+a.second,sb=b.first+b.second;
        if(sa!=sb)
        {
            return sa<sb;
        }
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};

struct cmp_cell
{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b) const
    {
        int sa=a.first+a.second+2*(a.first%3==2&&a.second%3==2),sb=b.first+b.second+2*(b.first%3==2&&b.second%3==2);
        if(sa!=sb)
        {
            return sa<sb;
        }
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        return a.second<b.second;
    }
};

set<pair<int,int>,cmp_table> table;
set<pair<int,int>,cmp_cell> cell;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int sum=0;sum<=N;++sum)
    {
        if((int)table.size()>N)
        {
            break;
        }
        for(int x=0;x<=sum;++x)
        {
            if((int)table.size()>N)
            {
                break;
            }
            table.insert({3*x+1,3*(sum-x)+1});
            cell.insert({3*x+1,3*(sum-x)+1});
            cell.insert({3*x+2,3*(sum-x)+1});
            cell.insert({3*x+1,3*(sum-x)+2});
            cell.insert({3*x+2,3*(sum-x)+2});
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> rm_table,rm_cell;
        while(n--)
        {
            int t;
            cin>>t;
            if(t==0)
            {
                auto it=table.begin();
                pair<int,int> p=*it;
                table.erase(it);
                cell.erase(p);
                rm_table.push_back(p);
                rm_cell.push_back(p);
                cout<<p.first<<' '<<p.second<<'\n';
            }
            else
            {
                auto it=cell.begin();
                pair<int,int> p=*it;
                cell.erase(it);
                rm_cell.push_back(p);
                pair<int,int> tmp={3*(p.first/3)+1,3*(p.second/3)+1};
                if(table.find(tmp)!=table.end())
                {
                    table.erase(tmp);
                    rm_table.push_back(tmp);
                }
                cout<<p.first<<' '<<p.second<<'\n';
            }
        }
        for(auto &v:rm_cell)
        {
            cell.insert(v);
        }
        for(auto &v:rm_table)
        {
            table.insert(v);
        }
    }
    return 0;
}
