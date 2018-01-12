#include<bits/stdc++.h>//ok
#define MAX 500
using namespace std;
int c1=0,c2=0,count1[MAX],count2[MAX];
void traverse_maxheap(int c[],int q,int y,int data[])
{
    int tmp,tmp1,a;

    tmp = c[q];
    tmp1= data[q];
    //cout<<"\ntmp= "<<tmp<<endl;
    a = 2*q;
    while(a<= y)
    {
        if(a < y && c[a+1] > c[a])
            a= a+1;
        if(tmp > c[a])
            break;
        else if(tmp <= c[a])
        {
            c[a/2] = c[a];
            c1++;
            data[a/2]=data[a];
            a = a*2;
        }
    }
    c[a/2] = tmp;
    data[a/2]=tmp1;
    return;
}

void insert_maxheap(int b[],int x,int data[])
{
    int p;
    for(p=x/2;p>=1;p--)
    {
        traverse_maxheap(b,p,x,data);
    }
}
void show(int a[],int m,int data[])
{
    int i;
    count1[m]=c1;
    c1=0;
    cout<<endl;
    for(i=1;i<=m;i++)
    {
        cout<<i<<". "<<a[i]<<"  "<<data[i]<<"  "<<count1[i]<<endl;
    }
}

int main()
{
    int data[MAX],a[MAX],i,num,n = 0,x;
    cout<<"Enter the total elements: ";
    cin>>x;
    for(i=1;i<=x;i++)
    {
        data[i]=rand();
        a[i]=i;
        cout<<"\ndata ["<<i<<"] = "<<data[i]<<endl;
        n=i;
        insert_maxheap(a,n,data);
        show(a,n,data);
    }
    return 0;
}
