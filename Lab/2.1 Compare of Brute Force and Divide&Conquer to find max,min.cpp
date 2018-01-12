#include <bits/stdc++.h>//ok
#include<fstream>
#define MAX 5000
#define INF 0x3f3f3f
using namespace std;

int arr[MAX],mx=-INF,mn=INF,mid,mx2,mn2,cx1=0,cy1=0,cx2=0,cy2=0;

int brute_force(int x,int n)
{
    mx2=mn2=arr[x];
    for(int i=x+1;i<=n;i++)
    {
        ++cx2;
        if(arr[i]>mx2)
        {
            mx2=arr[i];
        }
        else
        {
            ++cy2;
            if(arr[i]<mn2)
            {
                mn2=arr[i];
            }
        }
    }
    return 0;
}

void MaxMin(int i,int j)
{
    int max1,max2,finalmax,min1,min2,finalmin;

    if(i == j)
    {
        mx = arr[i];
        mn = arr[i];
    }
    else
    {
        mid = (i+j) / 2;

        MaxMin(i,mid);
        max1 = mx;
        min1 = mn;

        MaxMin(mid+1,j);
        max2 = mx;
        min2 = mn;

        //if(i!=mid)
        {
        finalmax = max(max1,max2);
        ++cx1;

        }
        //if((mid+1)!=j)
        {
        finalmin = min(min1,min2);
        ++cy1;
        }
        mx = finalmax;
        mn = finalmin;
    }

}

int main()
{
    int i,n;

    cout << "\n\nEnter the number of elements: ";
    cin >> n;


   ofstream fout,fout2;
   fout.open("2.in Compare of Brute Force and Divide&Conquer to find max,min.txt");
    for(i=0;i<n;i++)
    {
          arr[i]=rand()%1000+1;
          fout<<arr[i]<<endl;
    }
    fout.close();
    //freopen("2.in Compare of Brute Force and Divide&Conquer to find max,min.txt","r",stdin);
    MaxMin(0,n-1);
    fout2.open("2.out Compare of Brute Force and Divide&Conquer to find max,min.txt");
    fout2<<"\n\nThe maximum element by merge =  " << mx<<"  \tcomparison = "<<cx1<<endl;
    fout2<<"The minimum element by merge =  " << mn<<"  \tcomparison = "<<cy1<<endl;
    cout<<"\n\nThe maximum element by merge =  " << mx<<"  \tcomparison = "<<cx1<<endl;
    cout<<"The minimum element by merge =  " << mn<<"  \tcomparison = "<<cy1<<endl;

    brute_force(0,n-1);
    fout2<<"\n\nThe maximum element by brute_force =  " << mx2<<"  \tcomparison = "<<cx2<<endl;
    fout2<<"The minimum element by brute_force =  " << mn2<<"  \tcomparison = "<<cy2<<endl;
    cout<<"\n\nThe maximum element by brute_force =  " << mx2<<"  \tcomparison = "<<cx2<<endl;
    cout<<"The minimum element by brute_force =  " << mn2<<"  \tcomparison = "<<cy2<<endl;

    fout2.close();
    mx=-INF,mn=INF,mid,mx2,mn2,cx1=0,cy1=0,cx2=0,cy2=0;
    main();
    return 0;
}
/*#include <bits/stdc++.h>
#include<fstream>
#define MAX 5000
#define INF 0x3f3f3f
using namespace std;

int arr[MAX],mx=-INF,mn=INF,mid,mx2,mn2,cx1=0,cy1=0,cx2=0,cy2=0;

int brute_force(int x,int n)
{
    mx2=mn2=arr[x];
    for(int i=x+1;i<=n;i++)
    {
        if(arr[i]>mx2)
        {
            mx2=arr[i];
        }
        else if(arr[i]<mn2)
        {
            mn2=arr[i];
        }
        ++cx2;
        ++cy2;
    }
    return 0;
}

void maxandmin(int n,int i)
{
    int max1,max2,finalmax,min1,min2,finalmin;

    if(i == n)
    {
        mx = arr[i];
        mn = arr[i];
    }
    else
    {
        mid = (i+n) / 2;

        maxandmin(i,mid);
        max1 = mx;
        min1 = mn;

        maxandmin(mid+1,n);
        max2 = mx;
        min2 = mn;

        if(i!=mid)
        {
        finalmax = max(max1,max2);
        ++cx1;
        }
        if((mid+1)!=n)
        {
        finalmin = min(min1,min2);
        ++cy1;
        }
        mx = finalmax;
        mn = finalmin;
    }

}

int main()
{
    int i,n;

    cout << "\n\nEnter the number of elements: ";
    cin >> n;


   ofstream fout,fout2;
   fout.open("2.in Compare of Brute Force and Divide&Conquer to find max,min.txt");
    for(i=0;i<n;i++)
    {
          arr[i]=rand()%1000+1;
          fout<<arr[i]<<endl;
    }
    fout.close();
    //freopen("2.in Compare of Brute Force and Divide&Conquer to find max,min.txt","r",stdin);
    maxandmin(0,n-1);
    fout2.open("2.out Compare of Brute Force and Divide&Conquer to find max,min.txt");
    fout2<<"\n\nThe maximum element by merge =  " << mx<<"  \tcomparison = "<<cx1<<endl;
    fout2<<"The minimum element by merge =  " << mn<<"  \tcomparison = "<<cy1<<endl;
    cout<<"\n\nThe maximum element by merge =  " << mx<<"  \tcomparison = "<<cx1<<endl;
    cout<<"The minimum element by merge =  " << mn<<"  \tcomparison = "<<cy1<<endl;

    brute_force(0,n-1);
    fout2<<"\n\nThe maximum element by brute_force =  " << mx2<<"  \tcomparison = "<<cx2<<endl;
    fout2<<"The minimum element by brute_force =  " << mn2<<"  \tcomparison = "<<cy2<<endl;
    cout<<"\n\nThe maximum element by brute_force =  " << mx2<<"  \tcomparison = "<<cx2<<endl;
    cout<<"The minimum element by brute_force =  " << mn2<<"  \tcomparison = "<<cy2<<endl;

    fout2.close();
    mx=-INF,mn=INF,mid,mx2,mn2,cx1=0,cy1=0,cx2=0,cy2=0;
    main();
    return 0;
}*/
