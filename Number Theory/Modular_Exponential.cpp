#include<bits/stdc++.h>
#define lld long long int
using namespace std;

lld Modular_Exponential(lld base,lld exponent,lld mod)
{
    lld result=1;
    while(exponent>0)
    {
        if(exponent%2==1)
        {
            result=(result*base)%mod;
            //cout<<"r = "<<result<<endl;
        }

        exponent=exponent>>1;
        base=(base*base)%mod;
        //cout<<exponent<<" "<<base<<endl;
    }
    return result;
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


