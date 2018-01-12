#include <bits/stdc++.h>//not using adjacent list in directed graph complexity o(node*edge)
using namespace std;//negative cycle means cycling again and again (more than node+1 search) to find shortest path

#define MAXE 10000//maximum edge
#define MAXN 100//maximum node

int node,edge;
int d[MAXN],par[MAXN],edge_u[MAXE],edge_v[MAXE],edge_cost[MAXE];

int bellman_ford(int src)
{
    int neg_cycle=false;
    for(int i=1;i<=node;i++)
    {
        d[i]=1000000000;
        par[i]=-1;
    }
    d[src]=0; //distance to source is 0

    for(int step=1;step<=node;step++)
    {
        int updated=false;
        cout<<step<<endl;
        for(int i=1;i<=edge;i++)
        {
            int u=edge_u[i],v=edge_v[i];

            cout<<u<<" "<<v<<" "<<d[u]+edge_cost[i]<<" "<<d[v]<<endl;
            if(d[u]+edge_cost[i]<d[v])
            {
                d[v]=d[u]+edge_cost[i];
                cout<<"u--- "<<u<<" "<<v<<" "<<d[v]<<endl;
                par[v]=u;
                //updated=true;
                if(step==node)
                {
                    neg_cycle=true; //If we can update in n'th step, there is a negative cycle
                }
            }
        }
        printf("\n\n");
        /*if(updated==false)
        {
            break; //If we can't update in a any step, no need to try anymore
        }*/
    }

    if(neg_cycle==false)
    {

        vector<int>parent_vector[MAXN];
        printf("\nShortest path cost from node %d:\n\n", src);
        for(int i=1;i<=node;i++)
        {
            printf("\t to node %d: %d\n", i, d[i]);
            cout<<"\t Path in backward = "<<i<<" ";
            int x=i;
            break;
            while(x!=src)
            {
                x=par[x];
                parent_vector[i].push_back(x);
                cout<<x<<" ";
            }
            reverse(parent_vector[i].begin(),parent_vector[i].end());//to show path in forward direction
            printf("\n\n");
        }
    }
    else
    {
        puts("\nNegative cycle detected");
    }
    return 0;
}

int main()
{
    int src;

    cout<<"Enter Number of Nodes & Edges : ";
    cin>>node>>edge;

    for(int i=1;i<=edge;i++)
    {
        cout<<"Enter edge node1-node2 & cost : ";//direction node1 to node2
        cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];//for edge relaxation. serial depends on input serial
    }
    cout<<"Enter source node : ";
    cin>>src;
    bellman_ford(src);

    return 0;
}

/*
faster algorithm
inqueue : array of bool;

for i in [1..n] do { d[i]=oo; inqueue[i]=false; }
qu.push(start);
d[start] = 0;

repeat
    u=qu.pop;
    inqueue[u]=false;
    for v in adj[u] do
    if minimize(d[v], d[u]+uv) then
    if !inqueue[v] then
    { inqueue[v] = true; qu.push(v); }
until qu.empty;
print d[target];
*/
/*
input in matrix form
#include <stdio.h>
#include <stdlib.h>
int Bellman_Ford(int G[20][20] , int V, int E, int edge[20][2])
{
    int i,u,v,k,distance[20],parent[20],S,flag=1;
    for(i=0;i<V;i++)
        distance[i] = 1000 , parent[i] = -1 ;
        printf("Enter source: ");
        scanf("%d",&S);
        distance[S-1]=0 ;
    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v] , parent[v]=u ;
        }
    }
    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
        }
        if(flag)
            for(i=0;i<V;i++)
                printf("Vertex %d -> cost = %d parent = %d\n",i+1,distance[i],parent[i]+1);

        return flag;
}
int main()
{
    int V,edge[20][2],G[20][20],i,j,k=0;
    printf("BELLMAN FORD\n");
    printf("Enter no. of vertices: ");
    scanf("%d",&V);
    printf("Enter graph in matrix form:\n");
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            scanf("%d",&G[i][j]);
            if(G[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;
        }

    if(Bellman_Ford(G,V,k,edge))
        printf("\nNo negative weight cycle\n");
    else printf("\nNegative weight cycle exists\n");
    return 0;
}
*/
