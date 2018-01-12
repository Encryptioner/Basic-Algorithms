#include <bits/stdc++.h>//Accepted
using namespace std;

const int MAX  = 100001;
const long long int INF  = 0x3f3f3f3f3f3f3f;

typedef unsigned long long int i64;
typedef  pair<long long int, int > pii;

vector  <pii> G[MAX];
int par[MAX];
long long int d[MAX];

int  dijkstra(int src,int node)
{
    i64  i,j,u,v,w,c,gus;
    priority_queue<pii, vector< pii >, greater< pii > >  Q;

    Q.push(pii(0, src));
    d[src] = 0;

    while(!Q.empty())
    {
        u = Q.top().second;
        c = Q.top().first;
        Q.pop();

        if(u==node)
        {
            return d[u];
        }

        if(d[u] < c)
        {
            continue;
        }
        gus=G[u].size();
        for(i = 0; i < gus; i++)
        {
            v = G[u][i].first;
            w = G[u][i].second;
            if(v==u)
            {
                continue;
            }
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                par[v]=u;
                Q.push(pii(d[v], v));
            }

        }
    }
    if(d[node] < INF)
    {
        return d[node];
    }
    else
    {
        return -1;
    }
}

int main()
{
    freopen("Alpha Round #20 C. Dijkstra.txt","r",stdin);
    int node,edge,i,j,k,node1,node2,cost,src,ret,x,y;
    vector<int>parent_vector;

    while(scanf("%d",&node)==1)
    {
        scanf("%d",&edge);
        for(i = 1; i <= node; i++)
        {
            G[i].clear();
            d[i]=INF;
            par[i]=-1;
        }
        for(i = 1; i <= edge; i++)
        {
            scanf("%d %d %d", &node1, &node2, &cost);
            G[node1].push_back(pii(node2, cost));
            G[node2].push_back(pii(node1, cost));
        }

        ret= dijkstra(1,node);
        if(ret==-1)
        {
            printf("-1");
        }
        else
        {
            x=node;
            while(x!=-1)
            {
                parent_vector.push_back(x);
                x=par[x];
            }
            reverse(parent_vector.begin(),parent_vector.end());
            y=parent_vector.size();
            for(i=0;i<y;i++)
            {
                printf("%d",parent_vector[i]);
                if(i!=y){printf(" ");}
            }
            parent_vector.clear();
        }
        printf("\n");
    }
    return 0;
}

