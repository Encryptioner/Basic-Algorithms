#include<bits/stdc++.h>//gcd=greatst/highest common divisor(hcd)=highest common factor(hcf)=greatest common measure(gcm)=
using namespace std;

int gcd(int a,int b)
{
    int t,g;
    if(a==0 && b==0)//not approved in gcd definition
    {
        g=0;
    }
    else if(b==0)
    {
        g=a;
    }
    else if(a==0)
    {
        g=b;
    }
    else
    {
        while(a!=0)
        {
            t=a;
            a=b%a;
            b=t;
        }
        g=b;
    }
    return g;
}
int gcd_n()
{
    int num,a,g=0;
    printf("How Many Number? ");
    cin>>num;
    printf("\nEnter Number : \n");
    while(num--)
    {
        cin>>a;
        g=gcd(g,a);
    }
    cout<<"\nGCD = "<<g<<endl;
    return 0;
}
int main()
{
    gcd_n();
    return 0;
}
