//DETECT CYCLE IN DIRECTED GRAPH
#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int>adj[],int source,vector<bool>&visited,vector<bool>&curr_visited)
{
    visited[source]=true;
    curr_visited[source]=true;      //parent 
    for(auto i: adj[source])
    {
        if(!visited[i])
        {
            if(dfs(adj,i,visited,curr_visited))
               return true;
        }
        else if(visited[i]==true && curr_visited[i]==true)
            return true;
    }
    curr_visited[source]=false;
        return false;
}
bool cyclic(vector<int>adj[],int n)
{
    vector<bool>visited(n,false);
    vector<bool>curr_visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(adj,i,visited,curr_visited))
               return true;
        }
    }
    return false;
}
int main()
{
    int n,e,u,v;
    cout<<"Enter no of vertices & edges : ";
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        cout<<"Enter u and v: ";
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
    bool x =cyclic(adj,n);
    if(x==true)
        cout<<"GRAPH IS CYCLIC";
    else
        cout<<"GRAPH IS NOT CYCLIC";
    return 0;
}