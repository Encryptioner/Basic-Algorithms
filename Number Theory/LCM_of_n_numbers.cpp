#include<bits/stdc++.h>//lcm=least/lowest/smallest/minimum common multiple
using namespace std;

int lcm(int a,int b)
{
    int t,g,l,v;
    v=a*b;
    if(a==0 && b==0)
    {
        g=0;
        l=0;
    }
    else if(b==0)
    {
        g=a;
        l=0;
    }
    else if(a==0)
    {
        g=b;
        l=0;
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
        l=v/g;
    }
    return l;
}
int lcm_n()
{
    int num,a,l=0;
    printf("How Many Number? ");
    cin>>num;
    printf("\nEnter Number : \n");
    cin>>a;
    l=a;
    num--;
    while(num--)
    {
        cin>>a;
        l=lcm(l,a);
    }
    cout<<"\nLCM = "<<l<<endl;
    return 0;
}
int main()
{
    lcm_n();
    return 0;
}

