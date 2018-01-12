#include<bits/stdc++.h>//Accepted O(V=E), not in order of input
using namespace std;

#define MAX 102
#define For(i,n) for(i=1;i<=n;i++)

vector<int>G[MAX];
int in[MAX],pri[MAX];

int all_topological_sort(vector<int>& res,bool visited[],int n)
{
    // To indicate whether all topological are found
    // or not
    bool flag = false;
    int  siz,I,K,x;

    For(I,n)
    {
        //  If indegree is 0 and not yet visited then
        //  only choose that vertex
        if (in[I] == 0 && !visited[I])
        {
            //  reducing indegree of adjacent vertices
            siz=G[I].size();
            for(K=0;K<siz;K++)
            {
                x=G[I][K];
                in[x]-=1;
            }

            //  including in result
            res.push_back(I);
            visited[I] = true;
            all_topological_sort(res,visited,n);

            // resetting visited, res and indegree for
            // backtracking
            visited[I] = false;
            res.erase(res.end() - 1);
            siz=G[I].size();
            for(K=0;K<siz;K++)
            {
                x=G[I][K];
                in[x]+=1;
            }

            flag = true;
        }
    }

    //  We reach here if all vertices are visited.
    //  So we print the solution here
    siz=res.size();
    if (!flag)
    {
        for(K=0;K<siz-1;K++)
        {
            cout << res[K] << " ";
        }
        cout << res[K] << endl;
    }
    return 0;
}

int main()
{
    int n,m,I,K,M,x,y,cnt,u,siz,assign,node1,node2;

    map<int,int>mymap;//not mapped here

    while(cin>>n && cin>>m)
    {
        if(n==0 && m==0)
        {
            break;
        }

        assign=1;
        memset(in,0,sizeof(int)*(n+1));
        memset(pri,0,sizeof(int)*(n+1));

        For(I,m)
        {
            cin>>node1>>node2;//from 0 to n-1 node
            if(mymap.find(node1)==mymap.end())
            {
                //mymap[node1]=assign;
                pri[assign]=node1;//to print int to string
                assign++;
            }
            //x=mymap[node1];
            x=node1;

            if(mymap.find(node2)==mymap.end())
            {
                //mymap[node2]=assign;
                pri[assign]=node2;//to print int to string
                assign++;
            }
            //y=mymap[node2];
            y=node2;

            G[x].push_back(y);//x to y, y's list
            in[y]=in[y]+1;
            //cout<<x<<" "<<y<<" "<<in[y]<<endl;
        }
        For(I,n)
        {
            if(mymap.find(I)==mymap.end())//if any node has no indegree and outdegree
            {
                //mymap[I]=assign;
                pri[assign]=I;//to print int to string
                //cout<<I<<" mapped to "<<assign<<endl;
                assign++;

            }
        }

        vector<int>res;
        bool visited[MAX];
        memset(visited,0,sizeof(int)*(n+1));

        all_topological_sort(res,visited,n);

        mymap.clear();
    }

    return 0;
}
