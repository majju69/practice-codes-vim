#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int N=2e5+10,BLK=448;
int a[N],b[N],start1[BLK],start2[BLK];
long long sum1[BLK],sum2[BLK];

inline int get_blk(int i)
{
    return i/BLK;
}

void init(int n)
{
    for(int i=0;i<n;i+=BLK)
    {
        start1[get_blk(i)]=-1;
        start2[get_blk(i)]=-1;
    }
}

void build(int n,int k)
{
    int cur_blk=0;
    while(cur_blk<BLK)
    {
        int cur_idx=cur_blk*BLK;
        if(cur_idx>=n)
        {
            break;
        }
        long long s1=0,s2=0;
        bool ptr1=1,ptr2=1;
        for(int i=cur_idx;i<min(n,cur_idx+BLK);++i)
        {
            if(ptr1)
            {
                if(a[i]+k<b[i])
                {
                    s1+=(long long)b[i];
                    start1[cur_blk]=1;
                    ptr1=!ptr1;
                }
                else
                {
                    s1+=(long long)a[i];
                }
            }
            else
            {
                if(b[i]+k<a[i])
                {
                    s1+=(long long)a[i];
                    start1[cur_blk]=2;
                    ptr1=!ptr1;
                }
                else
                {
                    s1+=(long long)b[i];
                }
            }
            if(ptr2)
            {
                if(b[i]+k<a[i])
                {
                    s2+=(long long)a[i];
                    start2[cur_blk]=2;
                    ptr2=!ptr2;
                }
                else
                {
                    s2+=(long long)b[i];
                }
            }
            else
            {
                if(a[i]+k<b[i])
                {
                    s2+=(long long)b[i];
                    start2[cur_blk]=1;
                    ptr2=!ptr2;
                }
                else
                {
                    s2+=(long long)a[i];
                }
            }
        }
        sum1[cur_blk]=s1;
        sum2[cur_blk]=s2;
        cur_blk++;
    }
}

void update(int i,int k,int x,int t,int n)
{
    if(t==1)
    {
        a[i]=x;
    }
    else
    {
        b[i]=x;
    }
    int cur_blk=get_blk(i);
    int cur_idx=cur_blk*BLK;
    long long s1=0,s2=0;
    bool ptr1=1,ptr2=1;
    start1[cur_blk]=start2[cur_blk]=-1;
    for(int i=cur_idx;i<min(n,cur_idx+BLK);++i)
    {
        if(ptr1)
        {
            if(a[i]+k<b[i])
            {
                s1+=(long long)b[i];
                start1[cur_blk]=1;
                ptr1=!ptr1;
            }
            else
            {
                s1+=(long long)a[i];
            }
        }
        else
        {
            if(b[i]+k<a[i])
            {
                s1+=(long long)a[i];
                start1[cur_blk]=2;
                ptr1=!ptr1;
            }
            else
            {
                s1+=(long long)b[i];
            }
        }
        if(ptr2)
        {
            if(b[i]+k<a[i])
            {
                s2+=(long long)a[i];
                start2[cur_blk]=2;
                ptr2=!ptr2;
            }
            else
            {
                s2+=(long long)b[i];
            }
        }
        else
        {
            if(a[i]+k<b[i])
            {
                s2+=(long long)b[i];
                start2[cur_blk]=1;
                ptr2=!ptr2;
            }
            else
            {
                s2+=(long long)a[i];
            }
        }
    }
    sum1[cur_blk]=s1;
    sum2[cur_blk]=s2;
}

long long query(int n)
{
    int pvs=2;
    long long ans=0;
    for(int cur_blk=0;cur_blk<BLK;++cur_blk)
    {
        if(cur_blk*BLK>=n)
        {
            break;
        }
        if(pvs==2)
        {
            ans+=sum1[cur_blk];
            if(start1[cur_blk]!=-1)
            {
                pvs=start1[cur_blk];
            }
        }
        else
        {
            ans+=sum2[cur_blk];
            if(start2[cur_blk]!=-1)
            {
                pvs=start2[cur_blk];
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,k,q;
        cin>>n>>k;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        init(n);
        build(n,k);
        cin>>q;
        while(q--)
        {
            int t,i,x;
            cin>>t>>i>>x;
            i--;
            update(i,k,x,t,n);
            cout<<query(n)<<'\n';
        }
    }
    return 0;
}
