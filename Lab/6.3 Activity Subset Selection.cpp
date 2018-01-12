#include<bits/stdc++.h>
using namespace std;

int active[500];
int save_active[500];

void binary(int val)
{
    int i,rem;
    for(i=0;val!=0;i++)
    {
        rem=val%2;
        active[i]=rem;
        //cout<<rem<<" ";
        val/=2;
    }
    //printf("\n");
}

int main()
{
    int n,i,j,iter,cnt=0,cnt1=0,en=0;
    int s[500]={0},e[500]={0};

    cout<<"Number of jobs : ";
    cin>>n;
    cout<<"Start and end time :\n";
    for(i=0;i<n;i++)
    {
        cin>>s[i]>>e[i];
    }

    iter=round(pow(2,n));
    //cout<<iter<<endl;

    cout<<"\nData : \n\n";
    for(i=0;i<iter;i++)
    {
        //cnt=0;//
        //en=0;//
        memset(active,0,sizeof(active));
        binary(i);

        for(j=0;j<n;j++)
        //for(j=floor(log2(i));j>=0;j--)//
        {
            //cout<<s[j]<<" "<<e[j];//
            //if(active[j]==1 && s[n-j-1]>=en)//
            if(active[j]==1 && s[j]>=en)
            {
                cnt++;
                cout<<s[j]<<" "<<e[j]<<" "<<i;
                //cout<<s[n-j-1]<<" "<<e[n-j-1]<<" "<<i;//
                cout<<" Taken\n";
                en=e[j];
                //en=e[n-j-1];//
                //cnt1=max(cnt,cnt1);//
            }
            //printf("\n");
        }
        //cout<<"count = "<<cnt<<endl;//

    }
    cout<<"\nMaximum Job Can be Done = "<<cnt<<endl;
    //cout<<"\nMaximum Job Can be Done = "<<cnt1<<endl;//
    return 0;
}
