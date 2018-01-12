#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int G[MAX][MAX],x[MAX],B[MAX];
int n,s;

void graph_color(int j)
{
    int i,k,c;
    x[j]=1;
    B[j]=1;
    //cout<<"\n\nvertex no : "<<j<<endl;
    for(i=0;i<j;i++)
    {
        //cout<<x[j]<<" "<<x[i]<<endl;
        c=0;
        if(G[i][j]!=0 && x[i]==x[j])
        {
            B[j]=x[j];
            x[j]=x[i]+1;
            //cout<<x[j]<<endl;

            for(k=0;k<n;k++)
            {
                if(B[k]==0)
                {
                    printf("- ");
                    ++c;
                }
                else
                {
                    cout<<B[k]<<" ";
                }
            }
            printf("\n");
            B[j]=x[j];
            if(c!=0)
            {
                s+=pow(n,c);
                cout<<s<<endl;
            }
            //cout<<c<<" "<<s<<endl;
        }
   }
}

int main()
{
    int e,i,j,u,v;
    while(1)
    {
        printf("Enter no. of vertices : ");
        scanf("%d",&n);
        printf("Enter no. of edges : ");
        scanf("%d",&e);

        s=0;
        memset(G,0,sizeof G);
        memset(B,0,sizeof B);

        printf("Enter edge vertex1-vertex 2 : \n");
        for(i=0;i<e;i++)
        {
            scanf("%d %d",&u,&v);
            G[u][v]=1;
            G[v][u]=1;
        }
        cout<<"Backtracking Point : \n\n";
        for(i=0;i<n;i++)
        {
            graph_color(i);
        }
        s+=n-B[n-1];
        printf("\n\nColors of vertices : \n");
        for(i=0;i<n;i++)
        {
            printf("Vertex[%d] : %d\n",i,x[i]);
        }
        printf("\nCombination Checking Reduced for Backtracking : ");
        cout<<s<<endl;
        /*for(i=0;i<n;i++)
        {
            //cout<<(n-B[i])<<" "<<pow(n,n-i-1)<<endl;
            s+=(n-B[i])*pow(n,n-i-1);
            //cout<<s<<endl;
        }
        printf("\nTotal Combination Checking Reduced : ");
        cout<<s<<endl<<endl;*/
        printf("\n\n");
    }
  return 0;
}
