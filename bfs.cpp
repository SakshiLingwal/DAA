//BFS traversal : visit all the nodes level by level.
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>adj[],int n,int source)
{
    vector<bool>visited(n,0);
    queue<int>q;
    q.push(source);
    visited[source]=1;      //mark as 1
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";                                                            
        q.pop();
        for(int i:adj[node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int n,e;
    cout<<"Enter the no. of nodes :";
    cin>>n;
    cout<<"Enter the no. of edges :";
    cin>>e;
    vector<int>adj[n];   //vector array
    int u,v;
    for(int i=0;i<e;i++)
    {
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    int source;
    cout<<"Enter the source :";
    cin>>source;
    cout<<"Bfs traversal :"<<endl;
    bfs(adj,n,source);   //we can modify the source node
    return 0;
}
