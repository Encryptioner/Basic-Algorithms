#include<bits/stdc++.h>//not ok
#define INF 0x3f3f3f3f3f3f3f
#define lld long long int
#define MAX 100
//using namespace std;

lld max=-INF,min=INF,max1=-INF,min1=INF,c1=0;
lld a[MAX],n;

void MaxMin(lld i,lld j,lld max,int min)
{
    printf("now %lld %lld\n\n",a[i],a[j]);
    if(i==j)
    {
        max=a[i];
        min=a[i];
        max1=max;
        min1=min;
        printf("1 %lld %lld\n",max,min);
    }
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
            max=a[i];
            min=a[j];
        }
        printf("2 %lld %lld\n",max,min);
    }
    else
    {
        lld mid=(i+j)>>1;
        printf("3 %lld %lld\n",max,min);
        MaxMin(i,mid,max,min);
        MaxMin(mid+1,j,max1,min1);
        printf("3 %lld %lld\n",max,min);
        if(max1>max){max=max1;}
        if(min1<min){min=min1;}
    }
    printf("\nFinding MAX and MIN by Merge Sort Algorithm:\n");
    printf("MAX = %lld\n",max);
    printf("MIN = %lld\n",min);
}

int main()
{
    lld i;
    printf("Enter the number of elements: ");
    scanf("%lld",&n);
    printf("\nEnter the element: \n");
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }

    MaxMin(1,n,max,min);
    main();
    return 0;
}

