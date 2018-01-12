#include<bits/stdc++.h>//ok for directed graph
using namespace std;

vector<int>G[100];
int parent[100]={0},level[100]={0};;
void bfs(int n,int src)
{
	int i,j,k,u,v,x;
	stack<int>Q;
	Q.push(src);
	int visited[100]={0};
	visited[src]=1;
    level[src]=0;
    /*u=src;
    k=G[u].size();
    for(i=0;i<k;i++)
    {
        level[G[u][i]]=level[u]+1;
        parent[G[u][i]]=u;
    }*/
	while(!Q.empty())
	{
		u=Q.top();
		Q.pop();
		for(stack<int>dump=Q;!dump.empty();dump.pop())
        {
            cout<<dump.top()<<" ";
        }
        printf("\n");
		k=G[u].size();
		for(i=0;i<k;i++)
        {
            if(!visited[G[u][i]])
            {
            Q.push(G[u][i]);
            level[G[u][i]]=level[u]+1;
            parent[G[u][i]]=u;
            visited[G[u][i]]=1;
            }
        }
        for(stack<int>dump=Q;!dump.empty();dump.pop())
        {
            cout<<dump.top()<<" ";
        }
        printf("\n");
        visited[u]=1;
		//v=Q.top();
		cout<<u<<" ";
		if(!Q.empty())
        {
            cout<<Q.top()<<endl<<endl;
        }
		//parent[v]=u;
        //level[v]=level[u]+1;
		/*while(visited[v])
        {
            cout<<555<<endl;
            Q.pop();
            if(Q.empty())
            {
                break;
            }
            v=Q.top();
        }*/
		//cout<<u<<" "<<v<<endl<<endl;
	}
	printf("\n");
	for(i=1;i<=n;i++)
    {
        printf("%d to %d Shortest distance %d\n",src,i,level[i]);
        cout<<"Path in backward = "<<i<<" ";
        x=i;
        while(x!=src && level[i]!=0)
        {
            x=parent[x];
            cout<<x<<" ";

        }
        printf("\n\n");
    }

}

int main()
{
    int node,edge,i,j,k;
    int node1,node2,cost,t=2;
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
    bfs(node,4);
    for(i=1;i<=node;i++)
        {
            G[i].clear();
        }
        //assign=1;
        //mymap.clear();
        //memset(level,0)
        memset(level,0,sizeof level);
        memset(parent,0,sizeof parent);
        //level[10000]={0};
        //parent[10000]={0};
    }
    return 0;
}



