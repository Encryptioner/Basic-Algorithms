#include <bits/stdc++.h>//ok
#define lld long long int
using namespace std;

#define mx 100009
lld arr[mx];
struct info
{
    int prop,sum;
}tree[mx*3];

void init(lld node,lld b,lld e)
{
    if(b==e)
    {
        tree[node].sum=arr[b];
        return;
    }
    lld Left=node<<1;
    lld Right=Left+1;
    lld mid=(b+e)>>1;

    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node].sum=min(tree[Left].sum,tree[Right].sum);//finding min
    //tree[node].sum=tree[Left].sum+tree[Right].sum;//to find sum but it needs differnt query and update too
}

lld query(lld node,lld b,lld e,lld i,lld j,lld carry)
{
    if(i==b && j==e)
    {
        return tree[node].sum+carry*(e-b+1);
    }
    lld Left=node<<1;
    lld Right=Left+1;
    lld mid=(b+e)>>1;

    if(j<=mid)
    {
        return query(Left, b, mid, i, j, carry+tree[node].prop);
    }
    else if(i > mid)
    {
        return query(Right, mid+1, e, i, j, carry+tree[node].prop);
    }
    else
    {
        return min(query(Left, b, mid, i, mid, carry+tree[node].prop) , query(Right, mid+1, e, mid+1, j, carry+tree[node].prop));
    }
}

void update(lld node,lld b,lld e,lld i,lld j,lld x)
{
    if (i > e || j < b)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        tree[node].sum+=(x);//as we are only concern about a single value which is min
        tree[node].prop+=x;
        return;
    }
    lld Left=node<<1;
    lld Right=Left+1;
    lld mid=(b+e)>>1;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node].sum=min((tree[Left].sum+tree[node].prop),(tree[Right].sum+tree[node].prop));
}
int main()
{
    lld t,N,q,i,j,x,y,v,task,c=0,minimum,val;

    t=3%7;
    cout<<t<<endl;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&N,&q);

        for(i=1;i<=N;i++)
        {
            scanf("%lld",&arr[i]);
        }
        init(1,1,N);
        printf("Case %lld:\n",++c);
        while(q--)
        {
            scanf("%lld",&task);
            if(task==1)
            {
                scanf("%lld %lld %lld",&i,&j,&v);//in i to j position add value
                update(1,1,N,i,j,v);
            }
            else if(task==2)//find minimum
            {
                scanf("%lld %lld",&i,&j);
                val=query(1,1,N,i,j,0);
                printf("Minimum =  %lld\n",val);
            }

        }
        memset(arr,0,sizeof arr);
        for(i=0;i<mx*3;i++)
        {
			tree[i].sum=0;
			tree[i].prop=0l;
		}
    }
    return 0;
}
