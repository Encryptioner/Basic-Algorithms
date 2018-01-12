#include<bits/stdc++.h>//ok
#define lld long long int
using namespace std;

#define MX 100001
vector<lld>arr(MX),tree(4*MX);

void insert_update(lld node, lld b, lld e, lld pos, lld value)
{
    if(b == pos && pos == e)
    {
        tree[node] = value;
        return;
    }

    lld l = node<<1;
    lld r = l + 1;
    lld mid = (b+e)>>1;

    if(pos <= mid)
    {
        insert_update(l, b, mid, pos, value);
    }
    else
    {
        insert_update(r, mid+1, e, pos, value);
    }
    tree[node] = min(tree[l] , tree[r]);//or max
    //tree[node] = tree[l] + tree[r];
}

lld query(lld node, lld b, lld e, lld i, lld j)
{
    if(i==b && j==e)
    {
        return tree[node];
    }

    lld l = node<<1;
    lld r = l + 1;
    lld mid = (b+e)>>1;

    if(j<=mid)
    {
        return query(l, b, mid, i, j);
    }
    else if(i > mid)
    {
        return query(r, mid+1, e, i, j);
    }
    else
    {
        return min(query(l, b, mid, i, mid) , query(r, mid+1, e, mid+1, j));// or max
        //return query(l, b, mid, i, mid) + query(r, mid+1, e, mid+1, j);
    }
}

int main()
{
    lld t,N,q,i,j,x,y,c=0,minimum;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&N,&q);

        for(i=1;i<=N;i++)
        {
            scanf("%d",&arr[i]);
            insert_update(1, 1, N, i, arr[i]);//adds value arr[i] in i'th position, previous value was zero
        }
        printf("Case %lld:\n",++c);
        while(q--)
        {
            scanf("%lld %lld",&x,&y);//min, max, sum of value no x to y; counting started from 1
            minimum=query(1,1,N,x,y);
            printf("%lld\n",minimum);
        }
        arr.clear();
        tree.clear();
    }
    return 0;
}
