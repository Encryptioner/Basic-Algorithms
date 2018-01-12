// C++ implementation of randomized quickSelect//when dataset is huge randomized quickSelect is better like greater than 2^14
#include<iostream>//not okay
#include<climits>
#include<cstdlib>
#include<cstdio>
using namespace std;
int com=0;
int randomPartition(int arr[], int l, int r);
int partition(int arr[], int l, int r);

// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r)
{
    // If k is smaller than number of elements in array
    if (l<r)
    {
        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r);

        // If position is same as k
        //if (pos-l == k-1)
            //return arr[pos];
        //if (pos-l > k-1)  // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos-1);

        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r);
    }

    // If k is more than number of elements in array
    return INT_MAX;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard partition process of QuickSort().  It considers the last
// element as pivot and moves all smaller element to left of it and
// greater elements to right. This function is used by randomPartition()
int partition(int arr[], int l, int r)
{
    int pivotindex=l+rand()%(r-l+1);
    int pivot=arr[pivotindex];
    int i=l-1;
    swap(&arr[pivotindex], &arr[r]);
    for (int j = l; j <= r - 1; j++)
    {
        com+=2;
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
    /*int x = arr[r], i = l-1;
    for (int j = l; j <= r - 1; j++)
    {
        com+=2;
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;*/
}

// Picks a random pivot element between l and r and partitions
// arr[l..r] arount the randomly picked element using partition()
int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    int i=l+pivot;
    swap(&arr[i], &arr[r]);
    return partition(arr, l, r);
}

int main()
{
    //int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int i,n,k;
    int arr[100000],arr2[100000];
    while(1){
    cout << "\n\nEnter the number of elements: ";
    cin >> n;

    //cout << "\n\nEnter required minimum position i (i<=n) : ";
    //cin >> k;

    for(i=0;i<n;i++)
    {
          arr[i]=rand()%1000000;
          arr2[i]=arr[i];
          //cout<<arr[i]<<endl;
    }
    //random_shuffle(&arr2[0],&arr2[0]+n);
    //n = sizeof(arr)/sizeof(arr[0]), k = 6;
    cout<<arr2[0]<<" "<<arr2[1]<<endl;
    cout <<k<<"'th smallest element is " << kthSmallest(arr, 0, n-1)<<endl;
    cout<<com<<endl;
    cout<<"Element : \n";
    for(i=0;i<n;i++)
    {
        cout<<i+1<<" "<<arr[i]<<endl;
    }

    }
    return 0;
}

