#include <stdio.h>//number<=20
#include <math.h>
#include <conio.h>
#define ulld unsigned long long int

ulld factorial(ulld num)
{
    ulld f;
    if(num==1)
    {
        return 1;
    }
    else
    {
        f=num*factorial(num-1);
        return f;
    }
}

int main()
{
    ulld x;
    printf("Enter number = ");
    while(scanf("%lld",&x)==1)
    {
        printf("Factorial of %lld is %lld\n\n",x,factorial(x));
    }
    return 0;
}

/*//if we do this code in java we have to use this to multiply
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
public static void main(String[] arg){

Scanner input = new Scanner(System.in);
while(input.hasNext())
{
	BigInteger A = input.nextBigInteger();
	BigInteger B = input.nextBigInteger();
        System.out.println( A.multiply(B));
}


}
}
*/
