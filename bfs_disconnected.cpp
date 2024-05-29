//BFS on disconnected graph
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bfs_dis(vector<int>adj[],int s, vector<int>& visited)
{
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int node= q.front();
        cout<<node;
        q.pop();
        for(int x: adj[node])  
        {
            if(!visited[x])   
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
void bfs(vector<int> adj[],int n)   
{
    vector<int>visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            bfs_dis(adj, i, visited);
    }
}
int main()  
{
    int n,e,u,v;
    cout<<"Enter no of nodes : ";
    cin>>n;
    cout<<"Enter no. of edges :";
    cin>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++) 
    {
        cout<<"Enter the list(u,v): ";
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0;i<v;i++)    
    {
        cout<<i<<" -> ";
        for(auto x: adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
    bfs(adj,n);
    return 0;
}