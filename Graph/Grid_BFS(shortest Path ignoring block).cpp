#include<bits/stdc++.h>//Accepted
#define MAX 1001
#define pii pair<int,int>
using namespace std;

int row,col;

void gridbfs(int sx,int sy,int dx,int dy,vector<vector<int>>&cell)
{
	vector<vector<int>>d(MAX,vector<int>(MAX)), vis(MAX,vector<int>(MAX));
	int fx[]={1,-1,0,0};
    int fy[]={0,0,1,-1};

	vis[sx][sy]=1;
	queue<pii>q;
	q.push(pii(sx,sy));

	while(!q.empty())
	{
		pii top=q.front();
		q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0)
            {
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
		if(vis[dx][dy]==1)
        {
            break;
        }
	}
	cout<<d[dx][dy]<<endl;
}

int main()
{
    int i,j,k,n,r,c,mines,sx,sy,dx,dy;

    while(cin>>row && cin>>col && row!=0 && col!=0)
    {
        vector<vector<int>>cell(MAX,vector<int>(MAX));
        cin>>n;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&r,&mines);
            for(j=0;j<mines;j++)
            {
                scanf("%d",&c);
                cell[r][c]=-1;
            }
        }
        cin>>sx>>sy;
        cin>>dx>>dy;
        gridbfs(sx,sy,dx,dy,cell);
    }
    return 0;
}

