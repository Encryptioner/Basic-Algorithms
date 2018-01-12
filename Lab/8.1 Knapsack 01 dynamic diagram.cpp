#include <bits/stdc++.h>
#define MAX 201

using namespace std;

int profit[MAX],weight[MAX],table[MAX][MAX],n,maxw;

int select(int val)
{
    int i=maxw,j=n;
    cout<<"\nSelected item : \n";
    while(1)
    {
        if(val!=table[i][j-1])
        {
            cout<<j<<" th"<<endl;
            i=i-weight[j];
            j=j-1;
        }
        else
        {
            j--;
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

    for(i=0;i<=maxw;i++)//row in max weight
    {
        for(j=0;j<=n;j++)//column in amount of object
        {
            if(i==0 || j==0)
            {
                table[i][j]=0;
            }
            else if(i<weight[j])
            {
                table[i][j]=table[i][j-1];
            }
            else
            {
                table[i][j]=max( ( profit[j]+table[i-weight[j]][j-1] ), table[i][j-1] );
            }
        }
    }
    printf("\nTable: \n\nItem\t\t");
    for(i=0;i<=n;i++)
    {
        cout<<i<<"\t";
    }
    printf("\n------------------------------------------------------");
    printf("\nWeight |\n");
    for(i=0;i<=maxw;i++)
    {
        cout<<i<<"      |";
        for(j=0;j<=n;j++)
        {
            cout<<"\t"<<table[i][j];
        }
        printf("\n       |\n");
    }
    return table[maxw][n];
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
