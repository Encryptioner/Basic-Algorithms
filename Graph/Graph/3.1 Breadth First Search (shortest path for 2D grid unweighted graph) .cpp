#include<bits/stdc++.h>//ok
#define pii pair<int,int>

using namespace std;

int row,col;
vector<vector<int>>cell(10,vector<int>(10)), d(10,vector<int>(10)), vis(10,vector<int>(10));
//int cell[100][100]; //cell[x][y] যদি -১ হয় তাহলে সেলটা ব্লক
//int d[100][100],vis[100][100]; //d means destination from source. vis means visited
int gridbfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	//memset(vis,0,sizeof vis);
	//memset(d,0,sizeof d);
	int fx[]={1,-1,0,0}; //ডিরেকশন অ্যারে like if it goes 1 cell right then turned x=first x + 1
    int fy[]={0,0,1,-1};//like if it goes 1 cell right then turned y=first y + 0
	vis[sx][sy]=1;
	queue<pii>q; //A queue containing STL pairs
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front();
		q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k]; //Neighbor cell [tx][ty]
			cout<<tx<<" "<<ty<<endl;
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
			{
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				cout<<d[tx][ty]<<endl;
				q.push(pii(tx,ty)); //Pushing a new pair in the queue
			}
			printf("\n");
		}
		printf("\n\n");
	}
	for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("(%d,%d) to (%d,%d) Shortest distance %d\n\n",sx,sy,i,j,d[i][j]);//konakuni jete pare na
        }
    }
    return 0;
}

int main()
{
    //row=5;
    //col=5;
    int b,i,j,r,c,sx,sy,test=2;
    while(test--)
    {
        cout<<"Enter row and column of 2D grid : \n";
        cin>>row>>col;
        cout<<"How many Blocked cell? ";
        cin>>b;
        cout<<"Row and column starts from 0. Now Enter Blocked cell's row and column : \n";
        for(i=0;i<b;i++)
        {
            cin>>r>>c;
            cell[r][c]=-1;
        }
        cout<<" 2D Graph in matrix : \n\n";
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                cout<<cell[i][j]<<"\t";
            }
            printf("\n\n");
        }
        cout<<"Row and column starts from 0. Now Enter source node row and column : \n";
        cin>>sx>>sy;
        gridbfs(sx,sy);
        for(i=0;i<row;i++)//clearing previous grid graph
        {
            for(j=0;j<col;j++)
            {
                cell[i][j]=0;
            }
        }
    }
    return 0;
}
