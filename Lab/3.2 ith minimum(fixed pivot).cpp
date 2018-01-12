#include<bits/stdc++.h>//ok by full sorting
#include<fstream>
#define lld long long int
#define MAX 100000

using namespace std;

lld comparison,N;

lld partitioning_1(lld arr[],lld pivot,lld r)
{
    lld i,j,temp;

    lld v=arr[pivot];
    i=pivot;
    j=r;

    while(i<j)
    {
        ++comparison;
        while(arr[i]<=v && i<r)
        {
                i++;
        }
        while(arr[j]>v)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[pivot]=arr[j];
    arr[j]=v;

    return j;
}

lld quick_sort_1(lld arr[],lld l,lld r)
{
    lld pivot;
    ++comparison;
    if(l<r)
    {
        pivot=partitioning_1(arr,l,r);
        quick_sort_1(arr,l,pivot-1);
        quick_sort_1(arr,pivot+1,r);
    }
}

int main()
{
    lld i,n,x;
    lld arr[MAX],arr2[MAX];

    while(1)
    {
        cout << "\n\nEnter the number of elements: ";
        cin >> n;
        cout << "\n\nEnter required minimum position i (i<=n) : ";
        cin >> x;

        for(i=0;i<n;i++)
        {
            arr[i]=rand()%1000;
        }

        comparison=0;
        quick_sort_1(arr,0,n-1);
        cout<<"\nSorted Data : \n";
        for(i=0;i<x;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\nThe ith minimum = "<<arr[x-1]<<endl;
        cout<<"Number of comparison needed = "<<comparison<<endl;
    }

    return 0;
}


