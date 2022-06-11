#include <bits/stdc++.h>

using namespace std;

int calculateProfit(int length[], int price[],int n, int L)
{
    int dp[n+1][L+ 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            if (i==0 || j == 0)
            {
                dp[i][j] = 0;
            }
           
            else if (length[i-1]> j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],price[i-1]+ dp[i][j-length[i-1]]);
            }
            
            
        }
        
    }
    
    return dp[n][L];
    

}

int main()
{

    int n;
    cout<<"Enter the length of the raw rod ";
    cin>>n;
    int length[n];
    cout<<"Enter the length array: \n";
    for (int  i = 0; i < n; i++)
    {
        cin>>length[i];
    }

    int price[n];
    cout<<"Enter the corresponding prices: \n";
    for (int  i = 0; i < n; i++)
    {
        cin>>price[i];
    }
    int L;
    cout<<"Enter the length needed: ";
    cin>>L;

    cout<<"Max profit for given length will be : "<<calculateProfit(length,price,n,L);

 return 0;
}