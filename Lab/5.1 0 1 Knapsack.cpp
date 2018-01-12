#include<bits/stdc++.h>
using namespace std;
int way=0;

struct Knapsack
{
	int w,p;
	bool operator < ( const Knapsack& c ) const
	{
		return p > c.p;
	}
};
vector<Knapsack>data;

int Knapsack_0_1(int n,int m)
{
    clock_t start=clock();
    double time;
    int i,c=0,weight=0,profit=0,max_profit,Related_weight;

    sort(data.begin(),data.end());

    cout<<"\nSorted Data & Related weight : \n";
    for(i=0;i<n;i++)
    {
        cout<<data[i].p<<" "<<data[i].w;
        weight+=data[i].w;
        profit+=data[i].p;
        if(weight<=m)
        {
            cout<<" Taken";
            Related_weight=weight;
            max_profit=profit;
            c=i;
        }
        printf("\n");
    }
    cout<<"\nBy Picking Maximum weight First : Maximum profit = "<<max_profit<<", Related weight = "<<Related_weight<<endl<<endl;

    clock_t stop=clock();
    time=((double)(stop-start))/CLOCKS_PER_SEC;
    cout<<time<<endl;
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
        //data.push_back(object);
    }
    //Brute_Force(n,m,w,p);
    Knapsack_0_1(n,m);
    return 0;
}
