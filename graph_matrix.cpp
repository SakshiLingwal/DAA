#include <iostream>
using namespace std;
void printMatrix(int matrix[][100], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    int mat[n][n] = {0};
    cout << "Enter the edges: ";
    for(int i = 0;i < e;i++) 
    {
      int u, v;
      cin >> u >> v;
      mat[u][v] = 1;
      mat[v][u] = 1;
    }
    cout << "Adjacency Matrix representing the graph: " << endl;
    printMatrix(mat, n);
    return 0;
}