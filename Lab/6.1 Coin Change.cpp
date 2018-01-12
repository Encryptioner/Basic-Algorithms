#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int active[10];
int save_active[10];

void binary(int val)
{
    int i,rem;
    for(i=0;val;i++)
    {
        rem=val%2;
        active[i]=rem;
        val/=2;
    }
}

int main()
{
    int cnt=0,add=0,mincnt=100;
    bool list_of_coins[10];
    int no_of_coins,coin_values[10],iter,target;

    cout<<"No of coins: ";
    cin>>no_of_coins;
    for(int i=0;i<no_of_coins;i++)
    {
        cin>>coin_values[i];
    }

    cout<<"Amount to make: ";
    cin>>target;

    iter=round(pow(2,no_of_coins));
    cout<<iter<<endl;
    for(int i=0;i<iter;i++)
    {
        memset(active,0,sizeof(active));
        binary(i);
        for(int j=0;j<no_of_coins;j++)
        {
            if(active[j])
            {
                cnt++;
                add+=coin_values[j];
            }
        }
    if(add==target)
    {
        if(mincnt>cnt)
        {
            for(int k=0;k<no_of_coins;k++)
                save_active[k]=active[k];
                mincnt=min(mincnt,cnt);
        }
    }
    cnt=0;
    add=0;
    }

    cout<<"Minimum number of coins is "<<mincnt<<" and coins are"<<endl;
    for(int i=0;i<no_of_coins;i++)
    {
        if(save_active[i])
            cout<<coin_values[i]<<" ";
    }

    return 0;
}
