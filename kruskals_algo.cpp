// //kruskals algorithm 
#include <bits/stdc++.h>
using namespace std;
class DisjointSet 
{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n) 
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) //gives ultimate parent
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    // void unionByRank(int u, int v) 
    // {
    //     int ulp_u = findUPar(u);
    //     int ulp_v = findUPar(v);
    //     if (ulp_u == ulp_v) return;
    //     if (rank[ulp_u] < rank[ulp_v]) {
    //         parent[ulp_u] = ulp_v;
    //     }
    //     else if (rank[ulp_v] < rank[ulp_u]) {
    //         parent[ulp_v] = ulp_u;
    //     }
    //     else {
    //         parent[ulp_v] = ulp_u;
    //         rank[ulp_u]++;
    //     }
    // }
    void unionBySize(int u, int v) 
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
    public:
        int spanningTree(int V, vector<vector<int>> adj[])
        {
            vector<pair<int, pair<int, int>>> edges;
            for (int i = 0; i < V; i++)         //input of graph with cost
            {
                for (auto it : adj[i]) {
                    int adjNode = it[0];
                    int wt = it[1];
                    int node = i;
                    edges.push_back({wt, {node, adjNode}});
                }
            }
            DisjointSet ds(V);
            sort(edges.begin(), edges.end());       //sort acc to ascending order of costs
            int mstWt = 0;
            for (auto it : edges) {
                int wt = it.first;
                int u = it.second.first;
                int v = it.second.second;

                if (ds.findUPar(u) != ds.findUPar(v)) //find ultimate parent of u & v,check if they're not equal means 
                {                                       //they belong to d/f component
                    mstWt += wt;
                    ds.unionBySize(u, v);       //can use either rank/size
                }
            }
            return mstWt;
        }
};
int main() {
    int V,u,v,wt,f=0;
    //V=5,E=6;
    cout<<"Enter the number of vertices: ";
    cin>>V;
    // cout<<"Enter the number of edges: ";
    // cin>>E;
    vector<vector<int>> edges;
    //  = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    for(int i=0;i<V;i++){
        cout<<"Enter the values(u,v,wt): ";
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});      //no need to write bidirectionally as disjoint set will discard one of them
    }
    vector<vector<int>> adj[V];
    for(auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }
    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout<< "The sum of all the edge weights: "<< mstWt << endl;
    return 0;
}