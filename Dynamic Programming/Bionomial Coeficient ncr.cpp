#include<bits/stdc++.h>
#define ulld unsigned long long
#define MAX 66
using namespace std;

bool vis[MAX][MAX/2];
ulld dp[MAX][MAX/2];

ulld ncr(ulld n,ulld r)
{
    if(r==0 || r==n)
    {
        return 1;
    }
    else if(r==1 || r==n-1)
    {
        return n;
    }
    else if(vis[n][r]!=0)
    {
        return dp[n][r];
    }
    else
    {
        dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
        vis[n][r]=1;
        return dp[n][r];
    }
}
int main()
{
    ulld n,r;
    while(scanf("%llu %llu",&n,&r)==2 && r<=n)
    {
        if(r > n / 2){ r = n - r;}// because C(n, r) == C(n, n - r)

        printf("\n%I64lluC%llu = %llu\n\n",n,r,ncr(n,r));

        memset(vis,0,sizeof vis);
    }

    return 0;
}
