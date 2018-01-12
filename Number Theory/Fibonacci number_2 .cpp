#include<bits/stdc++.h>//93 of (O(N)).
#define ulld unsigned long long int
using namespace std;

vector<ulld>fib(500);

ulld fibonacci(ulld n)
{
    ulld a,b;
    if(fib[n]>0)
    {
        return fib[n];
    }
    else if(n<=0)
    {
        return 0;
    }
    else
    {
        a=fibonacci(n-1);
        b=fibonacci(n-2);

        fib[n-1]=a;
        fib[n-2]=b;
        return (a+b);
    }
}
int main()
{
    ulld n;
    fib[1]=1,fib[2]=2;
    cout<<"Enter which Fibonacci number u wanna see? press 0 to terminate. \n";

    while(1)
    {
        cin>>n;
        //printf("%lld th Fibonacci Number = %lld\n",n,fibonacci(n-1));
        cout<<n<<" th Fibonacci Number = "<<fibonacci(n-1)<<endl;
    }
    return 0;
}

