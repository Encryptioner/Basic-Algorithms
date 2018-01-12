#include<bits/stdc++.h>//not
#define MAX 10000
using namespace std;
int arr[MAX];
//int l,r,n,j,k,ind;
int n;
int Hull(struct s X[],int len,int a1,int a2,int b1,int b2);

struct s
{
    int x;
    int y;
}p[MAX],p1[MAX],p2[MAX],H1[MAX],H2[MAX],u[MAX];

int find_left()
{
    int l=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].x<p[l].x)
        {
            l=i;
        }
    }
    return l;
}
int find_right()
{
    int r=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].x>p[r].x)
            r=i;
    }
    return r;
}
int Quick_Hull()
{
    int i,l,r,j,k;

    l=find_left();
    r=find_right();
    cout<<"Lowest & Highest Point : "<<endl;
    cout<<l<<" "<<p[l].x<<" "<<p[l].y<<endl;
    cout<<r<<" "<<p[r].x<<" "<<p[r].y<<endl;
    struct s X1[MAX],X2[MAX];
    j=0;
    k=0;
    for(i=0;i<n;i++)
    {
        if( (p[r].x-p[l].x)*(p[i].y-p[l].y) - (p[r].y-p[l].y)*(p[i].x-p[l].x)  == 0 )
        {
            continue;
        }
        else if( (p[r].x-p[l].x)*(p[i].y-p[l].y) - (p[r].y-p[l].y)*(p[i].x-p[l].x)  > 0 )
        {
            X1[j].x=p[i].x;
            X1[j].y=p[i].y;
            cout<<"left = "<<X1[j].x<<" "<<X1[j].y<<endl;
            j++;
        }
        else
        {
            X2[k].x=p[i].x;
            X2[k].y=p[i].y;
            cout<<"right = "<<X2[k].x<<" "<<X2[k].y<<endl;
            k++;
        }
    }
    cout<<"Lowest & Highest Point : "<<endl;
    cout<<l<<" "<<p[l].x<<" "<<p[l].y<<endl;
    cout<<r<<" "<<p[r].x<<" "<<p[r].y<<endl;
    Hull(X1,j, p[l].x, p[l].y, p[r].x, p[r].y);
    Hull(X2,k, p[r].x, p[r].y, p[l].x, p[l].y);

}

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    cout<<sizeof(p)/sizeof(p[0])<<endl;
    Quick_Hull();
    //main();
    return 0;
}

int Hull(struct s X[],int len,int a1,int a2,int b1,int b2)
{
    cout<<"Lowest & Highest Point : "<<endl;
    cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
    if(a1>b1)
    {
        swap(a1,b1);
        swap(a2,b2);
        cout<<"swapping 1\n";
    }
    int i,h=0,j=0,k=0;
    double a,b,c,s,area,max=0,v1,v2;
    struct s X1[MAX],X2[MAX];

    a=(b1-a1)*(b1-a1) + (b2-a2)*(b2-a2);
    a=sqrt(a);
    cout<<"a = "<<a<<endl;
    cout<<len<<endl;
    for(i=0;i<len;i++)
    {
        b=(b1-X[i].x)*(b1-X[i].x) + (b2-X[i].y)*(b2-X[i].y);
        b=sqrt(b);
        cout<<"b = "<<b<<endl;
        c=(a1-X[i].x)*(a1-X[i].x) + (a2-X[i].y)*(a2-X[i].y);
        c=sqrt(c);
        cout<<"c = "<<c<<endl;
        s=(a+b+c)/2;
        area=(s*(s-a)*(s-b)*(s-c));

        cout<<area<<endl;
        if(area>max)
        {
            max=area;
            h=i;
            cout<<h<<endl;
        }
    }
    cout<<"max area = "<<max<<" point index = "<<h<<endl;
    cout<<"maximum point = "<<X[h].x<<" "<<X[h].y<<endl<<endl;
    if(a1>X[h].x)
    {
        swap(a1,X[h].x);
        swap(a2,X[h].y);
        cout<<"swapping 2\n";
    }
    if(a1>X[h].x)
    {
        swap(a1,X[h].x);
        swap(a2,X[h].y);
        cout<<"swapping 2\n";
    }
    for(i=0;i<len;i++)
    {
        cout<<"\n\n"<<X[i].x<<" "<<X[i].y<<endl;
        v1=(X[h].x-a1)*(X[i].y-a2) - (X[h].y-a2)*(X[i].x-a1);
        v2=(X[h].x-b1)*(X[i].y-b2) - (X[h].y-b2)*(X[i].x-b1);
        cout<<"Inside 1 : "<<v1<<endl;
        cout<<"Inside 2 : "<<v2<<endl;
        if( v1  == 0 )
        {
            continue;
        }
        else if( v1  > 0 )
        {
            X1[j].x=X[i].x;
            X1[j].y=X[i].y;
            cout<<"left = "<<X1[j].x<<" "<<X1[j].y<<endl;
            j++;
        }
        //else if( (b1-X[h].x)*(X[i].y-X[h].y) - (b2-X[h].y)*(X[i].x-X[h].x)  > 0 )
        else if( v2  < 0 )
        {
            X2[k].x=X[i].x;
            X2[k].y=X[i].y;
            cout<<"right = "<<X2[k].x<<" "<<X2[k].y<<endl;
            k++;
        }
    }
    if(j>0)
    {
        Hull(X1,j, a1, a2, X[h].x, X[h].y);
    }
    if(k>0)
    {
        Hull(X2,k, X[h].x, X[h].y, b1, b2);
    }
}
