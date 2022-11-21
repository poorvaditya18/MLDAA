#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int t[20][20];

// int max(int a,int b)
// {
//     return a>b ?a:b;
// }

// Recursive knapsack ->
int Recursive_knapsack(int wt[],int profit[],int W,int n)
{
    //base condtion 
    if(W==0 or n==0)
    {
        // no elements or bag capacity is 0 then max profit is 0
        return 0;
    }

    //recursive condition

    // if wt[n-1]<W --> either include or exclude
    if(wt[n-1]<W)
    {
        return max(profit[n-1]+Recursive_knapsack(wt,profit,W-wt[n-1],n-1),Recursive_knapsack(wt,profit,W,n-1));
    }
    //if wt[n-1]>W --. then exclude
    else if (wt[n-1]>W)
    {
        return Recursive_knapsack(wt,profit,W,n-1);
    }

}

// memoization ->
int memo_knapsack(int wt[],int profit[],int W,int n)
{
    //base condtion 
    if(W==0 or n==0)
    {
        // no elements or bag capacity is 0 then max profit is 0
        return 0;
    }

    // if value is already present
    if(t[n][W]!=-1)
    {
        return t[n][W];
    }


    //recursive condition
    // if wt[n-1]<W --> either include or exclude
    if(wt[n-1]<W)
    {
        return t[n][W] = max(profit[n-1]+memo_knapsack(wt,profit,W-wt[n-1],n-1),memo_knapsack(wt,profit,W,n-1));
    }
    //if wt[n-1]>W --. then exclude
    else if (wt[n-1]>W)
    {
        return t[n][W]= memo_knapsack(wt,profit,W,n-1);
    }

}

// dp knapsack ->
int dp_knapsack(int wt[],int val[],int W,int n)
{

//base condition 2d array
// vector<vector<int>> t(n+1,vector<int>(W+1));


// iterate over the matrix -->
// replace n with i
// replace W with j
// replace recursive function with matrix t[][]
for(int i=0;i<n+1;i++)
{
    for(int j=0;j<W+1;j++)
    {
        //base condition ->
        if(i==0 or j==0)
        {
           t[i][j] = 0;
        }
        //check first condition 
        else if(wt[i-1]<=j)
        {
            t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
        }
        // check second 
        else{
            t[i][j] = t[i-1][j];
        }

    }
}
// for(int i=1;i<n+1;i++)
// {
//     for(int j=1;j<W+1;j++)
//     {
      
//     }
// }

return t[n][W];

}


int main()
{

    int n = 7;
    int W = 15;
    int profit[n]={10,5,15,7,6,18,3};
    int wt[n]={2,3,5,7,1,4,1};
    memset(t,-1,sizeof(t));
    cout << Recursive_knapsack(wt, profit, W, n);

}