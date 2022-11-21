#include<iostream>
#include<stdio.h>
using namespace std;

int matrix[20][20];

int check(int n, int row, int col)
{
	int i, j;

	for (i = 0; i < row; i++)
		if (matrix[i][col])
			return 0;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (matrix[i][j])
			return 0;

	for (i = row, j = col; i >= 0 && j < n; i--, j++)
		if (matrix[i][j])
			return 0;

	return 1;
}

int place_queen(int n, int row)
{
	if (row >= n)
		return 1;

	for (int col = 0; col < n; col++) {

		if (check(n, row, col)) {

			matrix[row][col] = 1;

			if (place_queen(n, row + 1))
				return 1;
				
			matrix[row][col] = 0; 
		}
	}
	return 0;
}

int main()
{
	int n;
	cout<<"\nEnter the value of 'N' : ";
	cin>>n;

	if (!place_queen(n, 0)) 
	{
		cout << "\n......Solution does not exist......";
	}
	else
	{
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++)
			{
				cout << " " << matrix[i][j] << " ";
			}
			printf("\n");
		}
	}
	return 0;
}


