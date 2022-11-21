#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n, wgt, curr_wgt, max_ind;	
	cout<<"\nEnter the total number of elements (n) : ";
	cin>>n;
	float temp, max, xipi = 0, xiwi = 0;
	float pi[n], wi[n], pw[n], xi[n];
	
	cout<<"\nEnter the total weight capacity of bag (W) : ";
	cin>>wgt;
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter the Profit and Weight of element "<<i+1<<" : ";
		cin>>pi[i]>>wi[i];
	}
	
	for(int i=0; i<n; i++)
	{
		pw[i] = pi[i]/wi[i];
	}
	
	cout<<"\nElement no. :";
	for(int i=0; i<n; i++)
	{
		cout<<"\t"<<i;
	}
	
	cout<<"\nPi\t    :";
	for(int i=0; i<n; i++)
	{
		cout<<"\t"<<pi[i];
	}
	cout<<"\nWi\t    :";
	for(int i=0; i<n; i++)
	{
		cout<<"\t"<<wi[i];
	}
	cout<<"\nP/W\t    :";
	for(int i=0; i<n; i++)
	{
		cout<<"\t"<<pw[i];
	}
	
	for(int i=0; i<n; i++)
	{
		xi[i] = 0;
	}
	curr_wgt = wgt;
	do
	{
		max=0;
		for(int i=0; i<n; i++)
		{
			if(pw[i] > max)
			{
				max = pw[i];
				max_ind = i;
			}	
		}
		pw[max_ind] = 0;
		
		if(curr_wgt >= wi[max_ind])
		{
			xi[max_ind] = 1;
		}
		else
		{
			xi[max_ind] = curr_wgt/wi[max_ind];
		}
		curr_wgt = curr_wgt - (wi[max_ind]*xi[max_ind]);
	}while(curr_wgt != 0);
	
	cout<<"\nXi\t    :";
	for(int i=0; i<n; i++)
	{
		cout<<"\t"<<xi[i];
	}
	
	for(int i=0; i<n; i++)
	{
		xiwi = xiwi + (xi[i]*wi[i]);
	}
	for(int i=0; i<n; i++)
	{
		xipi = xipi + (xi[i]*pi[i]);
	}
	cout<<"\n\nE xiwi (Total Weight) = "<<xiwi;
	cout<<"\nE xipi (Total Profit) = "<<xipi;
	cout<<"\nSolution :";
	for(int i=0; i<n; i++)
	{
		cout<<" "<<xi[i];
	}
}

