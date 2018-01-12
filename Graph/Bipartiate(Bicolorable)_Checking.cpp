#include<bits/stdc++.h>//Accepted
#define MAX 201
using namespace std;

vector<int>G[MAX];

int bfs(int n,int src)
{
	int color[MAX]={0},visited[MAX]={0};
    int x,y,u,v,i,j;
    bool bipartite=true;
    queue<int>Q;

	Q.push(src);
	visited[src]=1;
    color[src]=1;

	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();

		x=color[u];
		if(x==1)
        {
            y=2;
        }
        else
        {
            y=1;
        }

		for(i=0;i<G[u].size();i++)
		{
			v=G[u][i];
			if(!visited[v])
			{
				visited[v]=1;
				color[v]=y;
				Q.push(v);
			}
			else if(color[v]!=y)
            {
                bipartite=false;
                printf("NOT BICOLORABLE.\n");
                break;
            }
		}
		if(!bipartite)
        {
            break;
        }
	}
	if(bipartite)
    {
        printf("BICOLORABLE.\n");
    }
    return 0;
}

int main()
{
    int node,edge,i,j,k;
    int node1,node2,cost;

    while(cin>>node && node!=0)
    {
        cin>>edge;
        for(i=0;i<edge;i++)
        {
            scanf("%d%d",&node1,&node2);
            G[node1].push_back(node2);
            G[node2].push_back(node1);
        }
        bfs(node,0);
        for(i=0;i<node;i++)
        {
            G[i].clear();
        }
    }
    return 0;
}



