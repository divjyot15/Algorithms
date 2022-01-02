#include <bits/stdc++.h>

using namespace std;

int CountSubsets(int set[], int sum, int n)
{

    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0 && j != 0)
            {
                dp[i][j] = 0;
            }
            else if (set[i - 1] > j)
            {
                dp[i][j]= dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j]+dp[i-1][j-set[i-1]];
            }
        }
    }

    return dp[n][sum];
}

int main()
{

    int n;
    cout << "Enter the number of elements in the set" << endl;
    cin >> n;
    cout << "Enter the set" << endl;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    int sum;
    cout << "Enter the sum" << endl;
    cin >> sum;

    cout << "Number of subsets with given sum is :" << CountSubsets(set, sum, n);

    return 0;
}