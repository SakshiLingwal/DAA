// DIJKSTRA's ALGORITHM
// graph in the form of adjoint list :
// 0 -> {1, 2} {4, 4} // first represent nodes it is connected to and second represent their corresponding
// 1 -> {0, 2} {4, 2}  //  distances between those nodes from source node 
// 2 -> {0, 1, 3, 4, 5} {4, 2, 3, 1, 6}
// 3 -> {2, 5} {3, 2}
// 4 -> {2, 5} {1, 3}
// 5 -> {3, 4} {2, 3}


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // USING PRIORITY QUEUE
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // creating min heap
        vector<int> dis(V, INT_MAX);
        dis[S] = 0; // distance from source node to source node is 0
        q.push({0, S});
        while (!q.empty())
        {
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();
            // iterating throught the list
            for (auto it : adj[node])
            {
                int wt = it[1];
                int adjNode = it[0];
                if (dist + wt < dis[adjNode])
                {   // if distance from current node less than prev distance
                    // stored then change the value
                    dis[adjNode] = dist + wt;
                    q.push({dist + wt, adjNode});
                }
            }
        }
        return dis;
    }
};

int main()
{
    int V, E;
    cout << "Enter total vertices and total edges: ";
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
        int u, v, w;
        cout << "Enter edge and weight: ";
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    cout << "Enter source node: ";
    int S;
    cin >> S;

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}

// Sample input :

// Enter total vertices and total edges: 6 8
// Enter edge and weight: 0 1 4
// Enter edge and weight: 0 2 4
// Enter edge and weight: 1 2 2
// Enter edge and weight: 2 3 3
// Enter edge and weight: 2 5 6
// Enter edge and weight: 2 4 1
// Enter edge and weight: 3 5 2
// Enter edge and weight: 4 5 3
// Enter source node: 0

// Sample output:

// 0 4 4 7 5 8