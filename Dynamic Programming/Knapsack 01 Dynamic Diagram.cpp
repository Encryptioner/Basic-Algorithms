#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int profit[MAX],weight[MAX],table[MAX][MAX],n,maxw;

int select(int val)
{
    int i=n,j=maxw;
    cout<<"\nSelected item : \n";
    while(1)
    {
        if(val!=table[i-1][j])
        {
            cout<<i<<" th"<<endl;
            j=j-weight[i];
            i=i-1;
        }
        else
        {
            i--;
        }
        if(table[i][j]==0)
        {
            break;
        }
    }
    return 0;
}

int knapsack_dp()
{
    int i,j;

    for(i=0;i<=n;i++)//column in amount of object
    {
        for(j=0;j<=maxw;j++)//row in max weight
        {
            if(i==0 || j==0)
            {
                table[i][j]=0;
            }
            else if(j<weight[i])
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                table[i][j]=max( ( profit[i]+table[i-1][j-weight[i]] ), table[i-1][j] );
            }
        }
    }
    printf("\nTable: \n\nWeight\t\t");
    for(i=0;i<=maxw;i++)
    {
        cout<<i<<"\t";
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\nItem   |\n");
    for(i=0;i<=n;i++)
    {
        cout<<i<<"      |";
        for(j=0;j<=maxw;j++)
        {
            cout<<"\t"<<table[i][j];
        }
        printf("\n       |\n");
    }
    return table[n][maxw];
}


int main()
{
    int i,j,val;

    cout << "Enter the amount of objects: ";
    cin >> n;
    cout << "Enter the weight and profit of each object:\n";

    for(i=1;i<=n;i++)
    {
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter the max weight: ";
    cin >> maxw;
    val=knapsack_dp();
    cout << "Maximum profit is " << val << endl << endl;
     select(val);
    return 0;
}
/*
4
2 3
3 4
4 5
5 6
5
*/

