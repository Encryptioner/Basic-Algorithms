#include<bits/stdc++.h>//ok, complexity O(V+E)
using namespace std;

vector<int>G[100];//here maximum node 100-1=99. node counting starts from 1
int parent[100]={0},level[100]={0};//for initializing all array element to zero. It only works when variable is declared first
int bfs(int n,int src)
{
	//memset(level,0,sizeof level);//both two for next test case
    //memset(parent,0,sizeof parent);
	queue<int>Q;
	Q.push(src);
	int visited[100]={0};
	visited[src]=1;
    level[src]=0;
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(!visited[v])
			{
				level[v]=level[u]+1;
				parent[v]=u;
				visited[v]=1;
				//cout<<u<<" "<<v<<endl;
				Q.push(v);
			}
		}
		//cout<<Q.front()<<endl;
		//Q.pop();
	}
	for(int i=1;i<=n;i++)
    {
        printf("%d to %d Shortest distance %d\n",src,i,level[i]);
        cout<<"Path in backward = "<<i<<" ";
        int x=i;
        while(x!=src && level[i]!=0)
        {
            x=parent[x];
            cout<<x<<" ";
        }
        printf("\n\n");
    }
    return 0;
}

int main()
{
    int node,edge,i,j,k;
    int node1,node2,cost,t=2;//t means test case
    while(t--){
    cout<<"Enter number of node & edge : ";
    scanf("%d %d",&node,&edge);
    for(i=1;i<=edge;i++)
    {
        cout<<"Enter edge node-node : ";
        scanf("%d%d",&node1,&node2);
        G[node1].push_back(node2);
        G[node2].push_back(node1);
    }
    printf("\n");
    for(i=1;i<=node;i++)
    {
        k=G[i].size();
        cout<<"Connected node with node "<<i<<" :";
        for(j=0;j<k;j++)
        {
            cout<<" "<<G[i][j];
        }
        printf("\n");
    }
    printf("\n");
    bfs(node,1);//calling bfs function to find shortest path starting from node 1
    for(i=1;i<=node;i++)
    {
        G[i].clear();//clearing previous graph for next test case
    }
        //assign=1;//clearing previous mapping for next test case
        //mymap.clear();//if we use mapping.
    }
    return 0;
}

