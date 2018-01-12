#include<bits/stdc++.h>
#define lld long long int
using namespace std;

int Leap_Year()
{
    string n;
    lld leap,a,b,c,i,l,x;
    int print=0;

    while(cin>>n)
    {
        if(print!=0)
        {
            printf("\n");
        }
        print=1;

        leap=x=a=b=c=0;

        l=n.length();

        for(i=0;i<l;i++)
        {
            a=((a*10)+(n[i]-'0'))%4;
            b=((b*10)+(n[i]-'0'))%100;
            c=((c*10)+(n[i]-'0'))%400;
        }

        if((a==0 && b!=0) || c==0)
        {
            printf("This is leap year.\n");
            leap = 1;
            x = 1;
        }
        if(x==0)
        {
            printf("This is an ordinary year.\n");
        }
    }
    return 0;
}
int main()
{
    Leap_Year();
    return 0;
}

