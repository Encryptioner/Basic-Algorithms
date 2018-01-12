#include<bits/stdc++.h>//doesn't work when unconnected subgraph, multiple path between two node is okay
#define MAX 10001
using namespace std;

struct prim
{
	int node1,node2,cost;
	bool operator < ( const prim& c ) const
	{
		return cost > c.cost;
	}
};

typedef  pair< int, int > pii;
vector  <pii> G[MAX],edge_list;
vector<prim>data;

void mst_prim(int n,int src)
{
    int i,j,k,l,d,s,c=0,count=1;
    prim o;
    vector<int>sub;
    sub.push_back(src);

    i=src;
    while(count!=n)//until all node is in subgraph
    {
        bool x=false;

        l=G[i].size();
        o.node1=i;
        for(j=0;j<l;j++)//send all adjacent edge to sort if it is not previously considered
        {
           o.node2=G[i][j].first;
           o.cost=G[i][j].second;

            s=sub.size();
            for(k=0;k<s;k++)
            {
                if(sub[k]==o.node2)
                {
                    x=true;
                }
            }
            if(x==true){x=false;continue;}
           data.push_back(o);
        }

        sort(data.begin(),data.end());
        d=data.size();
        for(j=0;j<d;j++)
        {
            cout<<data[j].node1<<" "<<data[j].node2<<" "<<data[j].cost<<endl;
        }

        x=false;
        s=sub.size();
        for(k=0;k<s;k++)
        {
            if(sub[k]==data[d-1].node2)
            {
                x=true;
            }
        }
        while(1)//
        {
            cout<<data[d-1].node2<<endl;
            if(x==false)//if min edge and node is not in subgraph then add them
            {
                sub.push_back(data[d-1].node2);
                count++;
                cout<<"count = "<<count<<endl;
                edge_list.push_back(pii(data[d-1].node1, data[d-1].node2));

                c+=data[d-1].cost;
                i=data[d-1].node2;
                cout<<"new "<<i<<" "<<c<<endl;

                data.pop_back();
                break;
            }
            else if(d==0)
            {
                count=n;
                break;
            }
            else//to avoid cycle we will pop one data and recheck if we can get a new node for subgraph
            {
                data.pop_back();
                d=data.size();
                x=false;
                s=sub.size();
                for(j=0;j<s;j++)
                {
                    if(sub[j]==data[d-1].node2)
                    {
                        x=true;
                    }
                }
            }
        }//

        d=data.size();
        for(j=0;j<d;j++)
        {
            cout<<"dfd "<<data[j].node1<<" "<<data[j].node2<<" "<<data[j].cost<<endl;
        }
    }
    cout<<"\nmst cost = "<<c<<endl;
}
int main()
{
    int node,edge,i,j,k;
    int node1,node2,cost,c;
    cout<<"Enter number of node & edge : ";
    scanf("%d %d",&node,&edge);
    for(i=1;i<=edge;i++)
    {
        cout<<"Enter edge node-node & cost : ";
        scanf("%d%d%d",&node1,&node2,&cost);
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


    mst_prim(node,1);

    return 0;
}

/*
8 11
1 5 2
1 2 4
1 4 10
2 4 8
2 3 18
3 4 11
4 5 5
4 7 11
4 8 9
6 7 1
6 8 2
ans 34

4 6
1 2 10
1 2 9
2 3 15
1 3 5
4 2 2
4 3 40
ans 16
*/

