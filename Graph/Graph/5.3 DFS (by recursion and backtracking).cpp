//http://www.algolist.net/Algorithms/Graph/Undirected/Depth-first_search

#include<bits/stdc++.h>
using namespace std;

enum VertexState { White, Gray, Black };

void Graph::runDFS(int u, VertexState state[])
{
      state[u] = Gray;
      for (int v = 0; v < vertexCount; v++)
      {
            if (isEdge(u, v) && state[v] == White)
            {
                runDFS(v, state);
            }
      }
      state[u] = Black;
}

void Graph::DFS()
{
      VertexState *state = new VertexState[vertexCount];

      for (int i = 0; i < vertexCount; i++)
      {
          state[i] = White;
      }

      runDFS(0, state);
      delete [] state;
}

int main()
{

}
