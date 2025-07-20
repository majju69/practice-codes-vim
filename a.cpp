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
    int n,m,dx[]={-1,1,0,0},dy[]={0,0,-1,1};
    cin>>n>>m;
    vector<string> str(n),ans;
    DisjointSet ds(n*m);
    for(int i=0;i<n;++i)
    {
        cin>>str[i];
    }
    for(int x=0;x<n;++x)
    {
        for(int y=0;y<m;++y)
        {
            if(str[x][y]=='.')
            {
                for(int i=0;i<4;++i)
                {
                    int r=x+dx[i],c=y+dy[i];
                    if(r>=0&&r<n&&c>=0&&c<m&&str[r][c]=='.')
                    {
                        ds.unionBySize(r*m+c,x*m+y);
                    }
                }
            }
        }
    }
    for(int x=0;x<n;++x)
    {
        string s;
        for(int y=0;y<m;++y)
        {
            if(str[x][y]=='.')
            {
                s.push_back('.');
            }
            else
            {
                int cnt=1;
                unordered_set<int> distinctComp;
                for(int i=0;i<4;++i)
                {
                    int r=x+dx[i],c=y+dy[i];
                    if(r>=0&&r<n&&c>=0&&c<m&&str[r][c]=='.')
                    {
                        distinctComp.insert(ds.findUltimateParent(r*m+c));
                    }
                }
                for(auto &v:distinctComp)
                {
                    cnt+=ds.getSize(v);
                }
                cnt%=10;
                s.push_back((char)(cnt+'0'));
            }
        }
        ans.push_back(s);
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

