#include <bits/stdc++.h>

using namespace std;

int Knapsack(int wt[], int profit[], int W, int n){
    if (n<0 || W==0)
    {
        return 0;
    }
    else if (wt[n]>W)
    {
        return Knapsack(wt,profit,W,n-1);
    }
    else
    {
        return max(Knapsack(wt,profit,W,n-1),profit[n]+Knapsack(wt,profit,W-wt[n],n-1));
    }
    
}

int main()
{
    int n;
    cout<<"Enter the number of elements: \n";
    cin>>n;
    int wt[n];
    int profit[n];

    cout<<"\nEnter the wt array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    }
    
    cout<<"\nEnter the profit array:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>profit[i];
    }
    int W;
    cout<<"\nEnter the capacity of bag:\n";
    cin>>W;

    cout<<"Maximum Profit will be: "<<Knapsack(wt,profit,W,n-1);
 

return 0;
}