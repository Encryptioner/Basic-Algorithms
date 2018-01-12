#include<bits/stdc++.h>
#define MAXC 1000

using namespace std;

int lenA,lenB;
char A[MAXC],B[MAXC];

int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];
string ans;

int calcLCS(int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0')
    {
        return 0;
    }
	if(visited[i][j])
    {
        return dp[i][j];
    }

	int ans=0;
	if(A[i]==B[j])
    {
        ans=1+calcLCS(i+1,j+1);
    }
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		ans=max(val1,val2);
	}
	visited[i][j]=1;
	dp[i][j]=ans;
	return dp[i][j];
}

string printall(int i,int j)
{
    if(A[i]=='\0' ||  B[j]=='\0')
    {
        cout<<ans<<endl;
        return ans;
    }
    if(A[i]==B[j])
    {
        ans+=A[i];
        printall(i+1,j+1);
        ans.erase(ans.end()-1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
        {
            printall(i+1,j);
        }
        if(dp[i+1][j]<dp[i][j+1])
        {
            printall(i,j+1);
        }
        else
        {
            printall(i+1,j);
            printall(i,j+1);
        }
    }
}

int main() {
	scanf("%s%s",A,B);

	lenA=strlen(A);
	lenB=strlen(B);
	printf("%d\n",calcLCS(0,0));

	for(int i=0;i<lenA;i++)
    {
        for(int j=0;j<lenB;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        printf("\n");
    }

	//printall(0,0);

	return 0;
}
