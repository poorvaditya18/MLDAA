#include<bits/stdc++.h>
using namespace std;


// Check whether you can place Queen or Not ->
bool canPlace(int board[][20],int n,int x,int y)
{

// check for the column 
for(int k=0;k<x;k++)
{
    if(board[k][y]==1)
    {
        return false;
    }
}

//left diagonal
int i=x;
int j=y;
while(i>=0 && j>=0)
{
    if(board[i][j]==1)
    {
        return false;
    }
    i--; 
    j--;
}

//right diagonal
i=x;
j=y;
while(i>=0 && j<n)
{
    if(board[i][j]==1)
    {
        return false;
    }
    i--;
    j++;
}

return true;

}

void printBoard(int board[][20],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}


// NQueen function ->
int  nQueen(int board[][20],int n , int i)
{


    // base condition 
    if(i==n)
    {
        printBoard(board,n);
        return 1;
    }

     
     int ways =0;

    // recursive condition 
    // check for every column
    for(int j=0;j<n;j++)
    {

        if(canPlace(board,n,i,j))
        {
            // mark i,j position as 1
            board[i][j] =1;

            //check for next row
            // bool success = nQueen(board,n,i+1);
            // if(success)
            // {
            //     return true;
            // }
            ways += nQueen(board,n,i+1);
            //backtrack and mark that position as 0
            board[i][j]=0;
        }

    }

return ways;
}



int main()
{

// enter no of queens
int board[20][20]={0}; 
int n;
cout<<"\nEnter number of Queens: ";
cin>>n;

nQueen(board,n,0);


    return 0;
}