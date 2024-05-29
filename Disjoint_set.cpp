#include<bits/stdc++.h>
using namespace std;
class Disjoint_set
{
    vector<int>rank,size;
    vector<int>parent;
    public:
        Disjoint_set(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
                size[i]=1;
            }
        }
        int find_ultimate_Parent(int node)      //path compression
        {
            if(node==parent[node])
                return node;
            return parent[node]=find_ultimate_Parent(parent[node]);

        }
        void Union_by_rank(int u,int v)
        {
            int pu=find_ultimate_Parent(u);
            int pv=find_ultimate_Parent(v);
            if(pu==pv)                          //both have same parent
                return ;
            if(rank[pu]<rank[pv])
                parent[pu]=pv;
            else if(rank[pu]>rank[pv])      //rank of pu > pv means pv->pu 
                parent[pv]=pu;
            else                        //when both have same ranks means 1->2 or 2->1
            {
                parent[pv]=pu;
                rank[pu]++;             //as v connect to u means rank of u increases.
            }
        }
        void Union_by_size(int u,int v)
        {
            int pu=find_ultimate_Parent(u);
            int pv=find_ultimate_Parent(v);
            if(pu==pv)                          //both have same parent
                return ;
            if(size[pu]<size[pv])
            {
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
            else if(size[pu]>size[pv])      //size of pu > pv means pv->pu 
            {
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
        }
};

int main()
{
    // Disjoint_set d(7);
    // d.Union_by_rank(1,2);
    // d.Union_by_rank(2,3);
    // d.Union_by_rank(4,5);
    // d.Union_by_rank(6,7);
    // d.Union_by_rank(5,6);
    int n,e,u,v;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    Disjoint_set d(n);
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Enter the edges(u,v): ";
    for(int i=0;i<e;i++)
    {    
        cin>>u>>v;
        d.Union_by_rank(u,v);
    }
    if(d.find_ultimate_Parent(3)==d.find_ultimate_Parent(7))
    {   
        cout<<"Belongs to same component\n";
    }
    else
        cout<<"Not belongs to same component\n";

    d.Union_by_rank(3,7); 
    if(d.find_ultimate_Parent(3)==d.find_ultimate_Parent(7))
        cout<<"Belongs to same component\n";
    else
        cout<<"Not belongs to same component\n";
    return 0;
}