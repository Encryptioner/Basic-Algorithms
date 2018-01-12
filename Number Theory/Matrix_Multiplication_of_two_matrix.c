#include <stdio.h>
#define MAX 100
int main()
{
    int r1,r2,c1,c2,n,i,j,k;
    int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
    printf("How many rows in a= ");
    scanf("%d",&r1);
    printf("How many columns in a= ");
    scanf("%d",&c1);
    printf("How many rows in b= ");
    scanf("%d",&r2);
    printf("How many columns in b= ");
    scanf("%d",&c2);
    if(c1==r2)
    {
        printf("\nNow,Input a\n");
        for(i=0;i<r1;++i)
        {
            printf("row %d :\n",i+1);
            for(j=0;j<c1;++j)
                scanf("%d",&a[i][j]);
        }
        printf("\nNow, Input b\n");
        for(i=0;i<r2;++i)
        {
            printf("row %d :\n",i+1);
            for(j=0;j<c2;++j)
                scanf("%d",&b[i][j]);
        }
        for(i=0;i<r1;++i)
        {
            for(j=0;j<c2;++j)
            {
                c[i][j]=0;
                for(k=0;k<c1;++k)
                {
                    c[i][j]=a[i][k]*b[k][j]+c[i][j];
                }
            }
        }
        printf("Now, multiplication= \n\n");
        for(i=0;i<r1;++i)
        {
            for(j=0;j<c2;++j)
            {
                printf("\t%4d\t",c[i][j]);
            }
        }
    }
    else
    {
        printf("\nSyntax Error\n");
    }
    return 0;
}

