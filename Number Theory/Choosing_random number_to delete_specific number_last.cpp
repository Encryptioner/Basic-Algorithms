#include<bits/stdc++.h>//Accepted

using namespace std;

int main()
{
    int n,i,j,c;
    freopen("151. Power Crisis  .txt","r",stdin);
    while(cin>>n && n!=0)//n=number of region
    {
        if(n<=13)
        {
            printf("1\n");
        }
        else
        {
        for(i=5;;i++)
        {
            vector<int>region(n);

            for(j=0;j<n;j++)
            {
                region[j]=j+1;
            }
            c=0;
            while(region[c]!=13)
            {
                region.erase(region.begin()+c);
                c+=i-1;

                if(c>=region.size())
                {
                    c=c%region.size();
                }
            }

            if(region[0]==13 && region.size()==1)//13 is that value which will be deleted last
            {
                printf("%d\n",i);//print that random number
                break;
            }
        }
        }
    }
    return 0;
}


