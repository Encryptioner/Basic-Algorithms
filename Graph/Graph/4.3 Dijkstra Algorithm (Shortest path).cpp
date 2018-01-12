#include <cstdio>//not ok

#include <iostream>

#include <vector>

#include <climits>

#include <queue>

using namespace std;


vector<int>graph[100];

int weight[100][100];

vector < int> cost(100);

int N;


struct cmp

{

  bool operator()(const int &lhs, const int &rhs) const

  {

    return cost[lhs] > cost[rhs];

  }

};


int min(int a,int b)

{

	if(a<b)

		return a;

	return b;

}


priority_queue <int,vector<int>,cmp> pq;


int dijkstra(int from,int to)

{
cout<<N;
	vector<bool>visited(N,false);
	//int visited[N];
    cout<<1515<<endl;
	visited[from] = true;

	cost [from] = 0;

	pq.push(from);

    cout<<4541<<endl;
	while(!pq.empty() && !visited[to])

	{

		int current = pq.top();

		pq.pop();

		visited[current] = true;

		for(int i=0;i<graph[current].size();i++)

		{

			if(!visited[graph[current][i]])

			{

				cost[graph[current][i]] = min( cost[graph[current][i]] ,cost[current] + weight[current][i]);

				pq.push(graph[current][i]);

			}

		}

	}

	return cost[to];

}


int main()

{
	int node,edge,i,j,k;
    int node1,node2,cost,c;
    cout<<"Enter number of node & edge : ";
    scanf("%d %d",&node,&edge);
    N=node;
    for(i=1;i<=edge;i++)
    {
        cout<<"Enter edge node-node & cost : ";
        scanf("%d%d%d",&node1,&node2,&cost);
        graph[node1].push_back(node2);
        weight[node1][node2]=cost;
    }
    printf("\n");
    for(i=1;i<=node;i++)
    {
        k=graph[i].size();
        cout<<"Connected node with node "<<i<<" :";
        for(j=0;j<k;j++)
        {
            c=graph[i][j];
            cout<<" "<<graph[i][j]<<"*"<<weight[i][c];
        }
        printf("\n");
    }
    printf("\n");

		cout<<454;
		cout<<dijkstra(1,2)<<endl;
		cout<<dijkstra(1,3)<<endl;
		cout<<dijkstra(4,1)<<endl;
		cout<<454;

		return 0;

	}
