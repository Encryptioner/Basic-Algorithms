#include<bits/stdc++.h>//O(ElogE)
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
    int i,j,a,val,l,u,v,count=1,c=0;
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
int mst2(int n)
{
    int i,j,a,val,l,u,v,count=1,c=0;
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
        cout<<data[i].u<<" "<<data[i].v<<endl;

        if(u!=v)
        {
            par[u]=v;
            ++count;
            c+=data[i].w;
            //edge_list.push_back(pii(data[i].u, data[i].v));
            cout<<u<<" "<<v<<" "<<c<<endl;
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
    int i,j,k,n,m,u,v,w,minans,l,siz,minans2=2147483600,ans;
    cout<<"Enter Number of Nodes & edges: ";
    cin>>n>>m;
    krus o;

    cout<<"Enter node1-node2 & cost for 1 to m edges : ";
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        o.u=u,o.v=v,o.w=w;
        data.push_back(o);
    }
    minans=mst(n);
    l=edge_list.size();
    siz=data.size();

    //cout<<minans<<" "<<l<<" "<<siz<<endl;

    for(i=0;i<l;i++)
    {
        u=edge_list[i].first;
        v=edge_list[i].second;

        //cout<<u<<" "<<v<<endl;

        for(j=0;j<siz;j++)
        {
            if(data[j].u==u && data[j].v==v)
            {
                o.u=u,o.v=v,o.w=data[j].w;
                data.erase(data.begin()+j);
                break;
            }
        }
        ans=mst2(n);

        if(ans<minans2 && ans>minans)
        {
            minans2=ans;
        }
        data.push_back(o);
    }
    cout<<minans<<" "<<minans2<<endl;
    return 0;
}
