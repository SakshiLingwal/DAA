//DETECT CYCLE IN UNDIRECTED GRAPH
#include<bits/stdc++.h>
using namespace std;
bool dfs_rec(vector<int>adj[],int s,vector<bool>&visited,int parent)    
{
    visited[s]=true;
    for(auto i: adj[s]) 
    {
        if(!visited[i])                             //visit all adjacent nodes if not visited
        {
            if(dfs_rec(adj,i,visited,s))
                return true;                    //if any 1 of the dfs calls became true then whole recurssion will return true.
        }
        else if(i!=parent)   //means i is already visited & it is not the parent hence cycle exists & some other node had already traverse it.
            return true;    //cycle exists
    }
    return false;
}
bool cycle(vector<int> adj[],int n)   
{
    vector<bool> visited(n, false);
    for(int i=0;i<n;i++)    
    {
        if(!visited[i]) 
        {
            if(dfs_rec(adj,i,visited,-1))    //-1 is the parent of source node
                return true;                //means cycle exists
        }
    }
    return false;
}
int main()  
{
    int e,v,u,n;
    cout<<"Enter no of vertex: ";
    cin>>n;
    cout<<"Enter no of edges: ";
    cin>>e;
    vector<int> adj[n];
    for(int i=1;i<=e;i++)
    {   cout<<"Enter u and v: ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<v;i++) 
    {
        for(auto x: adj[i])
            cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    if(cycle(adj,n))
        cout<<"CYCLE EXITS";
    else
        cout<<"CYCLE Does NOT EXITS";
}