#include<bits/stdc++.h>
#define MAX 7501
#define N 6
using namespace std;

//int coin[]={5,8,11,15,18}; //value of coins available
int coin[]={50,25,10,5,1}; //value of coins available
int make,c=0; //our target value
int dp[N][MAX];
int call(int i,int amount)
{	cout<<i<<" "<<amount<<" "<<c<<endl;
	if(i>=5) {   //All coins have been taken
		if(amount==make){c=c+1;cout<<"c = "<<c<<endl; return 1;}
		else return 0;
	}
	if(dp[i][amount]!=-1) {cout<<"Stored "<<i<<" "<<amount<<" "<<dp[i][amount]<<endl;return dp[i][amount];} //no need to calculate same state twice
	int ret1=0,ret2=0;
	if(amount+coin[i]<=make) {ret1=call(i,amount+coin[i]);cout<<"Here "<<i<<" "<<amount<<endl;
	}//try to take coin i
	ret2=call(i+1,amount); cout<<"Here2 "<<i<<" "<<amount<<endl;
	//}//dont take coin i
	cout<<i<<" "<<amount<<" "<<ret1<<"  "<<ret2<<endl;
	//return dp[i][amount]=ret1|ret2; //storing and returning.
    return dp[i][amount]=ret1+ret2;//number of possible way to make desired value
}
int main()
{
//	freopen("in","r",stdin);
	while(cin>>make)
	{
		memset(dp,-1,sizeof(dp));
		cout<<"val = "<<call(0,0)<<" count = "<<c<<endl;
		cout<<"count = "<<c<<endl<<endl;//watch counts value
	}
    return 0;
}

/*
//Better alternative when coin[] is constant for all test case
#include<bits/stdc++.h>
#define MAX 7501
#define N 5
using namespace std;

int coin[]={50,25,10,5,1};
int dp[N][MAX];
int make,c=0;

int call(int i,int amount)
{
	cout<<i<<" "<<amount<<endl;
	if(i>=N)
    {
		if(amount==0)
		{
		    c=c+1;cout<<"c = "<<c<<endl;
		    return 1;
        }
		else
        {
            cout<<"return = 0"<<endl;
            return 0;
        }
	}
	if(dp[i][amount]!=-1)
    {
        cout<<"Stored "<<i<<" "<<amount<<" "<<dp[i][amount]<<endl;
        return dp[i][amount];
    }
    int ret1=0,ret2=0;
	if(amount-coin[i]>=0)
    {
        ret1=call(i,amount-coin[i]);
        cout<<"Here "<<i<<" "<<amount<<endl;
	}
	ret2=call(i+1,amount);
	cout<<"Here2 "<<i<<" "<<amount<<endl;
	cout<<"............. "<<i<<" "<<amount<<" "<<ret1<<"  "<<ret2<<endl;
    return dp[i][amount]=ret1+ret2;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&make)==1)
	{
		printf("%d\n",call(0,make));
		for(int i=0;i<N;i++)
        {
            for(int j=0;j<=make;j++)
            {
                cout<<dp[i][j]<<"  ";
            }
            printf("\n\n");
        }
	}
    return 0;
}
*/
