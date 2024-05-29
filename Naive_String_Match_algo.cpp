//Naive pattern search
#include<bits/stdc++.h>
using namespace std;
bool search(string txt,string pattern)
{
    int m=txt.size();
    int n=pattern.size();
    for(int i=0;i<=(m-n);i++)
    {
        int f=0;
        for(int j=0;j<n;j++)
        {
            if(pattern[j]!=txt[j+i])
            {
                f=1;
                break;
            }
        }
        if(f==0)
            return true;
    }
    return false;
}
int main()
{
    string txt,pattern;
    cout<<"Enter a txt string :";
    cin>>txt;
    cout<<"Enter a pattern string :";
    cin>>pattern;
    if(search(txt,pattern)==true)
    {
        cout<<"YES !!Pattern matches with the txt string";
    }
    else
    {
        cout<<"NO !!Pattern do not match";
    }
    return 0;
}