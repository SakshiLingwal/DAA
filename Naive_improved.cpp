#include <iostream>
using namespace std;
bool patSearching(string &txt, string &pat)
{
    int m=pat.length();
    int n=txt.length();
    int i=0;
    while(i<=(n-m))
    {
        int j;
        for(j=0;j<m;j++)
        {
            if(pat[j]!=txt[i+j])
                break;
        }
        if(j==m)
            return true;
            
        if(j==0)
        {
            i++;
        }
        else
        {
            i=(i+j);
        }
    }
    return false;
}

int main()
{
    string txt, pat;
    cout << "Enter the text string: ";
    getline(cin, txt);

    cout << "Enter the pattern string: ";
    getline(cin, pat);

    if(patSearching(txt, pat)==true)
        cout<<"yes";
    else
        cout<<"No";
    return 0;
}