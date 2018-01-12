#include<bits/stdc++.h>
#define MAX 100
using namespace std;

char A[MAX],B[MAX];
int sol[MAX][MAX];

int lenA,lenB,c=0;

int table()//using one data only one time
{
    int i,j;

    for(i=0;i<lenA;i++)//column in amount of object
    {
        bool x=false;
        for(j=0;j<lenB;j++)//row in max weight
        {
            if(i==0)
            {
                if(A[i]==B[j])
                {
                    sol[i][j]=1;
                }
                else if(j!=0)
                {
                    sol[i][j]= sol[i][j-1];
                }
                continue;
            }
            if(j==0)
            {
                sol[i][j]=sol[0][0];
                continue;
            }
            if(A[i]==B[j])
            {
                sol[i][j]=sol[i][j-1]+1;
                x=true;
            }
            else if(x==true)
            {
                sol[i][j]=sol[i][j-1];
            }
            else
            {
                sol[i][j]=sol[i-1][j];
            }
        }
    }
    printf("\nTable: \n\nString 1 \t");
    for(i=0;i<lenB;i++)
    {
        cout<<A[i]<<"\t";
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nString 2   |\n");
    for(i=0;i<lenA;i++)
    {
        cout<<i<<"      |";
        for(j=0;j<lenB;j++)
        {
            cout<<"\t"<<sol[i][j];
        }
        printf("\n       |\n");
    }
    return sol[lenA-1][lenB-1];
}
int main()
{
    int i,j;
    int x;
    while(scanf("%s %s",&A,&B)==2)
    {
        cout<<"Enter Coin Value : \n";
        lenA=strlen(A);
        lenB=strlen(B);

        x=table();
        cout<<"\nLCS = "<<x<<endl;
    }
    return 0;
}


