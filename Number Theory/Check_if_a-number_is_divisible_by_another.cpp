#include<bits/stdc++.h>
#define lld long long int
using namespace std;

bool isDiv(string num, lld div)
{
    int i,rem=0;
    int len = num.length();

    for(i=0;i<len;i++)
    {
        rem =(10*rem+(num[i]-'0'))%div;
    }
    if(rem==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string num;
    lld div;

    getline(cin,num);
    cin>>div;

    bool result  = isDiv(num,div);

    if(result)
    {
        cout<<num<<" is divided by "<<div<<endl;
    }
    else
    {
        cout<<num<<" is not divided by "<<div<<endl;
    }
    return 0;
}
