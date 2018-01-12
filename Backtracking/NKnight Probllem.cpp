#include<bits/stdc++.h>
using namespace std;

int pos[20],c=0;

void print(int n)
{
    int i,j;
    ++c;
    printf("\n\nSolution %d:\n\n",c);

    for(i=1;i<=n;++i)
    {
        printf("\t%d",i);
    }

    for(i=1;i<=n;++i)
    {
        printf("\n\n%d",i);
        for(j=1;j<=n;++j)
        {
            if(pos[i]==j)
            {
                printf("\tQ");
            }
            else
            {
                printf("\t-");
            }

        }
    }
    printf("\n\nSolution column :\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",pos[i]);
    }
    printf("\n\n");
}

bool place(int row,int col)
{
    int i;
    //cout<<row<<" "<<col<<endl;
    for(i=1;i<row;++i)
    {
        if(fabs(pos[i]-col)==1 && fabs(i-row)==2)
        {
            //cout<<row<<" "<<col<<" 0"<<endl;
            return 0;
        }
        else if(fabs(pos[i]-col)==2 && fabs(i-row)==1)
        {
            //cout<<row<<" "<<col<<" 0"<<endl;
            return 0;
        }
    }

    return 1;
}

void NQueen(int row,int n)
{
    int col;
    for(col=1;col<=n;++col)
    {
        //cout<<row<<" "<<col<<endl;
        if(place(row,col))
        {
            pos[row]=col;
            //cout<<"pos["<<row<<"] = "<<col<<endl;
            if(row==n)
            {
                print(n);
            }
            else
            {
                NQueen(row+1,n);
            }
        }
    }
}

int main()
{
    int n,i,j;

    while(1)
    {
        printf("Enter number of Knight : ");

        scanf("%d",&n);
        NQueen(1,n);


        printf("\n\nNumber of total solution for (n = %d) : %d\n\n\n",n,c);
        c=0;
        memset(pos,0,sizeof pos);
    }
    return 0;
}

