#include<bits/stdc++.h>//not ok  in find_ithmin
#include<fstream>
#define lld long long int
#define MAX 100000

using namespace std;

lld interchange;

lld partitioning(lld arr[],lld pivot,lld r)
{
    lld i,j,temp;

    lld v=arr[pivot];
    i=pivot;
    j=r;

    while(i<j)
    {
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
            ++interchange;
        }
    }
    arr[pivot]=arr[j];
    arr[j]=v;
    ++interchange;

    return j;
}

lld quick_sort(lld arr[],lld l,lld r)
{
    lld pivot;
    if(l<r)
    {
        pivot=partitioning(arr,l,r);
        //cout<<pivot<<" ";
        quick_sort(arr,l,pivot-1);
        quick_sort(arr,pivot+1,r);
    }
}

lld sorting(lld arr[],lld n,lld x)
{
    lld i;
    /*cout<<"\nGiven Data : "<<endl;
    for(i=0;i<n;i++)
    {
          cout<<arr[i]<<endl;
    }*/
    quick_sort(arr,0,n-1);

    cout<<"\nQuick_Sorted Data : "<<endl;
    /*for(i=0;i<n;i++)
    {
          cout<<arr[i]<<endl;
    }*/

    cout<<"The ith minimum = "<<arr[x-1]<<endl;
    cout<<"Number of interchange needed = "<<interchange<<endl;
    return 0;
}
lld find_ithmin(lld arr[],lld l,lld r,lld i)
{
    lld pivot,tl;
    if(i==l)
    {
        return arr[i];
    }
    pivot=partitioning(arr,l,r);
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

    cout << "\n\nEnter required minimum position i (i<=n) : ";
    cin >> x;

    ofstream fout;
    //fout.open("3.in ith minimum.txt");
    for(i=0;i<n;i++)
    {
          arr[i]=rand()%1000+1;
          arr2[i]=arr[i];
          //fout<<arr[i]<<endl;
    }
    //fout.close();
    interchange=0;
    sorting(arr,n,x);

    interchange=0;
    find_ithmin(arr2,0,n-1,x);
    cout<<"\nFind ith min Data : "<<endl;
    /*for(i=0;i<n;i++)
    {
          cout<<arr2[i]<<endl;
    }*/

    cout<<"The ith minimum = "<<arr2[x-1]<<endl;
    cout<<"Number of interchange needed = "<<interchange<<endl;
    }
    //cout<<4464646;
    //main();
    return 0;
}
