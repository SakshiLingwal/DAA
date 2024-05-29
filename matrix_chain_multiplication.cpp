#include <iostream>
#include <climits>
using namespace std;
int mChain(int p[], int n) 
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = 0;
    }    
    for (int gap = 2; gap < n; gap++) 
    {
        for (int i = 0; i + gap < n; i++) 
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) 
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[k] * p[j]);
            }
        }
    }
    return dp[0][n-1];
}
int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int dimensions[n];
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i < n; i++) {
        cin >> dimensions[i];
    }
    int minMultiplications = mChain(dimensions,n);
    cout<< "Minimum number of multiplications: " << minMultiplications << endl;
    return 0;
}