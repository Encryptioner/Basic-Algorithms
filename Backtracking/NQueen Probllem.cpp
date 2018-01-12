#include<bits/stdc++.h>//by how many way n queens can be set in n*n chessboard
#define MAX 20
using namespace std;

int pos[MAX],c=0;
void output(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("output %d \n",pos[i]);
    }
    printf("\n");
    ++c;
}
bool place(int k,int i)
{
    cout<<"p "<<k<<" "<<i<<endl;
    int j;
    for(j=0;j<=k;j++)
    {
        //cout<<j<<" "<<pos[j]<<" "<<fabs(pos[j]-i)<<endl;
        if( pos[j]==i || fabs(pos[j]-i)==fabs(k-j) )
        {
            //cout<<"false\n\n";
            return false;
        }
    }
    return true;
}
void nqueen(int k,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(place(k,i))
        {
            pos[k]=i;
            //cout<<k<<" "<<i<<" n = "<<n<<endl<<endl;
            if(k==n-1)
            {
                output(n);
            }
            else
            {
                nqueen(k+1,n);
            }
        }
    }
}
int main()
{
    int k=0,n;
    while(1){
    printf("Enter number of dimension : ");
    scanf("%d",&n);

    nqueen(k,n);
    printf("number of total combination : %d\n\n",c);
    c=0;
    memset(pos,0,sizeof pos);
    }
    return 0;
}
