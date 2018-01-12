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
    int i,j,a,val,l,u,v,count=1,c=0,n,m;
    scanf("%d %d",&n,&m);

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
    vector<int>parent;
    bool x;
    for(i=1;i<=n;i++)
    {
        x=false;
        val=Find(i,par);
        for(j=0;j<parent.size();j++)
        {
            if(val==parent[j])
            {
                x=true;
                break;
            }
        }
        if(x==false)
        {
            parent.push_back(val);
        }
    }

    printf("subgraph = %d\n",parent.size());
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
    cout<<"\nmst cost = "<<mst(n)<<endl;
    return 0;
}
/*
7 7
1 2 10
1 3 5
2 3 15
2 4 2
3 4 40
6 7 3
5 6 14

ans 34
two subgraph
*/
