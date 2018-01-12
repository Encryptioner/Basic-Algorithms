#include<bits/stdc++.h>
#define maxn 100
using  namespace std;

int cost[maxn][maxn];
string edit[maxn*maxn][2];
int c=0;

string intToString( int number )
{
  ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string
  return oss.str();
}

int table(string x,string y,int n,int m)
{
    int i,j,p,q,r,u,v;
    for(i=0;i<=n;i++)
    {

        //cout<<576576;
        for(j=0;j<=m;j++)
        {
            cout<<i<<" "<<j<<" "<<x[i-1]<<" "<<y[j-1]<<endl;
            //cout<<908;
            if(i==0 && j==0)
            {
                cost[i][j]==0;
            }
            else if(j==0 && i>0)
            {
                cost[i][j]=cost[i-1][0]+1;//delete
                //x[i]=' ';
                v=1;
                continue;
            }
            else if(i==0 && j>0)
            {
                cost[i][j]=cost[0][j-1]+1;//insert
                //x=x+y[j];
                v=3;
                continue;
            }
            else if(x[i-1]==y[j-1])
            {
                cost[i][j]=cost[i-1][j-1];
                continue;
            }
            else
            {
                cout<<"else "<<x[i-1]<<" "<<y[j-1]<<endl;
                p=cost[i-1][j]+1;//delete
                //x[i]=' ';
                q=cost[i-1][j-1]+2;//change
                //x[i]=y[j];

                r=cost[i][j-1]+1;//insert
                //x=x+y[j];

                v=2;
                u=min(p,q);
                if(u==p)
                {
                    v=1;
                }
                cost[i][j]=min(u,r);
                if(u==r)
                {
                    v=3;
                }

            }

            string a=intToString(i);
            string b=intToString(j);
            cout<<p<<" "<<q<<" "<<r<<" "<<cost[i][j]<<endl;
            if(v==1)
            {
                edit[c][0]="Delete ", edit[c][1]="x";
                edit[c][1]+=a;
            }
            if(v==2)
            {
                edit[c][0]="Change ", edit[c][1]="x";
                edit[c][1]+=a;
                edit[c][1]+=" with y";
                edit[c][1]+=b;
            }
            if(v==3)
            {
                edit[c][0]="Insert ", edit[c][1]="y";
                edit[c][1]+=b;
            }
            c++;
        }
    }
}

int main()
{
    string x,y;
    int m,n,i,j;

    //cin>>x>>y;
    x="aabab";
    y="babb";

    n=x.length();
    m=y.length();


    table(x,y,n,m);

    for(i=0;i<c;i++)
    {
        cout<<edit[i][0]<<edit[i][1];
        printf("\n");
    }
    printf("\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        printf("\n\n");
    }
    return 0;
}
