/* file:///G:/C%20Drive/Offline%20GeeksforGeeeks/www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/index.html
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array.
 It is given that ll array elements are distinct.

Examples:

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 3
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}
       k = 4
Output: 10
*/
#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
int com=0;
int partition(int arr[], int l, int r);

// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);

        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos-1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
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
// element as pivot and moves all smaller element to left of it
// and greater elements to right
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        com+=2;
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// Driver program to test above methods
int main()
{
    //int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int i,n,k;
    int arr[100000],arr2[100000];
    while(1){
    cout << "\n\nEnter the number of elements: ";
    cin >> n;

    cout << "\n\nEnter required minimum position i (i<=n) : ";
    cin >> k;

    for(i=0;i<n;i++)
    {
          arr[i]=rand();
          arr2[i]=arr[i];
          //cout<<arr[i]<<endl;
    }
    //n = sizeof(arr)/sizeof(arr[0]), k = 6;
    cout<<arr2[0]<<" "<<arr2[1]<<endl;
    cout <<k<<"'th smallest element is " << kthSmallest(arr, 0, n-1, k)<<endl;
    cout<<com<<endl;
    }
    return 0;
}
