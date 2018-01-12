#include<iostream>
using namespace std;


int i,j,k,coin_values[10­];

int func()
{
    return i*coin_values[0]+j*c­oin_values[1]+k*coin­_values[2];
}


int main()
{
    int no_of_coins,coin_num­bers[10],target,no1,­no2,no3;
    int add=0;
    int mini=100,minj=100,mink=100;

    cout<<"Enter number of coins : ";
    cin>>no_of_coins;

    for(int i=0;i<no_of_coins;i+­+)
    {
        cin>>coin_values[i]>­>coin_numbers[i];
    }

    cout<<"Enter amount : ";
    cin>>target;

    no1=coin_numbers[0];
    no2=coin_numbers[1];
    no3=coin_numbers[2];

    for(i=0;i<no1;i++)
    {

        for(j=0;j<no2;j++)
        {
        for(k=0;k<no3;k++)
        {
            int ret=func();

            if(ret==target)
            {
                if(mini>i && minj>j && mink>k)
                {
                    mini=i;
                    minj=j;
                    mink=k;
                }
            }
        }
        }
    }

cout<<"Coin "<<coin_values[0]<<"­ is used "<<mini<<" times"<<endl;
cout<<"Coin "<<coin_values[1]<<"­ is used "<<minj<<" times"<<endl;
cout<<"Coin "<<coin_values[2]<<"­ is used "<<mink<<" times"<<endl;
return 0;
}
