#include <bits/stdc++.h>//ok by priority queue, complexity log(VlogV+E)
using namespace std;

const int MAX  = 1024;
const int INF  = 350;// 1<<31;

typedef unsigned long long int i64;
typedef  pair< int, int > pii;

vector  <pii> G[MAX];//G=graph
int d[MAX],par[MAX];//d=destination from source, par=parent

int  dijkstra(int src,int node)//The dijkstra routine. You can send a target node too along with the start node.
{
    i64  i,j,u,v,w,c;
    priority_queue<pii, vector< pii >, greater< pii > >  Q;
    memset(d,INF,sizeof(d));//if we take value except o and -1 in memset it stores garbage which is tense to infinity
    memset(par,-1,sizeof(par));
    //cout<<INF<<" "<<d[2]<<" "<<par[2]<<endl;//there will be positive value tense to infinity will appear for INF if we use more than 350 d[2] shows negative. though it doesn't give problem to if(d[u] + w < d[v]) condition
    Q.push(pii(0, src));
    d[src] = 0;

    while(!Q.empty())
    {
        u = Q.top().second; // node
        //cout<<"u = "<<u<<" d[u] = "<<d[u]<<endl;
        if(u==node)
        {
            return d[u];
        }

        c = Q.top().first;  // node cost so far
        Q.pop();            // remove the top item.
        //cout<<"c = "<<c<<endl;
        if(d[u] < c)
        {
            continue;
        }

        for(i = 0; i < G[u].size(); i++)
        {
            v = G[u][i].first;     // node
            w = G[u][i].second;    // edge cost
            //cout<<"v = "<<v<<" d[v] = "<<d[v]<<" w = "<<w<<endl;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                par[v]=u;
                Q.push(pii(d[v], v));
            }
            //cout<<"d[v] = "<<d[v]<<" par[v] = "<<par[v]<<endl<<endl;
        }
    }
    return -1;
}

int main()
{
    int node,edge,i,j,k,node1,node2,cost,src;//src=source
    vector<int>parent_vector[MAX];
    while(1)
    {
        cout<<"Enter Number of Nodes & Edges : ";
        cin>>node>>edge;
        for(i = 1; i <= node; i++)
        {
            G[i].clear();
            parent_vector[i].clear();
        }
        for(i = 1; i <= edge; i++)
        {
            cout<<"Enter edge node1-node2 & cost : ";
            scanf("%d %d %d", &node1, &node2, &cost);
            G[node1].push_back(pii(node2, cost));
            G[node2].push_back(pii(node1, cost)); // only if bi-directional
        }

        printf("\n");
        for(i=1;i<=node;i++)
        {
            k=G[i].size();
            cout<<"Connected node with node "<<i<<" :";
            for(j=0;j<k;j++)
            {
                cout<<"   "<<G[i][j].first<<" "<<G[i][j].second;//.first=node number  .second=cost with that node
            }
            printf("\n");
        }
        printf("\n");
        int en,dist;
        cout<<"Enter source & end node :";
        scanf("%d %d", &src, &en);//For a source node to call dijkstra.
        cout<<"Enter boost distance : ";
        cin>>dist;

        int ret= dijkstra(src,node);//ret means returned value
        if(ret==-1)
        {
            cout<<"no path"<<endl;
        }
        /*
        Output the shortest paths from the start node.
        */
        printf("Shortest path cost from node %d:\n\n", src);
        for(i = en; i <= node; i++)
        {
            if(i==en+1)
            {
                break;
            }
            if(i == src)
            {
                continue;
            }
            if(d[i] >= INF)
            {
                printf("\t to node %d: unreachable\n", i);
            }
            else
            {
                printf("\t to node %d: %d\n", i, d[i]);
                cout<<"\t Path in backward = "<<i<<" ";
                int x=i;
                while(x!=src)
                {
                    x=par[x];
                    //cout<<" dis = "<<d[x]<<endl;
                    parent_vector[i].push_back(x);
                    cout<<endl<<x<<" "<<d[x];
                }
                reverse(parent_vector[i].begin(),parent_vector[i].end());//to show path in forward direction
                printf("\n\n");
            }
        }
        int x,y,v=0,a=0,b;
        for(i=1;i<parent_vector[en].size();i++)
        {
            x=d[parent_vector[en][i]]-a;
            if(i+1<=parent_vector[en].size())
            {
                y=d[parent_vector[en][i+1]]-a;
                if(y<dist)
                {
                    cout<<x<<" c "<<y<<endl;
                    continue;
                }
                else
                {
                    ++v;
                    a=x;
                    cout<<"wtgwg"<<endl;
                }
            }
            cout<<x<<" "<<y<<endl;
        }
        cout<<v<<endl;
    }
    return 0;
}

/*
8 11
1 5 2
1 2 4
1 4 10
2 4 8
2 3 12
3 4 11
4 5 5
4 7 11
4 8 9
6 7 1
6 8 2
*/
