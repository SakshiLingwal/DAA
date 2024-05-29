//Floyd warshall
#include<bits/stdc++.h>
#define INF 999
using namespace std;
int main()
{
    int n,e;
    cout<<"Enter no. of nodes & edges :";
    cin>>n>>e;
    int dis[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;i<n;j++)
        {
            if(i==j)
                dis[i][j]=0;
            else
                dis[i][j]=INF;
        }
    }  
    cout<<"Enter edges & weights :";  
    for(int i=0;i<n;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        dis[x][y]=wt;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                // dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                if (dis[i][j]>(dis[i][k] + dis[k][j])&& (dis[k][j] != INF && dis[i][k] != INF))
 					dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i][j]==INF)
                cout<<"INF";
            else
                cout<<dis[i][j]<<" ";
            cout<<endl;
        }
    }
}
// C++ Program for Floyd Warshall Algorithm
// #include <bits/stdc++.h>
// using namespace std;
// #define V 4
// #define INF 99999
// void floydWarshall(int dist[][V])
// {

// 	int i, j, k;
// 	for (k = 0; k < V; k++) {
// 		for (i = 0; i < V; i++) {
// 			for (j = 0; j < V; j++) {
// 				if (dist[i][j]>(dist[i][k] + dist[k][j])&& (dist[k][j] != INF && dist[i][k] != INF))
// 					dist[i][j] = dist[i][k] + dist[k][j];
// 			}
// 		}
// 	}
// 	cout << "The following matrix shows the shortest distances between every pair of vertices \n";
// 	for (int i = 0; i < V; i++) {
// 		for (int j = 0; j < V; j++) {
// 			if (dist[i][j] == INF)
// 				cout << "INF"<< " ";
// 			else
// 				cout << dist[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }
// int main()
// {

// 	int graph[V][V] = { { 0, 5, INF, 10 },
// 						{ INF, 0, 3, INF },
// 						{ INF, INF, 0, 1 },
// 						{ INF, INF, INF, 0 } };
// 	floydWarshall(graph);
// 	return 0;
// }