#include<bits/stdc++.h>
using namespace std;

int brute_force(int n,int m,int w[],int p[])
{
    clock_t start=clock();
    double time;

    int i,j,k,l,c=0,MAX1,MAX=0,v,count=0,a,b;
    int x=pow(2,n);
    int valw[500]={0},valp[500]={0},bin[n];
    valw[c]=0;
    valp[c]=0;
    c++;
    for(i=1;i<x;i++)
    {
        v=i;
        a=0;
        while(v!=0)
        {
            bin[a]=v%2;
            v=v/2;
            a++;
        }
        count=n;
        for(j=0;j<a;j++)
        {
            count--;
            //cout<<bin[j];
            if(bin[j]==1)
            {
                valw[c]+=w[count];
                valp[c]+=p[count];
            }
        }
        if(valp[c]>MAX && valw[c]<=m)
        {
            MAX=valp[c];
            MAX1=c;
        }
        c++;
    }
    /*c=0;
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            for(k=0;k<=1;k++)
            {
                for(l=0;l<=1;l++)
                {
                    cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<valw[c]<<" "<<valp[c]<<endl;
                    if(valp[c]>MAX && valw[c]<=m)
                    {
                        MAX=valp[c];
                        MAX1=c;
                    }
                    c++;
                }
            }
        }
    }*/
    cout<<"\nMaximum point index = "<<MAX1<<"(Converet it to decimal for n object)"<<endl;
    v=MAX1;
    a=0;
    while(v!=0)
    {
        bin[a]=v%2;
        v=v/2;
        a++;
    }
    count=n;
    for(j=0;j<a;j++)
    {
        count--;
        if(bin[j]==1)
        {
            cout<<p[count]<<" "<<w[count]<<endl;
        }
    }
    printf("\n");
    cout<<"Maximum Profit position Under constraints  "<<MAX<<endl;
    cout<<"Maximum profit obtained when weight = "<<valw[MAX1]<<endl<<endl;

    clock_t stop=clock();
    time=((double)(stop-start))/CLOCKS_PER_SEC;
    cout<<time<<endl;
    return 0;
}
int main()
{
    int i,n,m,w[100],p[100];

    cout<<"Enter number of object : ";
    cin>>n;
    cout<<"Enter maximum weight : ";
    cin>>m;
    //n=4;
    cout<<"Enter weight and it's profit :\n";
    for(i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }
    brute_force(n,m,w,p);
    return 0;
}

