// C++ implementation of worst case linear time algorithm//for worst case
// to find k'th smallest element
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int com=0;
int partition(int arr[], int l, int r, int k);

// A simple function to find median of arr[].  This is called
// only for an array of size 5 in this program.
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);  // Sort the array
    return arr[n/2];   // Return middle element
}

// Returns k'th smallest element in arr[l..r] in worst case
// linear time. ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k)
{
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1; // Number of elements in arr[l..r]

        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups;
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n) //For last group with less than 5 elements
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partition(arr, l, r, medOfMed);

        // If position is same as k
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)  // If position is more, recur for left
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

// It searches for x in arr[l..r], and partitions the array
// around x.
int partition(int arr[], int l, int r, int x)
{
    // Search for x in arr[l..r] and move it to end
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);

    // Standard partition algorithm
    i = l;
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
          arr[i]=rand()%1000000;
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
/*
a worst case linear time method is discussed. The idea in this new method is similar to quickSelect(),
 we get worst case linear time by selecting a pivot that divides array in a balanced way (there are not very few elements on one side and many on other side).
  After the array is divided in a balanced way, we apply the same steps as used in quickSelect() to decide whether to go left or right of pivot.

  kthSmallest(arr[0..n-1], k)
1) Divide arr[] into ⌈n/5rceil; groups where size of each group is 5
   except possibly the last group which may have less  than 5 elements.

2) Sort the above created ⌈n/5⌉ groups and find median
   of all groups. Create an auxiliary array 'median[]' and store medians
   of all ⌈n/5⌉ groups in this median array.

// Recursively call this method to find median of median[0..⌈n/5⌉-1]
3) medOfMed = kthSmallest(median[0..⌈n/5⌉-1], ⌈n/10⌉)

4) Partition arr[] around medOfMed and obtain its position.
     pos = partition(arr, n, medOfMed)

5) If pos == k return medOfMed
6) If pos < k return kthSmallest(arr[l..pos-1], k)
7) If poa > k return kthSmallest(arr[pos+1..r], k-pos+l-1)
*

