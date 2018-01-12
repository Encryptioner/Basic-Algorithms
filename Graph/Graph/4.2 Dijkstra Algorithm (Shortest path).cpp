#include <bits/stdc++.h>//ok by priority queue
using namespace std;

const int MAX  = 1024;
const int INF  = 100000;// 1<<31;

typedef unsigned long long int i64;
typedef  pair< int, int > pii;

vector  <pii> G[MAX];//G=graph
int d[MAX],par[MAX];//d=destination from source, par=parent

/*pair object for graph is assumed to be (node, weight). d[] array holds the shortest path from the source.
It contains INF if not reachable from the source.*/

int  main()//The dijkstra routine. You can send a target node too along with the start node.
{
    i64  i,j,u,v,w,c;
    priority_queue<pii, vector< pii >, greater< pii > >  Q;
    memset(d,350,sizeof(d));//if we take value except o and -1 in memset it stores garbage
    memset(par,-1,sizeof(par));
    cout<<INF<<" "<<d[2]<<" "<<par[2]<<endl;

}
