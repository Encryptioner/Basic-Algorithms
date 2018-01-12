#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n;
    n=7;
    /*int A[n][n]={
        {0,3,-5,64},
        {2,0,2,79},
        {7,5,0,89},
        {20,52,8,0}
        };
        */
        int A[n][n]={
        {0,4,5,64,64,64,64},
        {64,0,64,6,64,64,64},
        {7,5,0,89},
        {20,52,8,0}
        };

        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(A[i][j]>A[i][k]+A[k][j])
                    {
                        A[i][j]=A[i][k]+A[k][j];
                    }
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<A[i][j]<<" ";
            }
            printf("\n\n");
        }
        return 0;
}
