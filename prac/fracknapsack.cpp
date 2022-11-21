#include<bits/stdc++.h>
using namespace std;

//input function 
void take_input(double arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

//1 .calculate p/w ratio
void ratiopw(double wt[],double profit[],double ratio[],int n)
{
    for(int i=0;i<n;i++)
    {
        ratio[i] = (profit[i]/wt[i]);
    }
}

// 2. sort the array on the basis of p/w ratio
void sortpw(double wt[],double profit[],double ratio[],int n)
{

    int counter = 1;
    while(counter<n)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(ratio[i]<ratio[i+1])
            {

                // swap ratio
                swap(ratio[i],ratio[i+1]);

                //swap wt
                swap(wt[i],wt[i+1]);

                //swap profit
                swap(profit[i],profit[i+1]);
            }

        }
        counter ++;
    }

}

// fractional knapsack
double knapsack(double wt[],double profit[],double ratio[],int xi[],int W,int n)
{

//knapsack using greedy
double finalprofit = 0;

for(int i=0;i<n;i++)
{
    if(wt[i]<W)
    {
        // choose the element
        xi[i]=1;
        //new bag wt
        W = W - wt[i]; 
        //profit
        finalprofit += profit[i];

    }
    else
    {
        // choose the fraction -> bagwt/wt
        xi[i] = W/wt[i];
        // new bag wt
        W = W -(W/wt[i]);

        // profit
        finalprofit += (W/wt[i])*profit[i];

    }

}

return finalprofit;

}

int main()
{

int n;
double W;
cout<<"Enter the no of elements: ";
cin>>n;

cout<<"\nEnter the Bag capacity: ";
cin>>W;

int xi[n];
double wt[n]; //weight array
double profit[n]; //profit associated with each item

cout<<"\nEnter the weight array\n";

take_input(wt,n);

cout<<"\nEnter the profit array\n";
take_input(profit,n);

double ratio[n]={0};

// calculate ratio
ratiopw(wt,profit,ratio,n);

// sort on the p/w
sortpw(wt,profit,ratio,n);

// calculate maximum profit
cout<<"\nMaximum Profit is : "<<knapsack(wt,profit,ratio,xi,W,n)<<endl;



}