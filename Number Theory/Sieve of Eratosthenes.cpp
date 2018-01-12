#include<bits/stdc++.h>//to find prime number 1 to MAX, complexity O(n log log n)
#define lld long long int
using namespace std;

#define MAX 500//30000003
bool sieve[MAX+10];//initializing all sieve index value as false(0)
lld prime_size;
vector<lld>prime_list;

lld Sieve_of_Eratosthenes()
{
    lld i,j,max1;
    max1=sqrt(MAX);

    for(i=3;i<=max1;i+=2)//don't counting odd index
    {
        for(j=(i*i);j<=MAX;j+=(2*i))//j is divided by i
        {
            sieve[j]=1;//1 means true or this sieve index_no is not prime
        }
    }
    prime_list.push_back(1);//supposing 1st prime is 1 and its index is prime[0]
    prime_list.push_back(2);
    prime_size=1;//last index value of prime
    for(i=3;i<=MAX;i+=2)//don't counting odd index as they are not prime except 2 which was pushed earlier
    {
        if(sieve[i]==0)
        {
            prime_list.push_back(i);
            cout<<i<<endl;
            ++prime_size;
        }
    }
    cout<<prime_size<<" "<<prime_list[prime_size]<<endl;
    for(i=0;prime_list[i]<=200;i++)
    {
        cout<<prime_list[i]<<endl;
    }
    return 0;
}

int main()
{
    Sieve_of_Eratosthenes();
    return 0;
}


