//DEPTH FIRST SEARCH (DFS)-
#include<bits/stdc++.h>
using namespace std;
void dfs_rec(vector<int>adj[],int s,vector<bool>&visited) //recurssive func. used as stack
{
    visited[s]=true;
    cout<<s<<" ";
    for(auto i: adj[s])
    {
        if(!visited[i])
            dfs_rec(adj,i,visited);
    }
}
void dfs(vector<int>adj[],int n)  
{
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++)    
    {
        if(!visited[i])
            dfs_rec(adj,i,visited);
    }
}
int main()  
{
    int n,e,u,v;
    cout<<"Enter no of vertices: ";
    cin>>n;
    cout<<"Enter edges: ";
    cin>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"DFS tranversal: ";
    dfs(adj,n);
    return 0;
}
