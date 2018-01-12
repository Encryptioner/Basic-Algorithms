#include<bits/stdc++.h>
using namespace std;

int G[50][50],x[50];  //G:adjacency matrix,x:colors

void next_color(int k)
{
    int i,j;
    x[k]=1;  //coloring vertex with color1
    cout<<"\n\nvertex no : "<<k<<endl;
    for(i=0;i<k;i++)
    { //checking all k-1 vertices-backtracking
        cout<<x[k]<<" "<<x[i]<<endl;
        if(G[i][k]!=0 && x[k]==x[i])  //if connected and has same color
        {
            x[k]=x[i]+1;  //assign higher color than x[i]
            cout<<x[k]<<endl;
        }
   }
}

int main()
{
    int n,e,i,j,k,l,u,v;
    while(1)
    {
    printf("Enter no. of vertices : ");
    scanf("%d",&n);  //total vertices
    printf("Enter no. of edges : ");
    scanf("%d",&e);  //total edges

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j]=0;  //assign 0 to all index of adjacency matrix

    printf("Enter edge vertex1-vertex 2 : \n");
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        G[v][u]=1;
    }

    for(i=0;i<n;i++)
    {
        next_color(i);  //coloring each vertex
    }

    printf("\n\nColors of vertices : \n");
    for(i=0;i<n;i++)  //displaying color of each vertex
    {
        printf("Vertex[%d] : %d\n",i,x[i]);
    }
    printf("\n\n");
    }
  return 0;
}
