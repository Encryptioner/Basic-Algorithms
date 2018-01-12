#include<cstdio>//not ok
#include<iostream>
#include <list>
using namespace std;

// This class represents a undirected graph using adjacency list
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;  // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void printVertexCover();  // prints vertex cover
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Since the graph is undirected
}

// The function to print vertex cover
void Graph::printVertexCover()
{
    // Initialize all vertices as not visited.
    bool visited[V];
    for (int i=0; i<V; i++)
        visited[i] = false;

    list<int>::iterator i;

    // Consider all edges one by one
    for (int u=0; u<V; u++)
    {
        // An edge is only picked when both visited[u] and visited[v]
        // are false
        if (visited[u] == false)
        {
            // Go through all adjacents of u and pick the first not
            // yet visited vertex (We are basically picking an edge
            // (u, v) from remaining edges.
            for (i= adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = *i;
                if (visited[v] == false)
                {
                     // Add the vertices (u, v) to the result set.
                     // We make the vertex u and v visited so that
                     // all edges from/to them would be ignored
                     visited[v] = true;
                     visited[u]  = true;
                     break;
                }
            }
        }
    }

    // Print the vertex cover
    cout<<"\n\nNode no of minimum vertex to cover : ";
    for (int i=0; i<V; i++)
        if (visited[i])
          cout << i << " ";
    printf("\n\n");
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    int n,i,u,v;
    cout<<"Enter Number of edge : ";
    cin>>n;

    Graph g(n+1);

    for(i=0;i<n;i++)
    {
        cin>>u>>v;
        g.addEdge(u, v);
    }
    g.printVertexCover();

    return 0;
}


/*#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include <list>
#include <string>

using namespace std;

typedef std::list< std::pair<int,int> > myType;

int main()
{
list<pair<int,int>> edge;
myType::iterator it1,it2;

int i,n,u,v,n1,a,b;

    cin>>n;
    n1=n;

    for(i=0;i<n;i++)
    {
        cin>>u>>v;
        edge.push_back( make_pair(u,v) );
    }
    printf("\n\n");

    it1 = edge.begin();

    while(n1>0){
            int x= rand()%(n1+1);


        it2 = edge.begin();
        advance (it2,x);
        --it2;
        a = (*it2).first;
        b = (*it2).second;
        cout<<"n1 = "<<n1<<"\nx = "<<x<<"    "<<a<<" "<<b<<endl<<endl;
        int p=n1;
    it1 = edge.begin();
    for(i=1;it1 != edge.end();i++,it1++)
    {

        u = (*it1).first;
        v = (*it1).second;


        cout<<"n1 = "<<n1<<" i = "<<i<<endl;
        cout<<u<<" "<<v<<endl;
        //cout<<"    "<<i<<" "<<n1<<endl;
        if(i>=p)
        {
            if(u==a || u==b || v==a || v==b)
            {
            --it1;
            --n1;
            it1=edge.erase (it1);
            //cout<<edge.size()<<endl;
            cout<<"erase \n\n";
            break;
            }
        }

        if(u==a || u==b || v==a || v==b)
        {
            --it1;
            --n1;
            it1=edge.erase(it1);
            //edge.resize(n1);//sets all value to 0

            cout<<" erase \n\n";
            cout<<edge.size()<<endl;
            continue;
        }
        cout<<"\n"<<u<<"     "<<v<<endl<<endl;

    }
    }
    edge.clear();
    cout<<"Broke\n\n\n";
    return 0;
    cout<<"Broke\n";
}
/*
#include <list>
#include <string>

using namespace std;

typedef std::list< std::pair<string,char> > myType;


int main()
{
list<pair<string,char>> edge;

edge.push_back( make_pair("aaa",' ') );


myType::iterator iter = edge.begin();

for(;iter != edge.end();iter++)
{
string s = (*iter).first;
char c = (*iter).second;
}
}
*/
