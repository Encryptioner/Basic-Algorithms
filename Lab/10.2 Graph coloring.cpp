#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int G[MAX][MAX],x[MAX],A[MAX],B[MAX];
int v=0;

void graph_color(int j)
{
    int i;
    x[j]=1;
    cout<<"\n\nvertex no : "<<j<<endl;
    for(i=0;i<j;i++)
    {
        cout<<x[j]<<" "<<x[i]<<endl;
        if(G[i][j]==0 || x[i]!=x[j])
        {
            A[v]=x[j];
            B[v]=x[i];
            v++;
        }
        if(G[i][j]!=0 && x[i]==x[j])
        {
            x[j]=x[i]+1;
            cout<<x[j]<<endl;
        }
   }
}

int main()
{
    int n,e,i,j,u,v;
    while(1)
    {
        printf("Enter no. of vertices : ");
        scanf("%d",&n);
        printf("Enter no. of edges : ");
        scanf("%d",&e);

        memset(G,0,sizeof G);

        printf("Enter edge vertex1-vertex 2 : \n");
        for(i=0;i<e;i++)
        {
            scanf("%d %d",&u,&v);
            G[u][v]=1;
            G[v][u]=1;
        }

        for(i=0;i<n;i++)
        {
            graph_color(i);
        }

        printf("\n\nColors of vertices : \n");
        for(i=0;i<n;i++)
        {
            printf("Vertex[%d] : %d\n",i,x[i]);
        }
        printf("\n\n");
        for(i=0;i<v;i++)
        {
            cout<<A[v]<<" "<<B[v]<<endl;
        }
    }
  return 0;
}
