#include<bits/stdc++.h>//O(ElogE)। //node starts from 1
#define MAXN 100001
using namespace std;

struct krus
{
	int u,v,w;
	bool operator < ( const krus& p ) const
	{
		return w < p.w;
	}
};
vector<krus>data;
typedef  pair< int, int > pii;
vector  <pii>edge_list;
int Find(int r,int par[])
{
    if(par[r]==r)
    {
        return r;
    }
    else
    {
        par[r]=Find(par[r],par);
        return Find(par[r],par);
    }
}

int mst(int n)
{
    int i,l,u,v,count=1,c=0;
    int par[n+1];
    sort(data.begin(),data.end());

    l=data.size();
    for(i=1;i<=n;i++)
    {
        par[i]=i;
    }
    for(i=0;i<l;i++)
    {
        u=Find(data[i].u , par);
        v=Find(data[i].v , par);
        if(u!=v)
        {
            par[u]=v;
            ++count;
            c+=data[i].w;
            edge_list.push_back(pii(data[i].u, data[i].v));
            if(count==n)
            {
                break;
            }
        }
    }
    return c;
}

int main()
{
    int i,n,m,u,v,w;
    cout<<"Enter Number of Nodes & edges: ";
    cin>>n>>m;

    cout<<"Enter node1-node2 & cost for 1 to m edges : ";
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        krus o;
        o.u=u,o.v=v,o.w=w;
        data.push_back(o);
    }
    cout<<mst(n)<<endl;
    return 0;
}
/*
operator overloading for priority queue

struct data
{  int u,v,cost;
    bool operator < ( const data& p ) const { //overloading operator
        return cost > p.cost;
    }
};

*/
