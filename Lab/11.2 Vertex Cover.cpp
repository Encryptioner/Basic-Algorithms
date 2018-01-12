#include<bits/stdc++.h>//dp works when must n-1 edges where n=node number
#define MAXN 100002//Spoj PT07X(vertex cover)
using namespace std;

int dp[MAXN][5];
int par[MAXN];
bool active[2][MAXN];
vector<int>edges[MAXN];

int f(int x,int u, int isGuard)
{
    //active[u]=isGuard;
    if (edges[u].size() == 0)
    {
        active[x][u]=isGuard;
        return 0;
    }
    if (dp[u][isGuard] != -1)
        //active[x][u]=isGuard;
        return dp[u][isGuard];
    int sum = 0;
    for (int i = 0; i < (int)edges[u].size(); i++) {
        int v = edges[u][i];
        if (v != par[u]) {
            par[v] = u;
            if (isGuard == 0)
            {
                sum += f(x,v, 1);
                active[x][v]=1;
                cout<<u<<"v "<<v<<" "<<active[x][v]<<" "<<sum<<endl;
            }
            else
            {
                int a=f(x,v, 1);
                int b=f(x,v, 0);
                sum += min(a,b);
                cout<<u<<" "<<v<<" "<<a<<" "<<b<<" "<<sum<<endl;
                if(a<b)
                {
                    active[x][v]=1;
                }
                else
                {
                    active[x][v]=0;
                }
                cout<<v<<" "<<active[x][v]<<endl;
            }
        }
    }
    //active[x][u]=isGuard;
    return dp[u][isGuard] = sum + isGuard;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i < n; i++) {
            cout<<i<<" : "<<endl;
        for (int j =0 ; j < edges[i].size(); j++) {
            cout<<edges[i][j]<<" ";
        }
        printf("\n");
    }
    int ans = 0;
    int j;
    int a=f(0,1, 1);
    cout<<"a =  "<<a<<endl;
    int b=f(1,1, 0);
    cout<<"b =  "<<b<<endl;
    if(a<b)
    {
        active[0][1]=1;
        j=0;
    }
    else
    {
        active[1][1]=0;
        j=1;
    }
    ans = min(a,b);
    printf("\n%d\n", ans);
    cout<<"\nNode Taken :\n\n";
    for(int i=1;i<=n;i++)
    {
        if(active[j][i]==1)
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
