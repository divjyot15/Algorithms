#include <bits/stdc++.h>

using namespace std;


int Knapsack(int wt[], int profit[], int W, int n,vector<vector<int>> mem)
{
    

   if (n==0 || W==0)
    {
        return 0;
    }
    else if (mem[W][n]!=-1)
    {
        return mem[W][n];
    }
    
    else if (wt[n-1]>W)
    {
        mem[W][n]= Knapsack(wt,profit,W,n-1,mem);
    }
    else
    {
        mem[W][n] =  max(Knapsack(wt,profit,W,n-1,mem),profit[n-1]+Knapsack(wt,profit,W-wt[n-1],n-1,mem));
    }
    
    return mem[W][n];
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

    vector<vector<int>> mem(W+1,vector<int> (n+1, -1));

    

    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }

    

    cout<<"Maximum Profit will be: "<<Knapsack(wt,profit,W,n,mem);

return 0;
}