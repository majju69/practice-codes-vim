#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

private:

    vector<int> ultimateParent,rank,size;

public:

    DisjointSet(int n)
    {
        ultimateParent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;++i)
        {
            ultimateParent[i]=i;
        }
    }

    int findUltimateParent(int node)
    {
        if(ultimateParent[node]==node)
        {
            return node;
        }
        return ultimateParent[node]=findUltimateParent(ultimateParent[node]);
    }

    int getSize(int node)
    {
        return size[node];
    }

    int getRank(int node)
    {
        return rank[node];
    }

    void unionByRank(int u,int v)
    {
        int ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
        if(ultimateParentOfU==ultimateParentOfV)
        {
            return ;
        }
        if(rank[ultimateParentOfU]<rank[ultimateParentOfV])
        {
            ultimateParent[ultimateParentOfU]=ultimateParentOfV;
        }
        else if(rank[ultimateParentOfU]>rank[ultimateParentOfV])
        {
            ultimateParent[ultimateParentOfV]=ultimateParentOfU;
        }
        else
        {
            ultimateParent[ultimateParentOfV]=ultimateParentOfU;
            rank[ultimateParentOfU]++;
        }
    }

    void unionBySize(int u,int v)
    {
        int ultimateParentOfU=findUltimateParent(u),ultimateParentOfV=findUltimateParent(v);
        if(ultimateParentOfU==ultimateParentOfV)
        {
            return ;
        }
        if(size[ultimateParentOfU]<size[ultimateParentOfV])
        {
            ultimateParent[ultimateParentOfU]=ultimateParentOfV;
            size[ultimateParentOfV]+=size[ultimateParentOfU];
        }
        else
        {
            ultimateParent[ultimateParentOfV]=ultimateParentOfU;
            size[ultimateParentOfU]+=size[ultimateParentOfV];
        }
    }

};

int main()
{
    int n;
    string s,t;
    vector<pair<char,char> > spells;
    DisjointSet ds(26);
    cin>>n>>s>>t;
    for(int i=0;i<n;++i)
    {
        if(ds.findUltimateParent(s[i]-'a')!=ds.findUltimateParent(t[i]-'a'))
        {
            spells.push_back(make_pair(s[i],t[i]));
            ds.unionByRank(s[i]-'a',t[i]-'a');
        }
    }
    cout<<spells.size()<<endl;
    for(int i=0;i<spells.size();++i)
    {
        cout<<spells[i].first<<' '<<spells[i].second<<endl;
    }
    return 0;
}

