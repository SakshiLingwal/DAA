//Fractional Knapsack :Greedy approach is best
#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<int,int>x,pair<int,int>y)
{
    double v1=(double)x.first/x.second;
    double v2=(double)y.first/y.second;
    return v1>v2;               //descending order acc. to cost(value/weight)
}
int main()
{
    int n,w;
    cout<<"No. of items :";
    cin>>n;
    vector<pair<int,int>>a(n);      //pair weight & value 
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),comparator);     //sort acc. to the max value.
    cout<<"Enter weight of knapsack :";
    cin>>w;

    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(w>=a[i].second)
        {
            ans+=a[i].first;    //add profit
            w=w-a[i].second;    //remaining weight of knapsack
            continue;
        }
        double vw=(double)a[i].first/a[i].second;
        ans+=vw*w;      //vw * with remaning weight
        //w=0;
        break;
    }
    cout<<"Max cost :"<<ans<<endl;
    return 0;
}