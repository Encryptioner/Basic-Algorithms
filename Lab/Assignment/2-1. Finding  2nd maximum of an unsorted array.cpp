#include<bits/stdc++.h>
using namespace std;
int com;
int second_max(int arr[],int n)
{
    int max1,max2;
    max1=max2=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max1)
        {
            max2=max1;
            max1=arr[i];
        }
    }
    cout<<"1st Maximum = "<<max1<<endl;
    cout<<"2nd Maximum = "<<max2<<endl;
    return 0;
}
int main()
{
    int i,n,k;
    int arr[100000],arr2[100000];
    while(1)
    {
        cout << "\n\nEnter the number of elements: ";
        cin >> n;

        k=2;

        for(i=0;i<n;i++)
        {
          arr[i]=rand();
          cout<<arr[i]<<endl;
        }
        second_max(arr,n);
    }
    return 0;
}
