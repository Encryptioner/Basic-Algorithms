#include<bits/stdc++.h>//was told find kth minimum generealized partition and randomized partition and find number of comparision
#include<fstream>//not ok
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
    //cout<<"pivot = "<<pivot<<" "<<j<<endl;
    while(1)
    {
        ++comparison;
        while(arr[i]<=v)
        {
                i++;
                //++comparison;
        }
        while(arr[j]>v)
        {
            j--;
            //++comparison;
        }
        //comparison+=3;
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

        }
        else
        {
            arr[pivot]=arr[j];
            arr[j]=v;

            return j;
        }
    }
}

lld quick_sort_1(lld arr[],lld l,lld r)
{
    lld pivot;
    //++comparison;
    if(l<r)
    {
        //cout<<" sgsg ";
        pivot=partitioning_1(arr,l,r);
        //cout<<pivot<<" ";
        quick_sort_1(arr,l,pivot-1);
        quick_sort_1(arr,pivot+1,r);
    }
}
lld partitioning_2(lld arr[],lld l,lld r)
{
    lld v,i,j,temp;
    v=arr[r];
    i=l;
    j=r;
    //cout<<x<<" "<<pivot<<" "<<r<<endl;
    while(true)
    {
        ++comparison;
        while(arr[i]<v && i<=r)
        {
                ++i;
                ++comparison;
        }
        while(arr[j]>=v && j>=0)
        {
            --j;
            ++comparison;
        }
        //comparison+=3;
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else
        {
            //arr[i]=arr[j];
            //arr[j]=v;

            return j;
        }
    }
}

lld quick_sort_2(lld arr[],lld l,lld r)
{
    lld pivot;
    if(l<r)
    {
        //cout<<" sgsg ";
        pivot=partitioning_2(arr,l,r);
        //cout<<" "<<pivot<<" "<<endl;
        quick_sort_2(arr,l,pivot-1);
        quick_sort_2(arr,pivot,r);
    }
}
lld sorting(lld arr[],lld n,lld x)
{
    lld i;

    /*comparison=0;
    cout<<25<<endl;
    quick_sort_1(arr,0,n-1);
    cout<<"\nQuick_Sorted_1 Data : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<arr[i]<<endl;
    }
    cout<<"The ith minimum = "<<arr[x-1]<<endl;
    cout<<"Number of comparison needed = "<<comparison<<endl;*/

    comparison=0;
    cout<<25<<endl;
    quick_sort_2(arr,0,n-1);
    cout<<"\nQuick_Sorted_2 Data : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<i<<" "<<arr[i]<<endl;
    }
    cout<<"The ith minimum = "<<arr[x-1]<<endl;
    cout<<"Number of comparison needed = "<<comparison<<endl;

    return 0;
}
lld find_ithmin(lld arr[],lld l,lld r,lld i)
{
    lld pivot,tl;
    if(i==l)
    {
        return arr[i];
    }
    pivot=partitioning_1(arr,l,r);
    tl=pivot-l+1;
    if(i==pivot)
    {
        return arr[i];
    }
    if(i<pivot)
    {
        find_ithmin(arr,l,pivot-1,i);
    }
    else
    {
        find_ithmin(arr,pivot+1,r,i-tl);
    }
    return 0;
}
int main()
{
    lld i,n,x;
    lld arr[MAX],arr2[MAX];

    while(1){
    cout << "\n\nEnter the number of elements: ";
    cin >> n;
    N=n;
    cout << "\n\nEnter required minimum position i (i<=n) : ";
    cin >> x;

    for(i=0;i<n;i++)
    {
          arr[i]=rand()%1000000;
          arr2[i]=arr[i];
          //cout<<arr[i]<<endl;
    }
    comparison=0;
    sorting(arr,n,x);
    cout<<arr2[0]<<" "<<arr2[1]<<endl;
    /*comparison=0;
    //find_ithmin(arr2,0,n-1,x);
    cout<<"\nFind ith min Data : "<<endl;
    for(i=0;i<n;i++)
    {
          cout<<arr2[i]<<endl;
    }

    cout<<"The ith minimum = "<<arr2[x-1]<<endl;
    cout<<"Number of comparison needed = "<<comparison<<endl;*/

    }
    //cout<<4464646;
    //main();
    return 0;
}

