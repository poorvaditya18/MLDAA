#include<iostream>
#include<stdio.h>
using namespace std;

struct Edge
{
	int src, dest, wgt;
};

void bellmen(int V, int E, int dist[], struct Edge edg[])
{
	int u, v, w, f=0;
	cout<<"\nIteration no";
	for(int x=0; x<V; x++)
	{
		cout<<"\t"<<x;
	}
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<E; j++)
		{
			u = edg[j].src;
			v = edg[j].dest;
			w = edg[j].wgt;
			if(dist[u]+w < dist[v])
			{
				dist[v] = dist[u]+w;
				f=1;
			}
			if(f==1)
			{
				cout<<"\nIteration "<<j;
				for(int x=0; x<V; x++)
				{
					cout<<"\t"<<dist[x];
				}
				f=0;
			}
		}
	}
	
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
	int dist[V];
	
	cout<<"\nEnter the number of vertices : ";
	cin>>V;
	cout<<"\nEnter the number of edges : ";
	cin>>E;
	struct Edge edg[E];
	for(int i=0; i<E; i++)
	{
		cout<<"\nEnter the source, destination and weight of edge "<<i+1<<" : ";
		cin>>edg[i].src>>edg[i].dest>>edg[i].wgt;
	}
	cout<<"\nEnter the Source of the Graph : ";
	cin>>source;
	for(int i=0; i<V; i++)
	{
		dist[i] = 9999;
	}
	dist[source] = 0;
	
	bellmen(V, E, dist, edg);
	
	return 0;
}
