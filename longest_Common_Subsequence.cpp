//Longest common subsequence :
#include <iostream>
#include <string>
using namespace std;
int lcs(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+ dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    cout << "Length of Longest Common Subsequence: " << lcs(s1, s2) << endl;
    return 0;
}