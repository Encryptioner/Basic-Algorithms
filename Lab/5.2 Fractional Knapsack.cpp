#include<bits/stdc++.h>
using namespace std;
int way=0;

struct Knapsack
{
	int w,p;
	bool operator < ( const Knapsack& c ) const
	{
		return p < c.p;
	}
};
vector<Knapsack>data;

int Pick_max_profit(int n,int m)
{
    clock_t start=clock();
    double time,v,max_profit,Related_weight;
    int i,c=0,c1=0,weight=0,profit=0;

    sort(data.begin(),data.end());

    cout<<"\nSorted Data & Related weight : \n";
    for(i=n-1;i>=0;i--)
    {
        cout<<data[i].p<<" "<<data[i].w<<endl;
        weight+=data[i].w;
        profit+=data[i].p;
        if(weight<=m)
        {
            Related_weight=weight;
            max_profit=profit;
            c=i;
        }
        if(weight>m && Related_weight<m)
        {
            v=(m-Related_weight)/data[i].w;
            //cout<<v<<endl;
            Related_weight=m;
            max_profit+=data[i].p*v;
            c1=i;
        }
    }
    cout<<"\nBy Picking Maximum Profit First : Maximum profit = "<<max_profit<<", Related weight = "<<Related_weight<<endl;

    clock_t stop=clock();
    time=((double)(stop-start))/CLOCKS_PER_SEC;
    cout<<"Runtime = "<<time<<endl<<endl;
    return 0;
}

int Pick_min_weight(int n,int m,int w[],int p[])
{
    clock_t start=clock();
    double time,v,max_profit,Related_weight;
    int i,j,c=0,c1=0,weight=0,profit=0;

    for(i=1;i<n;i++)
    {
        for(j=n-1;j>=i;j--)
        {
            if(w[j-1]<w[j])
            {
                swap(w[j-1],w[j]);
                swap(p[j-1],p[j]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<w[i]<<" "<<p[i]<<endl;
        weight+=w[i];
        profit+=p[i];
        if(weight<=m)
        {
            Related_weight=weight;
            max_profit=profit;
            c=i;
        }
        if(weight>m && Related_weight<m)
        {
            v=(m-Related_weight)/w[i];
            //cout<<v<<endl;
            Related_weight=m;
            max_profit+=p[i]*v;
            c1=i;
        }
    }
    cout<<"\nBy Picking Minimum weight First : Maximum profit = "<<max_profit<<", Minimum weight = "<<Related_weight<<endl<<endl;

    clock_t stop=clock();
    time=((double)(stop-start))/CLOCKS_PER_SEC;
    cout<<"Runtime = "<<time<<endl<<endl;
    return 0;
}
int main()
{
    int i,n,m,weight,profit;
    int w[100],p[100];
    cout<<"Enter Number of Objects : ";
    cin>>n;
    cout<<"Enter Maximum Weights : ";
    cin>>m;

    for(i=0;i<n;i++)
    {
        cin>>weight>>profit;
        w[i]=weight,p[i]=profit;
        Knapsack object;
        object.w=weight, object.p=profit;
        data.push_back(object);
    }
    //Brute_Force(n,m,w,p);
    Pick_max_profit(n,m);
    Pick_min_weight(n,m,w,p);
    return 0;
}

