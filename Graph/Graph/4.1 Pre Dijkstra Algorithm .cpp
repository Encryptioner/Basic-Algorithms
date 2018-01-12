#include<bits/stdc++.h>//half ok but not dijkstra, by bfs complexity much
using namespace std;

vector<int>G[100];
int COST[100][100];

void shortest_path(int n,int src)
{
    vector<int>d(n+1,1000000);
    queue<int>Q;//here
    Q.push(src);
    d[src]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        for(int i=0;i<(int)G[u].size();i++)
        {
            int v=G[u][i];

            if(d[u]+COST[u][v]<d[v]) //  update/relaxation
            {
                d[v]=d[u]+COST[u][v];
                cout<<u<<" "<<v<<endl;
                Q.push(v);
            }
        }
        cout<<Q.front()<<endl;
        Q.pop();
    }
    for(int i=1;i<=n;i++)
		printf("%d to %d distance %d\n",src,i,d[i]);
}
int main()
{
    int node,edge,i,j,k;
    int node1,node2,cost,c;
    cout<<"Enter number of node & edge : ";
    scanf("%d %d",&node,&edge);
    for(i=1;i<=edge;i++)
    {
        cout<<"Enter edge node-node & cost : ";
        scanf("%d%d%d",&node1,&node2,&cost);
        G[node1].push_back(node2);
        COST[node1][node2]=cost;
    }
    printf("\n");
    for(i=1;i<=node;i++)
    {
        k=G[i].size();
        cout<<"Connected node with node "<<i<<" :";
        for(j=0;j<k;j++)
        {
            c=G[i][j];
            cout<<" "<<G[i][j]<<"*"<<COST[i][c];
        }
        printf("\n");
    }
    printf("\n");

    shortest_path(node,1);
    //system(pause);
    //cin>>i;
    return 0;
}

