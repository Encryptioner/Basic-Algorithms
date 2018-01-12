#include<bits/stdc++.h>//Accepted O(V=E), not in order of input

using namespace std;

#define MAX 102
#define For(i,n) for(i=1;i<=n;i++)

vector<int>G[MAX];
int in[MAX];

int main()
{
    freopen("11060. Beverages.txt","r",stdin);

    int n,m,K,M,x,y,cnt,siz,assign,c=0,I,u;
    string node1,node2,node;

    map<string,int>mymap;

    while(cin>>n)
    {
        vector<int>top_order;
        string str[n+1];
        //queue<int> q;
        priority_queue<int, vector<int>, std::greater<int> > q;//sort data in increasing order
        cnt=0;
        assign=1;
        memset(in,0,sizeof(int)*(n+1));memset(in,0,sizeof(int)*(n+1));

        For(I,n)
        {
            cin>>node;

            if(mymap.find(node)==mymap.end())
            {
                mymap[node]=assign;
                str[assign]=node;//to print int to string
                assign++;
            }
        }

        cin>>m;
        //mapping and find out indegree
        For(I,m)
        {
            cin>>node1>>node2;
            x=mymap[node1];
            y=mymap[node2];

            G[x].push_back(y);//x to y, y's list
            in[y]=in[y]+1;
            //cout<<in[y]<<endl;
        }
        //Topological Sort
        For(I,n)
        {
            if(mymap.find(I)==mymap.end())//if any node has isn't mapped
            {
                mymap[I]=assign;
                pri[assign]=I;//to print int to string
                //cout<<I<<" mapped to "<<assign<<endl;
                assign++;

            }
            //cout<<in[I]<<" ";
            if(in[I]==0)
            {
                q.push(I);
            }
        }
        //printf("\n");
        while (!q.empty())
        {
            u = q.top();//for queue q.front();
            q.pop();
            top_order.push_back(u);
            siz=G[u].size();

            //cout<<u<<"   "<<siz<<endl;

            for(K=0;K<siz;K++)
            {
                x=G[u][K];
                in[x]-=1;
                //cout<<x<<"  v "<<in[x]<<endl;
                if(in[x]==0)
                {
                    q.push(x);
                }
            }
            G[u].clear();
            cnt++;
        }
        printf("Case #%d: Dilbert should drink beverages in this order: ",++c);
        siz=top_order.size();
        for(K=0;K<siz-1;K++)
        {
            assign=top_order[K];
            cout<<str[assign]<<" ";
        }
        assign=top_order[K];
        cout<<str[assign]<<"."<<endl<<endl;
        mymap.clear();
    }

    return 0;
}





