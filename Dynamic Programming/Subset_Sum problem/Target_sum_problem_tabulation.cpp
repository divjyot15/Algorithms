// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

//     For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

// Return the number of different expressions that you can build, which evaluates to target.

#include <bits/stdc++.h>

using namespace std;

int CountSubset(int set[],int n, int target){
    int sum =0;

    for (int i = 0; i < n; i++)
    {
        sum =sum + set[i];
    }


    int S1 = (sum + target)/2;


    
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
    int target_sum;
    cout<<"Enter the target sum: ";
    cin>>target_sum;

    cout<<"Number of ways to make sum equal to target is: "<<CountSubset(set,n,target_sum);


return 0;
}