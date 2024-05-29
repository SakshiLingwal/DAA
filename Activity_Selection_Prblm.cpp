//Activity Selection Problem :
#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&a,pair<int,int>&b)
{
    return a.second<b.second;       //sort acc. to finishing time
}
int main()
{
    int n;
    cout<<"Enter no.of process :";
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int start,end;
        cin>>start>>end;
        v.push_back({start,end});
    }
    sort(v.begin(),v.end(),comp);   //1.sort the activities acc.to their finishing tym

    int take=1; 
    int start=v[0].first;      
    int end=v[0].second;
    cout<<"Process are :"<<"\n";
    cout<<start<<" "<<end<<endl;    //2.Print the 1 activity after sorting as it is
    for(int i=1;i<n;i++)
    {
        start=v[i].first;
        if(start>=end)  //3.check the start tym of new activity >=end tym of previous activity 
        {
            take++;
            end=v[i].second;
            cout<<start<<" "<<end<<" "<<endl;
        }
    }
    cout<<"Total Process are :"<<take<<"\n";
    return 0;
}