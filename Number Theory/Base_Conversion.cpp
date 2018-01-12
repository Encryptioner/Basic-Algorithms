#include<bits/stdc++.h>//2 to 16
using namespace std;

int main()
{
    string s;
    long long int i,j,l,n,x;
    char base16[1000];

    while(getline(cin,s))//base1, coverting base2, number of base19(0x in first if base1>10)
    {
        l=s.length();
        if(s[0]=='0' && s[1]=='x')
        {
            j=l-3;
            n=0;
            for(i=2;i<l;i++)
            {
                if(s[i]=='A')
                {
                    x=10;
                }
                else if(s[i]=='B')
                {
                    x=11;
                }
                else if(s[i]=='C')
                {
                    x=12;
                }
                else if(s[i]=='D')
                {
                    x=13;
                }
                else if(s[i]=='E')
                {
                    x=14;
                }
                else if(s[i]=='F')
                {
                    x=15;
                }
                else
                {
                    x=s[i]-'0';
                }
                n+=x*pow(16,j);
                j--;
            }
            printf("%lld\n",n);
        }
        else
        {
            n=0;
            for(i=0;i<l;i++)
            {
                n=n*10+s[i]-'0';
            }
            if(n<=0)
            {
                if(n<0)
                {
                    break;
                }
                printf("0x0\n");
            }
            else
            {
                i=0;
                while(n>0)
                {
                    x=n%16;
                    if(x>9)
                    {
                        if(x==10)
                        {
                            base16[i]='A';
                        }
                        else if(x==11)
                        {
                            base16[i]='B';
                        }
                        else if(x==12)
                        {
                            base16[i]='C';
                        }
                        else if(x==13)
                        {
                            base16[i]='D';
                        }
                        else if(x==14)
                        {
                            base16[i]='E';
                        }
                        else
                        {
                            base16[i]='F';
                        }
                    }
                    else
                    {
                        base16[i]=x+48;
                    }
                    n=n/16;
                    i++;
                }
                printf("0x");
                for(j=i-1;j>=0;j--)
                {
                    printf("%c",base16[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
/*
Input
Each input line will consist of three values. The first value will be a positive integer indicating the base of the number.
The second value is a positive integer indicating the base we wish to convert to. The third value is the actual number (in the first base) that we wish to convert.
This number will have letters representing any digits higher than 9 and may contain invalid ``digits". It will not exceed 10 characters.
Each of the input values on a single line will be separated by at least one space.

Output
Program output consists of the original number followed by the string ``base", followed by the original base number, followed by the string ``=" followed by the converted number followed by the string ``base" followed by the new base.
If the original number is invalid, output the statement

original Value is an illegal base original Base number
where original Value is replaced by the value to be converted and original Base is replaced by the original base value.
*/

