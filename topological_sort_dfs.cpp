//write a cpp program to get the valid toplogical sort path using dfs.
#include<bits/stdc++.h>
using namespace std;
void topsort (int node,vector<bool>&visited,stack<int>&s,vector<int>adj[])
{
  visited[node] = true;
  for(auto i:adj[node])
  {
    if(!visited[i])
	    topsort(i,visited,s,adj);
  }
  s.push (node);		//to print the topological sort reverse this stack in main and then print
}
int main ()
{
   int v,e;
   cout<<"Enter the number of vertexes: ";
   cin>>v;
   cout<<"Enter the number of edges: ";
   cin>>e;
   vector<int>adj[v];
   cout<<"Enter the edges (source destination):"<<endl;
   for(int i=0;i<e;i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
   vector<bool>visited(v,false);
   vector<int>res;
   stack<int>s;
   for(int i=0;i<v;i++)
    {
      if(!visited[i])
	    topsort (i, visited, s, adj);
    }
    while(!s.empty())
    {
      res.push_back(s.top());     // res.insert(res.begin(),s.top());
      s.pop();
    }
    cout<<"Topological sort is: ";
    for(auto i:res)
    {
       cout<<i<<" ";
    }
    return 0;
}
