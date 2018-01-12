#include<bits/stdc++.h>
using namespace std;

#define MAX 100000 //maximum node
vector<int>EDGES[MAX];
vector<int>COST[MAX]; //parallel vector to store costs;

int main()
{

    int node,edge,i,j,k;
    int node1,node2,cost;
    cout<<"Enter number of node & edge : ";
    scanf("%d %d",&node,&edge);
    vector<int>indegree(node+1);//vector<int>indegree[node] gives error because node count starts from 1
    for(i=1;i<=edge;i++)
    {
        cout<<"Enter edge node1-node2 : ";
        scanf("%d%d",&node1,&node2);
        EDGES[node1].push_back(node2);
        indegree[node2]=indegree[node2]+1;//for directed graph
        //EDGES[node2].push_back(node1);//for bidirectional graph
        //cout<<"Enter cost : ";
        //cin>>cost;
        cost=1;//for not weighted matrix else cin cost
        COST[node1].push_back(cost);
        //COST[node2].push_back(cost);//for bidirectional graph
    }
    for(i=1;i<=node;i++)
    {
        k=EDGES[i].size();//for undirected graph indegree=outdegree=EDGES[i].size()
        cout<<"Connected node with node "<<i<<" :";
        for(j=0;j<k;j++)
        {
            cout<<" "<<EDGES[i][j]<<"*"<<COST[i][j];
        }

        cout<<" & indegree = "<<indegree[i]<<" & outdegree = "<<k<<endl;
        printf("\n");
    }
    return 0;
}
