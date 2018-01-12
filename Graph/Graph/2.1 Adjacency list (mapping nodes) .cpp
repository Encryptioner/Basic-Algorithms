#include<bits/stdc++.h>
using namespace std;

#define MAX 100000 //maximum node
vector<int>EDGES[MAX];
vector<int>COST[MAX]; //parallel vector to store costs;

int main()
{

    int node,edge,i,j,k;
    int node1,node2,cost;
    map<int,int>mymap;//mapping can be map<string,int>mymap. then node1 node2 wil be string and assign will be int as earlier
    int assign=1,x,y;

    cout<<"Enter number of node & edge : ";
    scanf("%d %d",&node,&edge);
    vector<int>indegree(node+1);//vector<int>indegree[node] gives error because node count starts from 1
    for(i=1;i<=edge;i++)
    {
        cout<<"Enter edge node1-node2 : ";
        cin>>node1>>node2;

        if(mymap.find(node1)==mymap.end())//mymap e search korte korte end e pouche jay. it means ekhono ei node er mapping hoyni
        {
            mymap[node1]=assign;
            //printf("Mapping %d with %d\n",node1,assign);
            cout<<"Mapping "<<node1<<" with "<<assign<<endl;
            assign++;
        }
        x=mymap[node1];
        if(mymap.find(node2)==mymap.end())
        {
            mymap[node2]=assign;
            cout<<"Mapping "<<node2<<" with "<<assign<<endl;
            assign++;
        }
        y=mymap[node2];

        EDGES[x].push_back(y);
        indegree[y]=indegree[y]+1;//for directed graph
        //EDGES[y].push_back(x);//for bidirectional graph
        //cout<<"Enter cost : ";
        //cin>>cost;
        cost=1;//for not weighted matrix else cin cost
        COST[x].push_back(cost);
        //COST[y].push_back(cost);//for bidirectional graph
    }
    for(i=1;i<=node;i++)
    {
        k=EDGES[i].size();//for undirected graph indegree=outdegree=EDGES[i].size()
        printf("\n");
        cout<<"Connected node with node "<<i<<" :";
        for(j=0;j<k;j++)
        {
            cout<<" "<<EDGES[i][j]<<"*"<<COST[i][j];
        }
        cout<<" & indegree = "<<indegree[i]<<" & outdegree = "<<k<<endl;
    }
    return 0;
}
