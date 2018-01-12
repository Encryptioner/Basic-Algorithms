#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int Bubble_Sort(int array[],int N)
{
    int i,j,data,count,com,temp;

    for(i=1;i<N;i++)
    {
        for(j=N-1;j>=i;j--)
        {
            if(array[j-1]<array[j])//sorting in descending order
            //if(array[j-1]>array[j])//sorting in ascending orde
            {
                temp=array[j-1];
                array[j-1]=array[j];
                array[j]=temp;

                count++;
            }
            com++;
        }
    }
    return 0;
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
    Bubble_Sort(array,N);
    show_sort(array,N);
    return 0;
}
