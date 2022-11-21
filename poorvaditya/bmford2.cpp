#include<iostream>
#include<stdio.h>
using namespace std;

//edge
struct Edge
{
	int src, dest, wgt;
};

//bellman ford (int Vertex ,int Edges, int dist[],struct Edge edg[])
void bellmen(int V, int E, int dist[], struct Edge edg[])
{
	int u, v, w;
	
    //relax all the edges v-1
    //every edge will be relaxed v-1 times
	for(int i=0; i<V-1; i++)
	{


        //for all the edges
		for(int j=0; j<E; j++)
		{

			u = edg[j].src;

			v = edg[j].dest;

			w = edg[j].wgt;

            //then relax
			if(dist[u]+w < dist[v])
			{
				dist[v] = dist[u]+w;
                cout<<"\nRelaxed vertex :"<<v<<" .Updated distance :"<<dist[v]<<endl;
			}
		}
	}
	
    //check for negative wt cycle
	for(int j=0; j<E; j++)
	{
		u = edg[j].src;
		v = edg[j].dest;
		w = edg[j].wgt;
		if(dist[u]+w < dist[v])
		{
			cout<<"\n.....This Graph Has Negative Weight Cycle.....";
		}
	}

	cout<<"\n\nVertex\tDistance\n";
	for(int i=0; i<V; i++)
	{
		cout<<i<<"\t "<<dist[i]<<"\n";
	}
}

int main() 
{
	int V, E, source;
	int dist[V]; //will store all the vertex
	
	cout<<"\nEnter the number of vertices : ";
	cin>>V;


	cout<<"\nEnter the number of edges : ";
	cin>>E;
	
    struct Edge edg[E]; //since we have E vertex
	
    for(int i=0; i<E; i++)
	{
		cout<<"\nEnter the source, destination and weight of edge "<<i+1<<" : ";
		cin>>edg[i].src>>edg[i].dest>>edg[i].wgt;
	}

	cout<<"\nEnter the Source of the Graph : ";
	cin>>source;

    //initially al the vertex at maximum 
	for(int i=0; i<V; i++)
	{
		dist[i] = 9999;
	}
	dist[source] = 0; //mark the source as 0.
	
	bellmen(V, E, dist, edg);
	
	return 0;
}