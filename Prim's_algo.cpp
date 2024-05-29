//Prims Algorthim: Minimum Spanning Tree
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void prims(int adj[4][4],int vertex, int s)
{
    vector<int> parent(vertex);
    parent[s]=-1;
    vector<bool>visited(vertex,false);
    vector<int>dist(vertex,INT_MAX);
    dist[s]=0;
    int res=0;
    for(int count=0;count<vertex; count++)  //for each node
    {
        int u=-1;
        for(int i=0;i<vertex;i++)       //min. cost b/w u to v ka index
        {
            if(visited[i]==false &&(dist[i]<dist[u]))
                u=i;
        }
        visited[u]=true;
        res=res+dist[u];
        for(int v=0;v< vertex;v++)
        {
            if(adj[u][v]!=0 && visited[v]==false && adj[u][v]<dist[v])
            {
                dist[v]=adj[u][v];
                parent[v]=u;
            }
        }
    }
    for(int i=0;i<vertex;i++)
    {
        cout<<"Parent of "<<i<<" is: "<<parent[i]<<endl;
    }
    cout<<"cost of Minimum Spanning tree : "<<res;
}
int main()  
{
    int adj[4][4]={{0,5,8,0},
                    {5,0,10,15},
                    {8,10,0,20},
                    {0,15,20,0}};
    int node=4;
    int source;
    cout<<"Source: ";
    cin>>source;
    prims(adj,node,source);
}