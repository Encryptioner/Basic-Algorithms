#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int interchange=0,count=0;

int Quick_Sort(int x[],int first,int last)
{
    int pivot,j,temp,i;
    //static int interchange;
    //printf("\nfunction called = %d\n",++count);
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(x[i]<=x[pivot]&&i<last)
            {
                i++;
            }
            while(x[j]>x[pivot])
            {
                j--;
            }
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
                interchange++;
                //printf("\n...Interchange = %d\n",interchange);
            }
        }
        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;
        interchange++;
        //printf("\nInterchange = %d\n",interchange);
        Quick_Sort(x,first,j-1);
        Quick_Sort(x,j+1,last);
    }
    //printf("\nfunction called again\n");
    return interchange;
}

int show_sort(int array[],int N)
{
    int i;
    printf("\n");
    for(i=0;i<N;i++)
    {
        cout<<array[i]<<endl;
    }
    return 0;
}
int main()
{
    int N,i,data;
    cin>>N;//Number of Data
    int array[MAX];
    for(i=0;i<N;i++)//Enter data from starting index 0
    {
        cin>>data;
        array[i]=data;
    }
    Quick_Sort(array,0,N-1);
    show_sort(array,N);
    return 0;
}
