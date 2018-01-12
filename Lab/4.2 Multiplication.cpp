#include <bits/stdc++.h>

using namespace std;

int mul(int a, int b)
{
    if ( a < 0 ) return -mul(-a,b);

    if ( b < 0 ) return -mul(a,-b);

    if ( b == 0 ) return 0;

    return (mul(a,b>>1)<<1)+(b&1?a:0);
}

int main()
{
cout<< mul(2,-11) << endl;
}


/*#include <iostream>//Power Finding
using namespace std;

int Multiply(int a, int power)
{
if(power==1)
return a;
else
{
int x=Multiply(a,power/2);
if(power%2)
return x*x*a;
else
return x*x;
}
}

int main()
{
cout<< Multiply(2,11) << endl;
}
*/
