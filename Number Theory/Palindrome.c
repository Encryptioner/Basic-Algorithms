#include <stdio.h>//palindrome of number by reversing

int reverse(int n)
{
    int a=0,b;
    while(n>0)
    {
        b=n%10;
        a=a*10+b;
        n=n/10;
    }
    return a;
}
int Palindrome(int num)
{
    int rev=reverse(n);
    printf("\n%d\n\n",rev);
    if(rev==num)
    {
        printf("palindrome\n");
    }
    else
    {
        printf("not palindrome\n");
    }
}

int main()
{
    int n;
    printf("Enter number = ");
    while(scanf("%d",&n)==1)
    {
        Palindrome();
    }
    return 0;
}
