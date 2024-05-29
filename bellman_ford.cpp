//BELLMAN FORD 
#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int src,dst,wt;
};
void bellmanFord(vector<edge>& Edges,int V,int E)
{
	// int parent[V];	
	// int cost_parent[V];	
	vector<int>dist(V,INT_MAX);	//distance array which stores the shortest path
	// parent[0] = -1;	
	dist[0] = 0;
	int flag=0;
	for(int i=0;i<V-1;++i)
	{
		flag=0;
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(dist[U]!=INT_MAX and dist[U]+wt < dist[V])
			{
				dist[V] = dist[U]+wt;
				// parent[V] = U;
				// cost_parent[V] = dist[V];
				flag=1;
			}
		}
		if(flag==0)	//save time if there is no relaxation of edges(means no change in dist array values)
			break;
	}
	for(int j=0;j<E;j++)	//extra iteration checks -ve cycle
	{
		int U = Edges[j].src;
		int V = Edges[j].dst;
		int wt = Edges[j].wt;
		if(dist[U]!=INT_MAX and dist[U]+wt < dist[V])
		{
			cout<<"Graph has -VE edge cycle\n";
			return;
		}
	}
	for(int i=1;i<V;++i)
	cout<<"Cost to reach "<<i<<" from source 0 = "<<dist[i]<<"\n";
		//cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<i<<" from source 0 = "<<dist[i]<<"\n";
}

int main()
{
	int V,E;
	cin>>V>>E;	//Enter no of Vertices and Edges
	vector<edge> Edges(E);

	//Now input all E edges
	int src,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>src>>dst>>wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}
	bellmanFord(Edges,V,E);	
	return 0;
}
