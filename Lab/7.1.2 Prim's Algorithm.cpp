#include<iostream>//just not ok with subgraph
#include<bits/stdc++.h>

using namespace std;
#define mx 100020
vector<int> graph[mx],cost[mx],Vartex;

struct node
{
    int v;
    int w;
    node(int c,int b){v=c; w=b;}
    bool operator > ( const node& p ) const { return w > p.w;}
};

bool visited[mx];

int MST_primes(int src,int max_node)
{
    int total_cost=0,p;
    memset(visited,0,sizeof(visited));
    priority_queue <node,vector<node>, greater<node> > q;
    Vartex.push_back(src);
    for(int i=1;i<max_node;i++)
    {
            visited[src]=true;
            for(int j=0;j<graph[src].size();j++)
            {
                q.push(node(graph[src][j],cost[src][j]));
            }

            do{
                node top = q.top();
                src = top.v;
                p = top.w;
                q.pop();
            } while(visited[src]==true && !q.empty());

            Vartex.push_back(src);
            total_cost+=p;

    }
    return total_cost;
}

int main()
{
    Vartex.clear();
    for(int i=0;i<=mx;i++)
    {
        graph[i].clear();
        cost[i].clear();
    }
    int n,e;
    int u,v,w;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);

    }
    int ans = 0;

    ans = MST_primes(1,n);
    cout<<ans<<endl;
    return 0;
}



