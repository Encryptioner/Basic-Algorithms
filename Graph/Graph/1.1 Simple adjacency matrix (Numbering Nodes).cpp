#include<bits/stdc++.h>//in row and column there are node numbers

using namespace std;

int main()
{
    //int matrix[10][10];
    vector<vector<int>>matrix1(10,vector<int>(10));
    int i,j;
    int node1,node2,cost,node,edge;

    cout<<"Enter Number of nodes & edges in the graph : ";
    cin>>node>>edge;
    for(i=1;i<=edge;i++)//input or connections depends on how many edges
    {
        cout<<"Enter edge node1-node2 : ";
        cin>>node1>>node2;
        cout<<"\nEnter cost (if weighted else cost=1) : ";
        cin>>cost;
        //cost=1;
        matrix1[node1][node2]=cost;//it means if there is connection between two nodes then there will be cost else 0 for using vector. if we don't use vector we have to make 2-d array manually zero
        //matrix1[node2][node1]=cost;//if graph is bidirectional or undirected. it means symmetric
    }
    cout<<" Graph in matrix : \n";//in row and column there are node numbers
    for(i=1;i<=node;i++)//as we numbered node no from 1 not 0
    {
        for(j=1;j<=node;j++)
        {
            cout<<matrix1[i][j]<<" ";
        }
        printf("\n");
    }
    return 0;
}
