//Bipartite graph - in which no 2 adjacent nodes have same color.
#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int color,vector<bool>&visited,vector<int>adj[])
{
    visited[node]=color;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            if(dfs(i,!color,visited,adj))
                return false;
        }
        else if(visited[i]==color)      //
            return false;       
    }
    return true;
}
bool bipartite(vector<int>adj[],int n)
{
    vector<bool>visited(n,-1);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==-1)
        {
            if(!(dfs(i,0,visited,adj)))
                return false;
        }
    }
    return true;
}
int main()
{
    int n,e,u,v;
    cout<<"Enter no. of nodes & edges :";
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(bipartite(adj,n))
        cout<<"Graph is bipartite";
    else
        cout<<"Graph is not bipartite";
    return 0;
}