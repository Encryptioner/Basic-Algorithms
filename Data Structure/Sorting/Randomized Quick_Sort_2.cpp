#include <stdio.h>//ok

#include <stdlib.h>

#define MAX 10000

/*void random_shuffle(int arr[])

{

    srand(time(NULL));

    int i, j, temp;

    for (i = MAX - 1; i > 0; i--)

    {

        j = rand()%(i + 1);

        temp = arr[i];

        arr[i] = arr[j];

        arr[j] = temp;

    }

}
*/


void swap(int *a, int *b)

{

    int temp;

    temp = *a;

    *a = *b;

    *b = temp;

}

int partion(int arr[], int p, int r)

{

    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot

    int pivot;

    int i = p - 1;

    int j;

    pivot = arr[pivotIndex];

    swap(&arr[pivotIndex], &arr[r]);

    for (j = p; j < r; j++)

    {

        if (arr[j] < pivot)

        {

            i++;

            swap(&arr[i], &arr[j]);

        }

    }

    swap(&arr[i+1], &arr[r]);

    return i + 1;

}



void quick_sort(int arr[], int p, int q)

{

    int j;

    if (p < q)

    {

        j = partion(arr, p, q);

        quick_sort(arr, p, j-1);

        quick_sort(arr, j+1, q);

    }

}

int main()

{

    int i,n;

    int arr[MAX];

    scanf("%d",&n);

    for (i = 0; i < n; i++)

        //arr[i] = i;
        arr[i]=rand()%1000000;

    //random_shuffle(arr); //To randomize the array

    quick_sort(arr, 0, n-1); //function to sort the elements of array

    for (i = 0; i < n; i++)

         printf("%d %d \n",i+1, arr[i]);

    return 0;

}
