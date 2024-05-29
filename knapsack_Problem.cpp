//0/1 Knapsack problem
#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int>weight,vector<int>val,int n,int w)
{
    if(w<=0)
        return 0;       //we can't put anything on knapsack
    if(n<=0)
        return 0;
    if(weight[n-1]>w)       //current item wt. > knapsack wt. 
        return knapsack(weight,val,n-1,w);  //same recursion w/o considering that wt.

    return max(knapsack(weight,val,n-1,w),knapsack(weight,val,n-1,w-weight[n-1])+val[n-1]); 
    //compare the wt. when we 've not taken it & when we've taken it.
}
int main()
{
    int n;
    cout<<"Enter no. of items :";
    cin>>n;
    vector<int>weight(n);
    vector<int>val(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int w;
    cout<<"Enter weight of knapsack :";
    cin>>w;
    cout<<knapsack(weight,val,n,w);
    return 0;
}