#include<bits/stdc++.h>//it can count prime number upto pow(10,9) and takes less memory than sieve_of_Eratosthenes
using namespace std;

#define MAX 1300000
//#define MAX 214783699
int sieve[(MAX>>6)+10];//there is 32 bit in an integer which is pow(2,5) and excluding even position so MAX is divided by pow(2,6)
int prime_size;
vector<int>prime_list;

bool Check(int n,int pos)
{
    return (n & (1<<pos));//cheaking if the pos position has 1 or n
}
int Set(int n,int pos)
{
    return (n | (1<<pos));//set 1 to the pos
}

int Bitwise_Sieve()
{
     int i, j, max1;
     max1=sqrt(MAX);

     for( i = 3; i <= max1; i += 2 )
     {
		 if( Check(sieve[i>>6],(i>>1)&31)==0)//if( Check(sieve[i/64],(i/2)%31)==0)
		 {
	 		 for( j = i*i; j <= MAX; j += 2*i )
			 {
				 sieve[j>>6]=Set(sieve[j>>6],(j>>1)&31) ;
	 		 }
		 }
	 }
    prime_list.push_back(1);
    prime_list.push_back(2);
    prime_size=1;//last index value of prime, thinking 1 as prime
    for(i=3;i<=MAX;i+=2)
    {
        if( Check(sieve[i>>6],(i>>1)&31)==0)
        {
            prime_list.push_back(i);
            ++prime_size;
        }
    }
    /*for(i=0;i<=prime_size;i++)
    {
        printf("%d %d\n",i,prime_list[i]);
    }*/
    cout<<prime_size<<" "<<prime_list[prime_size]<<endl;
    return 0;
}
int main()
{
     Bitwise_Sieve();
     return 0;
}
