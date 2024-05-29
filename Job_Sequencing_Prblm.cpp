//JOB SEQUENCING
#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<char,pair<int,int>> &a,pair<char,pair<int,int>> &b)  
{
    return (a.second.first > b.second.first); //compare on the basis of profit
}
void job_sequencing(vector<pair<char,pair<int,int>>> job_seq,int n)   
{
    vector<int>slots(n,0);
    vector<int>result(n,0);
    int max_profit=0,i=0;
    for(auto x: job_seq)   
    {
        for (int j=min(n, x.second.second);j>0;j--) //n=5 , deadline=3 :j=3 to j>0
        {
            if (slots[j] == 0)   //if slot is empty
            {
                max_profit+=x.second.first; //add profit
                result[j]= i;       //res store the job id
                slots[j] =1;        //as the slot is filled mark it as occupied
                break;
            }
        }
        i++;
    }
    cout<<"JOB DONE IN SEQUENCE: "<<endl;
    for(int i=0;i<n;i++)
    {
        if(slots[i])    //if slot is occupied print the id available at the slots
        {
            cout<<job_seq[result[i]].first<<" ";
        }
        cout<<endl;
    }
    cout<<"MAXIMUM PROFIT: "<<max_profit;
}
int main()  
{
    int n;
    cout<<"No of jobs: ";
    cin>>n;
    vector<pair<char,pair<int,int>>> job_seq;
    cout<<"J.NO PRO DEADLINE"<<endl;
    for(int i=0;i<n;i++) 
    {
        int profit, deadline;
        char job_id;
        cin>>job_id>>profit>>deadline;
        pair<int,int> p1={profit, deadline};
        job_seq.push_back(make_pair(job_id, p1));
    }
    //Sort according to profit in desending order....
    sort(job_seq.begin(), job_seq.end(), comparator);
    job_sequencing(job_seq,n);
    return 0;
}