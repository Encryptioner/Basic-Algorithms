#include<bits/stdc++.h>
#define lld long long int
using namespace std;

int prime_factor(int num)
{
    lld n,n1,i,j,l,count,factor_size[num];
    vector<int>factor[num];
    bool negative=false;
    printf("\nEnter Number : \n");
    while(num--)
    {
    cin>>n;
    cout<<n<<" = ";
    if(n<0)
    {
        n=n*(-1);
        negative=true;
        cout<<-1<<" * ";
    }
    n1=n;
    l=sqrt(n);
    count=0;
    for(i=2;i<=l;i++)
    {
        if(i>3)//we can't give i+=2 as there is a number 2(even) prime. so to minimize number of step after getting i=2
        {
            i++;
        }
        if(n%i==0)
        {
            if(count>0)
            {
                cout<<" * ";
                count=0;
            }
            while(n%i==0)
            {
                n=n/i;
                factor[num].push_back(i);
                count++;
                if(count>1)
                {
                    cout<<" * "<<i;
                }
                else
                {
                    cout<<i;
                }
            }
        }
    }
    if(n1==n && n==1)
    {
        cout<<1<<endl;
        factor[num].push_back(1);
    }
    else if(n!=1)
    {
        if(n1!=n)
        {
            cout<<" * "<<n<<"\n";
        }
        else
        {
            cout<<n<<endl;
        }
        factor[num].push_back(n);
    }
    else
    {
        printf("\n");
    }
    negative=false;
    factor_size[num]=factor[num].size();
    }
    return 0;
}

int main()
{
    int num;
    printf("How Many Number? ");
    cin>>num;
    prime_factor(num);
    return 0;
}

