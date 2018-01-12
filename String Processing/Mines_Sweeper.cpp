#include<bits/stdc++.h>//Accepted

using namespace std;

int main()
{
    int row,col,f=0,i,x,count;

    while(cin>>row && cin>>col && row!=0 && col!=0)
    {
        string s[100];
        if(f>0)
        {
            cout<<"\n";
        }
        for(i=0;i<row;i++)
        {
            cin>>s[i];
        }

        f++;
        printf("Field #%d:\n",f);
        for(x=0;x<row;x++)
        {
            for(i=0;i<col;i++)
            {
                count=0;
                if(s[x][i]=='*')
                {
                    cout<<s[x][i];
                }
                else
                {
                if(x-1>=0)
                {
                    if((i-1)>=0 && s[x-1][i-1]=='*')
                    {
                        count++;
                    }
                    if(s[x-1][i]=='*')
                    {
                        count++;
                    }
                    if((i+1)<=col && s[x-1][i+1]=='*')
                    {
                        count++;
                    }
                }
                if((i-1)>=0 && s[x][i-1]=='*')
                {
                    count++;
                }
                if((i+1)<=col && s[x][i+1]=='*')
                {
                        count++;
                }
                if(x+1<row)
                {
                    if((i-1)>=0 && s[x+1][i-1]=='*')
                    {
                        count++;
                    }
                    if(s[x+1][i]=='*')
                    {
                        count++;
                    }
                    if((i+1)<=col && s[x+1][i+1]=='*')
                    {
                        count++;
                    }
                }
                cout<<count;
                }
            }
            {
                cout<<"\n";
            }
        }
    }
    return 0;
}

