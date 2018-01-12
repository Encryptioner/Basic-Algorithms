#include<bits/stdc++.h>//Not enough
using namespace std;

#define MAX 100
vector<int>G[MAX];
int visited[MAX];


//insert an edge (vi,vj) in te adjacency list
void DFS(int);

int main()
{
    int i,vi,vj,no_of_edges,n;
    printf("Enter number of vertices:");
    scanf("%d",&n);

    printf("Enter number of edges:");
    scanf("%d",&no_of_edges);

    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter an edge(u,v):");
        scanf("%d%d",&vi,&vj);
        G[vi].push_back(vj);
    }
    //initialised visited to 0

    for(i=0;i<n;i++)
        visited[i]=0;

    DFS(0);
    return 0;
}

void DFS(int i)
{

    printf("\n%d",i);

    int s=G[i].size();
    visited[i]=1;

    for(int j=0;j<s;j++)
    {
       int x=G[i][j];
       if(!visited[x])
       {
           DFS(x);
       }
    }
}

