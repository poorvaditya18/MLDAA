#include<iostream>
#include<stdio.h>
using namespace std;

struct Element
{
	int wi;
	int pi; 
	int xi;
	int id;
};

void sort(struct Element ele[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(ele[j].wi > ele[j+1].wi)
			{
				swap(ele[j].wi, ele[j+1].wi);
				swap(ele[j].pi, ele[j+1].pi);
				swap(ele[j].id, ele[j+1].id);
			}
		}
	}
}

void unsort(struct Element ele[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(ele[j].id > ele[j+1].id)
			{
				swap(ele[j].id, ele[j+1].id);
				swap(ele[j].wi, ele[j+1].wi);
				swap(ele[j].pi, ele[j+1].pi);
				swap(ele[j].xi, ele[j+1].xi);
			}
		}
	}
}

void solution(struct Element ele[], int n)
{
	int xiwi, xipi;
	for(int i=0; i<n; i++)
	{
		xiwi = xiwi + (ele[i].xi*ele[i].wi);
	}
	for(int i=0; i<n; i++)
	{
		xipi = xipi + (ele[i].xi*ele[i].pi);
	}
	
	cout<<"\n\nE xiwi (Total Weight) = "<<xiwi;
	cout<<"\nE xipi (Total Profit) = "<<xipi;
	cout<<"\nSolution :";
	for(int i=0; i<n; i++)
	{
		cout<<" "<<ele[i].xi;
	}
}

void knapsack(struct Element ele[], int n, int wgt)
{
	int row = n+1;
	int col = wgt+1;
	int matrix[row][col];
	for(int i=0; i<col; i++)
	{
		matrix[0][i] = 0;
	}
	for(int i=0; i<row; i++)
	{
		matrix[i][0] = 0;
	}
	for(int i=1; i<row; i++)
	{
		for(int j=1; j<col; j++)
		{
			if(j<ele[i-1].wi)
			{
				matrix[i][j]=matrix[i-1][j];
			}
			else
			{
				matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j-ele[i-1].wi]+ele[i-1].pi);
			}
		}
	}
	cout<<"\nMatrix : \n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout<<"\t"<<matrix[i][j];
		}
		cout<<"\n";
	}
	
	int i=n;
	int j=wgt;
	while(i>0 && j>0)
	{
		if(matrix[i][j]!=matrix[i-1][j])
		{
			i--;
			ele[i].xi=1;
			j=j-ele[i].wi;
		}
		else
		{
			i--;
		}
	}

	unsort(ele, n);
}

int main()
{
	int n, wgt;	
	cout<<"\nEnter the total number of elements (n) : ";
	cin>>n;
	struct Element ele[n];
	cout<<"\nEnter the total weight capacity of bag (W) : ";
	cin>>wgt;
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter the Profit and Weight of element "<<i+1<<" : ";
		cin>>ele[i].pi>>ele[i].wi;
		ele[i].id = i+1;
		ele[i].xi = 0;
	}
	sort(ele, n);
	knapsack(ele, n, wgt);
	solution(ele, n);
	
	return 0;
}
