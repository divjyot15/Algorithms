// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

#include <bits/stdc++.h>

using namespace std;

int Count(int coins[],int n, int amount)
{
    int dp[n+1][amount+ 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0 && j!=0)
            {
                dp[i][j] = 0;
            }
            else if (coins[i-1]> j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }
            
            
        }
        
    }
    
    return dp[n][amount];
    
}

int main()
{

    int n;
    cout<<"Enter the number of denominations: ";
    cin>>n;
    int coins[n];
    cout<<"Enter the coins value: ";
    for (int  i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    int amount;
    cout<<"Enter the Amount needed: ";
    cin>>amount;

    cout<<"total Number of combinations to form the given amount are: "<<Count(coins,n,amount);

 return 0;
}