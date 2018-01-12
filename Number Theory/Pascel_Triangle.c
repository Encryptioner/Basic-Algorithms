#include <stdio.h>
#define MAX 250

int pascel_triangle()
{
    int a[MAX][MAX];
    int n,i,j,k;
    printf("Enter row= ");
    scanf("%d",&n);

    //taking input
    for(i=1;i<=n;i++)/*int i shows error*/
    {
        for(j=1;j<=i;j++)
        {
            if(j==1||j==i)
            {
                a[i][j]=1;
            }
            else//taking arrays value
            {
                a[i][j]=a[i-1][i-j]+a[i-1][i-j+1];

            }
        }
    }

    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n-i;k++)
        {
            printf("   ");
        }
        for(j=1;j<=i;j++)
        {
            printf("%4d ",a[i][j]);
            //printing pascal triangle
        }
        printf("\n\n");
    }

    return 0;
}
int main()
{
    pascel_triangle();
    return 0;
}

