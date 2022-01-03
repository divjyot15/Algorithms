// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.


#include <bits/stdc++.h>

using namespace std;

int CountCoins(int coins[],int n, int amount){

    int dp[n+1][amount+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j ==0)
            {
                dp[i][j]=0;
            }
            else if (i==0 && j!=0)
            {
                dp[i][j]= 1e5;
            }
            else if (coins[i-1]> j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j],1+ dp[i][j-coins[i-1]]);
            }
            
            
        }
        
    }
    
    if (dp[n][amount]>1e4)
    {
        return -1;
    }
    else
    {
        return dp[n][amount];
    }
    
    
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

    cout<<"Minimum Number of coins to form the given amount are: "<<CountCoins(coins,n,amount);

return 0;
}