#include<iostream>
#define lld long long int
using namespace std;

lld temp;

lld Modular_Exponential(lld base,lld exponent,lld mod)
{
    if(exponent==0)
    {
        return 1;
    }
    if(exponent%2==1)
    {
        return ((base%mod)*(Modular_Exponential(base,exponent-1,mod))%mod);
    }
    else
    {
        temp=Modular_Exponential(base,exponent/2,mod)%mod;
    }
    return (temp*temp)%mod;
}

int main()
{
    lld base,exponent,mod;

    while(cin>>base>>exponent>>mod)
    {
        cout<<"Result = "<<Modular_Exponential(base,exponent,mod)<<endl<<endl;
    }
    return 0;
}
