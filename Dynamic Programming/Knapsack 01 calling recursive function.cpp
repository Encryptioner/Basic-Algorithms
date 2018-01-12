#include<bits/stdc++.h>
#define MAX_N 100
#define MAX_W 1000
using namespace std;

int n,CAP;
bool vis[MAX_N+1][MAX_W+1];
int dp[MAX_N+1][MAX_W+1];
int weight[MAX_N+1] , cost[MAX_N+1];

int func(int i,int w)
{
	int profit1=0,profit2=0;

	if(i==n+1)
    {
        return 0; //সব কিছু নেয়া হয়ে গেছে
    }
	if(vis[i][w]!=0)
    {
        return dp[i][w]; //এই স্টেটটা আগেই হিসাব করে এসেছি
    }
	if(w+weight[i]<=CAP)
    {
        profit1=cost[i]+func(i+1,w+weight[i]);//যদি i তম জিনিসটা নেয়া যায় তাহলে লাভের পরিমাণ profit1, //if same item is taken more than one time  profit2=func(i,w);
    }

	profit2=func(i+1,w); //যদি জিনিসটা না নেই তাহলে লাভ profit2 , //যদি CAP এর থেকে বড় হয় তাহলে iনেয়া সম্ভবনা। i যদি না নেই তাহলে আমরা পরবর্তী i+1 e চলে যাবো:
	dp[i][w]=max(profit1,profit2); //বেশি লাভ যেটায় হবে সেটাই আমরা নিবো
	vis[i][w]=1;
	return dp[i][w];
}
int main()
{
	//freopen("Knapsack 01 calling recursive function.txt","r",stdin);
	while(scanf("%d %d",&n,&CAP)==2 && n>0)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&weight[i],&cost[i]);

        }
        printf("%d\n",func(1,0));//func(1,0) কল করার কারণ হলো শুরুতে তুমি ১ নম্বর জিনিসটা নিয়ে ট্রাই করবে এবং শুরুতে ব্যাগে সম্পূর্ণ খালি
    }
	return 0;
}

/*
4 10 //4 টা জিনিস, ১০ ক্যাপাসিটি
1 120 //প্রতিটা জিনিসের ওজন এবং দাম
4 280
3 150
4 200
*/
