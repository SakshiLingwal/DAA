/*write a cpp program to search the pattern in a string using knurth morris path algorithm (KMP)*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> lps(string s)
{                               //longest common prefix suffix substring
    int n=s.size();
    vector<int>pi(n,0);
    for (int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
        {
            j=pi[j-1];
        }
        if (s[i]==s[j])
            j++;
        pi[i]=j;
    }
    for (int i=0;i<pi.size();i++)
        cout<<pi[i]<<endl;
    return pi;
}
int kmp_searching(string str1,string pattern)
{
    int n=str1.size();
    int m=pattern.size();
    //vector<vector<int>>patern_index(2,vector<int>(m,0));
    vector<int>pattern_index;
    pattern_index=lps(pattern);
    int j=0,i=0,flag=0;
    while(i<=n)
    {
        if (str1[i]==pattern[j])
        {
            j++;
            i++;
        }
        else
        {
            if (j!=0)
                j=pattern_index[j-1];
            else
                i++;
        }
        if(j==m)
        {
            cout<<"Pattern foound at index: "<<i-j<<endl;
            flag=1;
            j=0;
        }
    }
    return  flag;
}
int main()
{
    string str1,pattern;
    cout<<"Enter the string: ";
    cin>>str1;
    cout<<"Enter the pattern you want to search: ";
    cin>>pattern;
    int i=kmp_searching(str1,pattern);
    if (i==0)
        cout<<"Pattern not found..."<<endl;
    return 0;
}



// vector<int> compute_lps_array(string pattern) {
//     int m = pattern.length();
//     vector<int> lps(m, 0);
//     int length = 0;
//     int i = 1;

//     while (i < m) {
//         if (pattern[i] == pattern[length]) {
//             length++;
//             lps[i] = length;
//             i++;
//         } else {
//             if (length != 0) {
//                 length = lps[length - 1];
//             } else {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }

//     return lps;
// }

// void kmp_search(string text, string pattern) {
//     int n = text.length();
//     int m = pattern.length();
//     vector<int> lps = compute_lps_array(pattern);

//     int i = 0, j = 0;
//     while (i < n) {
//         if (pattern[j] == text[i]) {
//             i++;
//             j++;
//         }

//         if (j == m) {
//             cout << "Pattern found at index " << i - j << endl;
//             j = lps[j - 1];
//         } else if (i < n && pattern[j] != text[i]) {
//             if (j != 0) {
//                 j = lps[j - 1];
//             } else {
//                 i++;
//             }
//         }
//     }
// }

// int main() {
//     string text = "ABABDABACDABABCABAB";
//     string pattern = "ABABCABAB";
//     kmp_search(text, pattern);
//     return 0;
// }
