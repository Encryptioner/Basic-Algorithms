#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>>matrix1(10,vector<int>(10));
    map<int,int>mymap;//mapping can be map<string,int>mymap. then node1 node2 wil be string and assign will be int as earlier
    int i,j;
    int node1,node2,cost,node,edge;
    int assign=1,x,y;

    cout<<"Enter number of node & edge : ";
    cin>>node>>edge;
    for(i=1;i<=edge;i++)
    {
        cout<<"Enter edge node1-node2 : ";
        cin>>node1>>node2;
        //cout<<"Enter cost : ";
        cin>>cost;//if weighted else cost=1
        //cost=1;
        if(mymap.find(node1)==mymap.end())//mymap e search korte korte end e pouche jay. it means ekhono ei node er mapping hoyni
        {
            mymap[node1]=assign;
            //printf("Mapping %d with %d\n",node1,assign);
            cout<<"Mapping "<<node1<<" with "<<assign<<endl;
            assign++;
        }
        x=mymap[node1];
        if(mymap.find(node2)==mymap.end())
        {
            mymap[node2]=assign;
            cout<<"Mapping "<<node2<<" with "<<assign<<endl;
            assign++;
        }
        y=mymap[node2];
        matrix1[x][y]=cost;
        //matrix1[y][x]=cost;//if graph is bidirectional or undirected. it means symmetric
    }
    cout<<"Graph in matrix :\n";
    for(i=1;i<=node;i++)
    {
        for(j=1;j<=node;j++)
        {
            cout<<matrix1[i][j]<<" ";
        }
        printf("\n");
    }
    return 0;
}
