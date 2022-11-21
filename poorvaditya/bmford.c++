#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanford(int V ,int src,vector<vector<int>> edges )
{
    
// create a vector initialise all as infinity.
vector<int> dist(V+1,INT_MAX); //distance vector
dist[src] = 0; // src dist will be 0

//relax all edges V-1 times
for(int i=0;i<V-1;i++)
{
    // relax each edge
    for(auto edge:edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        // relax condition -> 
        if(dist[u]!=INT_MAX && dist[u]+wt < dist[v])
        {
            dist[v] = dist[u]+wt;
            cout<<"\nRelaxed vertix: "<<v<<" .updated dist: "<<dist[v];
        }
    }
}

//check for Negative Wt cycle ->
// then it will be in infinite loop 
for(auto edge:edges)
{

        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

    if(dist[u]!=INT_MAX && dist[u]+wt < dist[v])
        {
            cout<<"\nNegative Wt Cycle Found !";
            exit(0);
        }

}

return dist;
}



int main()
{

int n,m,src;
cout<<"Enter the no of vertices : ";
cin>>n;
cout<<"\nEnter the no of edges : ";
cin>>m;

//Graph input : edge list 
vector<vector<int>> edges;

for(int i=0;i<m;i++)
{
    int u,v,wt;
    cout<<"Enter vertix u :";
    cin>>u;
    cout<<"\nEnter vertix v :";
    cin>>v;
    cout<<"\nEnter distance btw u and v :";
    cin>>wt;
    edges.push_back({u,v,wt});
}

cout<<"\nEnter the source vertix : ";
cin>>src;

//bellman ford
vector<int> distances = bellmanford(n,src,edges);

for(int i=1;i<=n;i++)
{
    cout<<"\nNode "<<i<<" is at dist "<<distances[i]<<endl;
}

return 0;
}