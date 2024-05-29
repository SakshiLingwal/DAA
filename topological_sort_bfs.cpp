//TOPOLOGICAL SORT using bfs
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> topological_sort(vector<int>adj[],int v)  
{
    vector<bool> visited(v,false);
    queue<int> q;
    vector<int> indegree(v,0),ans;
    for(int i=0;i<v;i++)    
    {
        vector<int> data=adj[i];
        for(auto x: data)   
        {
            indegree[x]++;
        }
    }
    for(int i=0;i<v;i++)    
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())   
    {
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(auto x: adj[u]) 
        {
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
    }
    return ans;
}
void printGraph(vector<int> adj[],int v)    
{
    for(int i=0;i<v;i++)    
    {
        cout<<i<<" -> ";
        for(auto x: adj[i])
            cout<<x<<" ";
        cout<<"NULL"<<endl;
    }
}
int main()  
{
    int v,u,n,e;
    cout<<"Enter no of vertex: ";
    cin>>n;
    cout<<"Enter no of edges : ";
    cin>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++)
    {
        cout<<"Enter u and v: ";
        cin>>u>>v;
        adj[u].push_back(v);
    }
    printGraph(adj,n );
    vector<int> ans;
    ans = topological_sort(adj, n);
    cout<<"TOPOLOGICAL SORT order: "<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}