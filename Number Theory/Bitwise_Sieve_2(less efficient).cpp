#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int sieve[(MAX>>5)+10];
vector<long long int>prime_list;

bool Check(int N,int pos)
{
    printf("%d %d c = %d %d\n",N,pos,(1<<pos),N&(1<<pos));
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    printf("%d %d s = %d %d\n",N,pos,(1<<pos),N|(1<<pos));
    return N=N | (1<<pos);
}

void Bitwise_Sieve()
{
     int i, j, max1,p;
     max1=sqrt(MAX);

     for( i = 3; i <= max1; i += 2 )
     {
		 if( Check(sieve[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <= MAX; j += 2*i )
			 {
				 sieve[j>>5]=Set(sieve[j>>5],j&31)  ;
	 		 }
		 }
	 }
    prime_list.push_back(1);//supposing 1st prime is 1 and its index is prime[0]
    prime_list.push_back(2);
    p=1;//last index value of prime
    for(i=3;i<=MAX;i+=2)//don't counting even index as they are not prime except 2 which was pushed earlier
    {
        //if(Check( prime[i>>6],((i>>1)&31) )==0)
        if(Check( sieve[i>>5],(i&31) )==0)
        {
            prime_list.push_back(i);
            ++p;
        }
    }
    for(i=0;i<=p;i++)
    {
        cout<<i<<" "<<prime_list[i]<<endl;
    }
}
int main()
{
     Bitwise_Sieve();
     return 0;
}

