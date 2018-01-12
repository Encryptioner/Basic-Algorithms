#include<bits/stdc++.h>
#define lld unsigned long long int
#define MAX 92
using namespace std;

bool vis[MAX];
lld dp[MAX];


lld fibonacci(lld n)
{
    if(n==0)
    {
       return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else if(vis[n]!=0)
    {
        return dp[n];
    }
    else
    {
        dp[n]=fibonacci(n-1)+fibonacci(n-2);
        vis[n]=1;
        return dp[n];
    }
}

int main()
{
    lld n;
    while(scanf("%lld",&n)==1 && n>=0)
    {
        printf("\n%lld th fibonacci number is %lld\n\n",n,fibonacci(n));
        memset(vis,0,sizeof vis);
    }

    return 0;
}
