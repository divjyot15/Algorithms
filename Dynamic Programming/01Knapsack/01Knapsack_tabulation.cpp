#include <bits/stdc++.h>

using namespace std;

int Knapsack(int wt[], int profit[], int W, int n)
{
    int dp[n+1][W+1];

    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            
            if (i==0 || j == 0)
            {
                dp[i][j]=0;
            }
            else if (wt[i-1]>W)
            {
                dp[i][j]= dp[i-1][j];
            }
            else
            {
                dp[i][j]= max(dp[i-1][j], profit[i-1]+ dp[i-1][j-wt[i-1]]) ;
            }

        }
        
    }
    
    return dp[n][W];
    
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

    cout<<"maximum profit will be: "<<Knapsack(wt,profit,W,n); 


return 0;
}