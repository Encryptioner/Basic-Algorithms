#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt=0,add=0;
    bool val=false;

    int i,j,n,target,data,mincnt;
    vector<int>coin_values;

    cout<<"No of coins: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        coin_values.push_back(data);
    }
    cout<<"Amount to make: ";
    cin>>target;

    sort(coin_values.begin(),coin_values.end());

    //greedy decreasing
    cout<<"\nData : \n\n";
    for(i=n-1;i>=0;i--)
    {
        cout<<coin_values[i];
        add+=coin_values[i];
        if(add<=target)
        {
            cnt++;
            cout<<" Taken";
            mincnt=add;
        }
        if(add==target)
        {
            val=true;
        }
        if(add>target)
        {
            add=add-coin_values[i];
        }
        printf("\n");
    }
    cout<<"\nNumber of needed coin = "<<cnt<<endl;
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
