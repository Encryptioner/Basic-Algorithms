#include<bits/stdc++.h>
#define lld unsigned long long int
#define MAX 21//all data are unique
using namespace std;

lld dp[MAX];

int main()
{
    int N,n,i,j;
    dp[0]=1;
    dp[1]=1;

    for(n=2;n<=MAX;n++)
    {
        i=0;
        j=n-1;
        //while(i!=n)
        while(i<j)
        {
            dp[n]+=2*dp[i]*dp[j];
            //cout<<n<<" "<<dp[n]<<" "<<i<<" "<<j<<endl;
            i++;
            j--;
        }
        if(i==j)
        {
            dp[n]+=dp[i]*dp[j];
        }
    }

    while(scanf("%lld",&N)==1 && N>0)
    {
        printf("Possible BST = %lld\n\n",dp[N]);
    }
    return 0;
}


