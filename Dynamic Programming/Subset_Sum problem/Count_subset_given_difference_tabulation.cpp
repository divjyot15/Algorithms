#include <bits/stdc++.h>

using namespace std;

int CountSubset(int set[],int n, int diff){
    int sum =0;

    for (int i = 0; i < n; i++)
    {
        sum =sum + set[i];
    }


    int S1 = (sum + diff)/2;


    
    int dp[n+1][S1+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= S1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0 && j!= 0)
            {
                dp[i][j] = 0;
            }
            else if (set[i-1]> j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j- set[i-1]];
                
            }
            
            
        }
        
    }
    
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j= 0; j <=S1; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<endl<<dp[n][S1];
    
    return dp[n][S1];

}

int main()
{

    int n;
    cout << "Enter the elements in the set" << endl;
    cin >> n;
    cout << "Enter the set" << endl;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    int diff;
    cout<<"Enter the particular difference: ";
    cin>>diff;



    cout<<"\nNumber of subsets with given difference are: "<<CountSubset(set,n,diff);
    return 0;
} 