#include<bits/stdc++.h>
#define lld long long int
using namespace std;

#define MAX 30000003
bool sieve[MAX+10];
lld prime_size;
vector<lld>prime_list;

lld Sieve_of_Eratosthenes()
{
    lld i,j,max1;
    max1=sqrt(MAX);

    for(i=3;i<=max1;i+=2)
    {
        for(j=(i*i);j<=MAX;j+=(2*i))
        {
            sieve[j]=1;
        }
    }
    prime_list.push_back(1);
    prime_list.push_back(2);
    prime_size=1;
    for(i=3;i<=MAX;i+=2)
    {
        if(sieve[i]==0)
        {
            prime_list.push_back(i);
            ++prime_size;
        }
    }
    cout<<prime_size<<" "<<prime_list[prime_size]<<endl;
    return 0;
}
lld prime_factor_by_sieve()
{
    lld n,n1,i,j,l,count;
    bool negative=false;

    while(cin>>n)
    {
    cout<<n<<" = ";
    if(n<0)
    {
        n=n*(-1);
        negative=true;
        cout<<-1<<" * ";
    }
    n1=n;
    l=sqrt(n);
    count=0;
    for(i=1;prime_list[i]<=l;i++)//i=1 as 1st prime 2 is in prime_list[1]
    {
        if(n%prime_list[i]==0)
        {
            if(count>0)
            {
                cout<<" * ";
                count=0;
            }
            while(n%prime_list[i]==0)
            {
                n=n/prime_list[i];
                count++;
                if(count>1)
                {
                    cout<<" * "<<prime_list[i];
                }
                else
                {
                    cout<<prime_list[i];
                }
            }
        }
        if(n==1)
        {
            break;
        }
    }
    if(n1==n && n==1)
    {
        cout<<1<<endl;
    }
    else if(n!=1)
    {
        if(n1!=n)
        {
            cout<<" * "<<n<<"\n";
        }
        else
        {
            cout<<n<<endl;
        }
    }
    else
    {
        printf("\n");
    }
    negative=false;
    }
    return 0;
}

int main()
{
    Sieve_of_Eratosthenes();
    prime_factor_by_sieve();
    return 0;
}


