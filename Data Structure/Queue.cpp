#include<bits/stdc++.h>//Accepted

using namespace std;

int main()//
{
    int F=0,R=0;
    int N,i;
    int Q[100];

    while(cin>>N && N!=0)//Throw away the top card starting from 1 and move the card that is now on the top of the deck to the bottom of the deck.
    {
        F=1;
        R=N;
        for(i=F;i<=R;i++)
        {
            Q[i]=i;
        }
        printf("Discarded cards:");
        while(F!=R)
        {
            printf(" %d",Q[F]);
            R=R+1;
            Q[R]=Q[F+1];
            F=F+2;
            if(F!=R)
            {
                printf(",");
            }
        }
        printf("\nRemaining card: %d\n",Q[R]);//Last Remaining Card
    }
    return 0;
}

