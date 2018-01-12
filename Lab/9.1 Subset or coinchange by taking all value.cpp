#include<bits/stdc++.h>
#define MAX 100
using namespace std;

bool sol[MAX][MAX];
int coinval[MAX];
int n,hcost,c=0;

void select()
{
    int i=n,j=hcost;
    bool val=true;

    cout<<"\nSelected item : \n";
    while(1)
    {
        if(val!=sol[i-1][j])
        {
            cout<<"Item no "<<i<<" th value "<<coinval[i]<<endl;
            j=j-coinval[i];
            i=i-1;
        }
        else
        {
            i--;
        }
        if(i==0 || j==0)
        {
            break;
        }
    }
    printf("\n\n");
}

bool table()//using one data only one time
{
    int i,j;

    for(i=1;i<=n;i++)//column in amount of object
    {
        for(j=1;j<=hcost;j++)//row in max weight
        {
            if(coinval[i]>j)
            {
                //sol[i][j]=sol[i-1][j];
                sol[i][j]=0;//to count number of possible way
            }
            else
            {
                //sol[i][j]= sol[i-1] [j]  ||  sol[i-1] [j-coinval[i]] ;
                sol[i][j]= sol[i-1] [j-coinval[i]] ;
            }
        }
    }
    printf("\nTable: \n\nWeight\t\t");
    for(i=0;i<=hcost;i++)
    {
        cout<<i<<"\t";
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nItem   |\n");
    for(i=0;i<=n;i++)
    {
        cout<<i<<"      |";
        for(j=0;j<=hcost;j++)
        {
            cout<<"\t"<<sol[i][j];
        }
        printf("\n       |\n");
        if(sol[i][hcost]==1)
        {
            ++c;
        }
    }
    return sol[n][hcost];
}
int main()
{
    int i,j;
    bool x;
    while(scanf("%lld",&n)==1 && n>0)
    {
        cout<<"Enter Coin Value : \n";
        sol[0][0]=1;
        for(i=1;i<=n;i++)
        {
            sol[i][0]=1;
            scanf("%d",&coinval[i]);
        }
        cout<<"Enter Desired Value : \n";
        scanf("%lld",&hcost);

        x=table();
        cout<<"Number of possible way : "<<c<<endl;
        if(x==true)
        {
            select();
        }
        else
        {
            printf("\nNot possible to get desired value by all of given item.\n\n");
            if(c>0)
            {
                int i=0;
                while(i!=c)
                {
                    n=n-1;
                    if(sol[n][hcost]==1)
                    {
                        cout<<"Possible way "<<i+1<<" :"<<endl;
                        select();
                        i++;
                    }
                }
            }
        }
    }
    return 0;
}

