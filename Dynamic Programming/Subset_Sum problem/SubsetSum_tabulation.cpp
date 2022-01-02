#include <bits/stdc++.h>

using namespace std;

bool subset(int set[], int sum, int n)
{

    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0 && j != 0)
            {
                dp[i][j] = false;
            }
            else if (set[i- 1] > j)
            {
                dp[i][j] =  dp[i-1][j];
            }
            else
            {
                dp[i][j] =  dp[i-1][j] || dp[i-1][j-set[i-1]];
            }
        }
    }

    return dp[n][sum];

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
    int sum;
    cout << "Enter the sum" << endl;
    cin >> sum;

    if (subset(set, sum, n) == true)
    {
        cout << "There is a subset with given sum" << endl;
    }
    else
    {
        cout << "No subset with given sum" << endl;
    }

    return 0;
}