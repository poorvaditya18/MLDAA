#include<iostream>
using namespace std;

int input(int mat[][4]){

	int m;
	cout<<"Enter Number of Edges you want to Enter:";
	cin>>m;
	
	for(int i=0;i<m;i++){
		int start;
		cout<<"Enter the starting Vertex:";
		cin>>start;
		int end;
		cout<<"Enter the ending Vertex:";
		cin>>end;
		
		int val;
		cout<<"Enter the value of the edge:";
		cin>>val;
		
		mat[start-1][end-1]=val;
		
	
		
	}
}
 int bellman_ford(int dis[],int mat[][4],int n){
	 	for(int a=0;a<n-1;a++){
	 		
	 		
	 		for(int i=0;i<n;i++){
	 			for(int j=0;j<n;j++){
	 				
	 				
	 				if(mat[i][j]!=0){
	 					if(dis[i]+mat[i][j]<dis[j]){
	 						dis[j]=dis[i]+mat[i][j];
						 
						 }
					 }
				 }
			 }
			 for(int b=0;b<n;b++){
			 	cout<<dis[b]<<" ";
			 }
			 cout<<endl;
	 }
	 
	 //Verification	
	 
	 int ver[n];
	 for(int x=0;x<n;x++){
	 	ver[x]=dis[x];
	 }
	 
	 for(int i=0;i<n;i++){
	 			for(int j=0;j<n;j++){
	 				
	 				
	 				if(mat[i][j]!=0){
	 					if(dis[i]+mat[i][j]<dis[j]){
	 						dis[j]=dis[i]+mat[i][j];
						 
						 }
					 }
				 }
			}
	for(int j=0;j<n;j++){
		if(ver[j]!=dis[j]){
			cout<<"The graph contains a Negative loop!!"<<endl;
		}
		else {
			cout<<"The graph is Verified now! It doesn't contain any negative loop :D"<<endl;
		}
	}
	 
	 
 }

int main(){




	int n,i=0;
	int s;
	int j=0;
	cout<<"Enter Number of Vertices:";
	cin>>n;
	int dis[n];
	cout<<"Enter Source Vertex:";
	cin>>s;
	for(int i=0;i<n;i++){
		dis[i]=INT_MAX;
	}
	dis[s-1]=0;
	
	
	
	int edgemat[4][4];
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			edgemat[x][y]=0;
		}
	} 
	input(edgemat);
	bellman_ford(dis,edgemat,n);
	
	cout<<"The distance of the Vertex are:"<<endl;
	
	for(int i=0;i<n;i++){
		cout<<dis[i]<<" ";
	}
	cout<<endl;
	
	cout<<"The Input Egde Matrix is:"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<"\t"<<edgemat[i][j];
		}
		cout<<endl;
	}
	


	
}
