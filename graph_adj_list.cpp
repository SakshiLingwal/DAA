//graph (adj. list) creation :Undirected graph
#include <iostream> 
#include<bits/stdc++.h>
using namespace std;
void addedge(unordered_map<int,list<int>>&adj,int u,int v,bool status)   //status = 0->undirected,status =1->directed
{
    //create an edge from u to v or v to u
    adj[u].push_back(v);        //u is fixed & v part can be extended as a list
    if(status==0)
    {
        adj[v].push_back(u);    //means graph is undirected & edge can be on both sides u->v || v->u
    }
}
void print(unordered_map<int,list<int>>&adj,int n)
{
    for(auto i:adj)   
    {
        cout<<i.first<<"->";
        for(auto x: i.second)
          cout<<x<<" ,";
        cout<<endl;
    }
}
int main()
{
   int n,m;
   cout<<"Enter the no. of nodes :";
   cin>>n;
   cout<<"Enter the no. of edges :";
   cin>>m;
   unordered_map<int,list<int>>adj;  //or we can creates a 2-d vector 
   int u,v;
   for(int i=0;i<m;i++)
   {
       cin>>u>>v;
      addedge(adj,u,v,0);
   }
   print(adj,n);
   return 0;
}
/*INPUT A GRAPH USING ADJACENCY LIST
#include<iostream>
#include<vector>
using namespace std;
void addEdge(vector<int> adj[],int u,int v) 
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}
void printGraph(vector<int> adj[],int v)    
{
    for(int i=0;i<v;i++)   
    {
        for(auto x: adj[i])
           cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
}
int main() 
{
    int v,u,n,e;
    cout<<"Enter no of nodes: ";
    cin>>n;
    cout<<"Enter no of edges: ";
    cin>>e;
    vector<int>adj[n];      //array of vectors 
    cout<<"Enter the edges : ";
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    printGraph(adj,n);
}*/