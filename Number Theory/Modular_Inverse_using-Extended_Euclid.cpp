#include<bits/stdc++.h>
using namespace std;

int x, y, d;
int Extended_Eulid(int a, int b)
{
    if(b==0)
    {
        x=1; y=0; d=a; // some extensions
        return a;
    }
    int ret = Extended_Eulid(b, a%b);     // GCD function
    int x1 = y;
    int y1 = x - (a/b) *y;
    x = x1;
    y = y1;
    return ret;
}
int main()
{
    int a,a_Inverse,MOD;
    while(cin>>a>>MOD)
    {
        Extended_Eulid(a,MOD); //here a*x+b*MOD = 1
        printf("x = %d, y = %d, gcd()=%d\n", x, y, d);

        a_Inverse = x; //x is the mod inverse
        if(x<0)  // if x is negative, to make it positive
        {
            a_Inverse+=MOD;
        }
        printf("Modular multiplicative inverse %d of %d modulo %d or %d(%d) = 1 (mod %d)\n\n",a_Inverse%MOD,a,MOD,a,a_Inverse%MOD,MOD);
    }

    return 0;

}


