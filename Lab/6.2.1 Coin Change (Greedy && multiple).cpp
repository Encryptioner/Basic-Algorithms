#include<bits/stdc++.h>
using namespace std;

struct coin_change
{
	int a,b;
	bool operator < ( const coin_change& c ) const
	{
		return a > c.a;
	}
};
vector<coin_change>data;

int main()
{
    int cnt=0,add=0;
    bool val=false;

    int i,j,n,target,mincnt=0,a,b,v,t;

    cout<<"No of coins: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        coin_change object;
        object.a=a,object.b=b;

        data.push_back(object);
    }
    cout<<"Amount to make: ";
    cin>>target;
    t=target;
    sort(data.begin(),data.end());
    //Descending
    cout<<"\nData : \n\n";
    for(i=0;i<n;i++)
    {
        cout<<data[i].a<<" "<<data[i].b;
        v=floor(t/data[i].a);
        //cout<<"\nv = "<<v<<endl;
        if(v==0)
        {
            printf("\n");
            continue;
        }
        if(v<=data[i].b)
        {
            add+=data[i].a*v;
        }
        if(v>data[i].b)
        {
            add+=data[i].a*data[i].b;
        }
        t=target-add;
        //cout<<"\nadd = "<<add<<" "<<t<<endl;
        if(add<=target)
        {
            cnt++;
            cout<<" Taken "<<(add-mincnt)/data[i].a<<" coins of "<<data[i].a;
        }
        if(add==target)
        {
            val=true;
        }
        /*if(add>target)
        {
            add=add-coin_values[i];
        }*/
        mincnt=add;
        printf("\n");
    }
    cout<<"\nNumber of needed coin type = "<<cnt<<endl;
    if(val==true)
    {
        cout<<"Achieved\n";
    }
    else
    {
        cout<<"Not Achieved\n";
        cout<<"Coin changed =  "<<mincnt<<endl;
    }
    return 0;
}
