#include<bits/stdc++.h>//not
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
    //cout<<"pivot = "<<pivot<<" "<<j<<endl;
    while(1)
    {
        ++comparison;
        while(arr[i]<=v)
        {
                i++;
                ++comparison;
        }
        while(arr[j]>v)
        {
            j--;
            ++comparison;
        }
        comparison+=3;
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
/*lld partitioning_1(lld arr[],lld pivot,lld r)
{
    lld i,j,temp;
    //cout<<"r+1-pivot = "<<(r+1-pivot)<<" ";
    lld val,l=pivot;
    if(l!=r)
    {
        val=r-1;
    }
    else
    {
        val=r;
    }
    lld x = arr[(rand()%val)];
    cout<<"Random = "<<x<<endl;

    pivot=x;

    i=pivot;
    j=r;
    lld v=arr[pivot];
    //cout<<x<<" "<<pivot<<" "<<r<<endl;
    while(1)
    {
        ++comparison;
        while(arr[i]<=v)
        {
                i++;
                ++comparison;
        }
        while(arr[j]>v)
        {
            j--;
            ++comparison;
        }
        comparison+=3;
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

*/
lld quick_sort_1(lld arr[],lld l,lld r)
{
    lld pivot;
    ++comparison;
    if(l<r)
    {
        //cout<<" sgsg ";
        pivot=partitioning_1(arr,l,r);
        //cout<<pivot<<" ";
        quick_sort_1(arr,l,pivot);
        quick_sort_1(arr,pivot+1,r);
    }
}

lld find_ithmin(lld arr[],lld l,lld r,lld i)
{
    lld pivot,tl;
    ++comparison;
    if(i==l)
    {
        return arr[i];
    }
    pivot=partitioning_1(arr,l,r);
    tl=pivot-l+1;
    ++comparison;
    if(i==pivot)
    {
        return arr[i];
    }
    ++comparison;
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

    while(1)
    {
        cout << "\n\nEnter the number of elements: ";
        cin >> n;
        cout << "\n\nEnter required minimum position i (i<=n) : ";
        cin >> x;

        for(i=0;i<n;i++)
        {
            arr[i]=rand()%1000;
            arr2[i]=arr[i];
        }

        comparison=0;
        find_ithmin(arr2,0,n-1,x);
        cout<<"\nFind ith min Data : "<<endl;
        for(i=0;i<n;i++)
        {
            cout<<arr2[i]<<endl;
        }

        cout<<"The ith minimum = "<<arr2[x-1]<<endl;
        cout<<"Number of comparison needed = "<<comparison<<endl;

    }
    return 0;
}


