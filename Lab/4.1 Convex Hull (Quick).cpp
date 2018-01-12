#include<bits/stdc++.h>//ok graham scan copied
using namespace std;
int arr[1000];
int l,r,n,j,k,ind;

typedef int (*compfn)(const void*, const void*);

struct s
{
    int x;
    int y;
}p[1000],p2[1000],p1[1000],res[1000];

int orientation(s p,s q,s r)
{
    int direction=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(direction==0)
        return 0;
    if(direction>0)
        return 1;
    if(direction<0)
        return -1;
}
void find_left()
{
    l=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].x<p[l].x)
        {
            l=i;
        }
    }
}
void find_right()
{
    r=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].x>p[r].x)
            r=i;
    }
}
void build_hull()
{
    int i;
    j=0;
    k=0;
    for(i=0;i<n;i++)
    {
        if(p[i].y>p[l].y&&p[i].y>p[r].y)
        {
            //cout<<1<<endl;
            p1[j].x=p[i].x;
            p1[j].y=p[i].y;
            j++;
        }
        else
        {
            //cout<<2<<endl;
            p2[k].x=p[i].x;
            p2[k].y=p[i].y;
        }
    }
}
int compare1(struct s *elem1, struct s *elem2)
{
   if ( elem1->x < elem2->x)
      return -1;

   else if (elem1->x > elem2->x)
      return 1;

   else
      return 0;
}
int compare2(struct s *elem1, struct s *elem2)
{
   if ( elem1->x > elem2->x)
      return -1;

   else if (elem1->x < elem2->x)
      return 1;

   else
      return 0;
}
void s()
{
    qsort(p1,j,sizeof(struct s),(compfn)compare1 );
    qsort(p2,k,sizeof(struct s),(compfn)compare2 );
}
int lc=0;
int rc=0;
void hull1()
{
    int a=0,b=1,c=2;
    ind=1;
    res[ind].x=p1[0].x;
    res[ind].y=p1[0].y;
    if(lc==j-1)
        return;
    if(lc<j)
    {
        lc++;
        bool flag=1;
        if(orientation(p2[a],p2[b],p2[c])==-1)
        {
            int temp=0;
            while(temp<ind-1)
            {
                flag=0;
                if(orientation(p2[temp],p2[temp+1],p2[temp+2])==-1)
                {
                    res[ind].x=p2[temp+2].x;
                    res[ind].y=p2[temp+2].y;
                    ind++;
                }
            }
            if(flag)
            {
                if(orientation(p1[a],p1[b],p1[c])==-1)
                {
                    res[ind].x=p1[c].x;
                    res[ind].y=p1[c].y;
                    a++;
                    b++;
                    c++;
                    ind++;
                }
        }
        a++;
        b++;
        c++;
            }

            //ind++;
        }
        else
        {
            res[ind].x=p1[b].x;
            res[ind].y=p1[b].y;
            b++;
            c++;
        }
        res[ind].x=p1[j-1].x;
        res[ind].y=p1[j-1].y;
}



void hull2()
{
    int a=0,b=1,c=2;
    ind=1;
    res[ind]=p2[0];
    if(rc==k-1)
        return;
    if(rc<k)
    {
        rc++;
        bool flag=1;
        if(orientation(p2[a],p2[b],p2[c])==-1)
        {
            int temp=0;
            while(temp<ind-1)
            {
                flag=0;
                if(orientation(p2[temp],p2[temp+1],p2[temp+2])==-1)
                {
                    res[ind].x=p2[temp+2].x;
                    res[ind].y=p2[temp+2].y;
                    ind++;
                }
            }
            if(flag)
            {
                if(orientation(p1[a],p1[b],p1[c])==-1)
                {
                    res[ind].x=p1[c].x;
                    res[ind].y=p1[c].y;
                    a++;
                    b++;
                    c++;
                    ind++;
                }
        }
            }
            a++;
            b++;
            c++;
            //ind++;
        }
        else
        {
            b++;
            c++;
        }

    res[ind].x=p1[k-1].y;
    res[ind].y=p2[k-1].y;
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    find_left();
    find_right();
    //cout<<l<<" "<<r<<endl;
    build_hull();
    s();
    //build_hull();
    hull1();
    hull2();
    for(i=0;i<sizeof(res);i++)
        cout<<res[i].x<<" "<<res[i].y<<endl;
}
