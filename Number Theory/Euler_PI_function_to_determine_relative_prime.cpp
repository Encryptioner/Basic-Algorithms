#include<bits/stdc++.h>
using namespace std;

int Euler_phi(int n)
{
    int result=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            result-=result/i;
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n>1)
    {
        result-=result/n;
    }
    return result;
}
int main()
{
    int n,result;
    cout<<"Enter n to find number of relative prime less than n : ";
    cin>>n;
    result=Euler_phi(n);
    cout<<"\nNumber of relative prime less than "<<n<<" = "<<result<<"\n\n";
    main();
    return 0;
}
/*
#include<iostream>//Kalam
#include<bits/stdc++.h>

using namespace std;
//Macros
#define read(a) scanf("%d",&a)
#define CLEAR(a,b) memset(a,b,sizeof(a))
#define VI(a) vector<a>

#define lld long long int
#define ulld unsigned long long int
#define PI acos(-1.0)
#define Gamma 0.5772156649015328606065120900824024310421

//End Macros

#define MAX 10000010
bool prime[MAX+10];
vector<int>primeList;
int Vsize;

void sieve()
{
    for(int i=4;i<=MAX;i+=2)
        prime[i]=1;
    int srt = sqrt(MAX);
    for(int i=3;i<=srt;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=MAX;j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    prime[0]=prime[1]=1;

    for(int i=2;i<=MAX;i++)
    {
        if(prime[i]==0)
        {
            primeList.push_back(i);
        }
    }

    Vsize = primeList.size();

    //cout<<"seive OK"<<endl;
}

int PI_function(int n)
{
    if(prime[n]==0)
    {
        //cout<<n-1;
        return n-1;
    }
    int count;
    int res=1;
    for(int i=0;i<=Vsize;i++)
    {
        count=0;
        while(n%primeList[i]==0 && n!=1)
        {
            n/=primeList[i];
            count++;
        }
        if(count>=1)
            res*=((pow(primeList[i],count))-(pow(primeList[i],count-1)));

        if(n<=1)
            break;

        if(prime[n]==0)
        {
            res*=(n-1);
            break;
        }
    }
   // cout<<res;

    return res;

}

int main()
{
    sieve();
    int res = PI_function(40);
    cout<<res<<endl;
    return 0;

}
*/

/*
Euler’s totient function
The number of positive integers, not greater than n, and relatively prime with n, equals to Euler’s totient function φ (n). In symbols we can state that

φ (n) ={a Î N: 1 ≤ a ≤ n, gcd(a, n) = 1}

This function has the following properties:

    If p is prime, then φ (p) = p – 1 and φ (pa) = p a * (1 – 1/p) for any a.
    If m and n are coprime, then φ (m * n) = φ (m) * φ (n).
    If n = , then Euler function can be found using formula:

φ (n) = n * (1 – 1/p 1) * (1 – 1/p 2) * … * (1 – 1/p k)

The function fi(n) finds the value of φ(n):

For example, to find φ(616) we need to factorize the argument: 616 = 23 * 7 * 11. Then, using the formula, we’ll get:

φ(616) = 616 * (1 – 1/2) * (1 – 1/7) * (1 – 1/11) = 616 * 1/2 * 6/7 * 10/11 = 240.

Say you’ve got a problem that, for a given integer n (0 < n ≤ 109), asks you to find the number of positive integers less than n and relatively prime to n. For example, for n = 12 we have 4 such numbers: 1, 5, 7 and 11.

The solution: The number of positive integers less than n and relatively prime to n equals to φ(n). In this problem, then, we need do nothing more than to evaluate Euler’s totient function.

Or consider a scenario where you are asked to calculate a function Answer(x, y), with x and y both integers in the range [1, n], 1 ≤ n ≤ 50000. If you know Answer(x, y), then you can easily derive Answer(k*x, k*y) for any integer k. In this situation you want to know how many values of Answer(x, y) you need to precalculate. The function Answer is not symmetric.

For example, if n = 4, you need to precalculate 11 values: Answer(1, 1), Answer(1, 2), Answer(2, 1), Answer(1, 3), Answer(2, 3), Answer(3, 2), Answer(3, 1), Answer(1, 4), Answer(3, 4), Answer(4, 3) and Answer(4, 1).

The solution here is to let res(i) be the minimum number of Answer(x, y) to precalculate, where x, y Î{1, …, i}. It is obvious that res(1) = 1, because if n = 1, it is enough to know Answer(1, 1). Let we know res(i). So for n = i + 1 we need to find Answer(1, i + 1), Answer(2, i + 1), … , Answer(i + 1, i + 1), Answer(i + 1, 1), Answer(i + 1, 2), … , Answer(i + 1, i).

The values Answer(j, i + 1) and Answer(i + 1, j), j Î{1, …, i + 1}, can be found from known values if GCD(j, i + 1) > 1, i.e. if the numbers j and i + 1 are not common primes. So we must know all the values Answer(j, i + 1) and Answer(i + 1, j) for which j and i + 1 are coprime. The number of such values equals to 2 * φ (i + 1), where φ is an Euler’s totient function. So we have a recursion to solve a problem:
res(1) = 1,
res(i + 1) = res(i) + 2 * j (i + 1), i > 1

Euler’s totient theorem:
If n is a positive integer and a is coprime to n, then a φ (n) º 1 (mod n).
*/
